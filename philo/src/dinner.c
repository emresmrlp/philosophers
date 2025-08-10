/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:16:52 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/10 13:33:37 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	initial_stagger(t_philo *philo)
{
	long	offset;

	offset = 0;
	if (philo->program->philo_count > 1)
	{
		if (philo->id % 2 == 0)
			offset = philo->program->time_to_eat / 2;
		else if (philo->program->philo_count % 2 == 1
			&& philo->id == philo->program->philo_count)
			offset = philo->program->time_to_eat / 3;
	}
	if (offset > 0)
		ft_usleep(offset);
	pthread_mutex_lock(&philo->program->meal_check_mutex);
	philo->last_meal_time = get_current_time_ms();
	philo->program->last_meal_times[philo->id - 1] = philo->last_meal_time;
	pthread_mutex_unlock(&philo->program->meal_check_mutex);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	initial_stagger(philo);
	while (is_simulation_running(philo->program))
	{
		do_action(philo, 1);
		if (!is_simulation_running(philo->program))
			break ;
		do_action(philo, 2);
		if (!is_simulation_running(philo->program))
			break ;
		do_action(philo, 3);
	}
	return (NULL);
}

int	check_death(t_program *program)
{
	int		i;
	long	current_time;
	t_philo	temp_philo;

	i = 0;
	while (i < program->philo_count)
	{
		pthread_mutex_lock(&program->meal_check_mutex);
		current_time = get_current_time_ms();
		if ((current_time - program->last_meal_times[i])
			>= program->time_to_die)
		{
			pthread_mutex_unlock(&program->meal_check_mutex);
			temp_philo.id = i + 1;
			temp_philo.program = program;
			print_status(&temp_philo, MESSAGE_DIED);
			pthread_mutex_lock(&program->death_check_mutex);
			program->simulation_running = 0;
			pthread_mutex_unlock(&program->death_check_mutex);
			return (1);
		}
		pthread_mutex_unlock(&program->meal_check_mutex);
		i++;
	}
	return (0);
}

int	check_all_ate(t_program *program)
{
	int		i;
	int		ate_enough;

	if (program->meals_required == -1)
		return (0);
	i = 0;
	ate_enough = 0;
	while (i < program->philo_count)
	{
		pthread_mutex_lock(&program->meal_check_mutex);
		if (program->meals_counts[i] >= program->meals_required)
			ate_enough++;
		pthread_mutex_unlock(&program->meal_check_mutex);
		i++;
	}
	if (ate_enough == program->philo_count)
	{
		pthread_mutex_lock(&program->death_check_mutex);
		program->simulation_running = 0;
		pthread_mutex_unlock(&program->death_check_mutex);
		return (1);
	}
	return (0);
}
