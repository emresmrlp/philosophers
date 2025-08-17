/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:17:20 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/17 03:14:48 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->simulation->time_to_eat / 10);
	if (philo->simulation->philo_count == 1)
	{
		act_eat(philo);
		return (NULL);
	}
	while (1)
	{
		act_eat(philo);
		act_sleep(philo);
		act_think(philo);
	}
	return (NULL);
}

void	check_death(t_simulation *sim)
{
	int		i;
	long	current_time;

	current_time = get_current_time_ms();
	i = 0;
	while (i < sim->philo_count)
	{
		if (current_time - sim->last_meal_times[i] > sim->time_to_die)
		{
			pthread_mutex_lock(&sim->print_mutex);
			printf("%ld %d %s\n", current_time - sim->start_time,
				i + 1, MESSAGE_DIED);
			pthread_mutex_unlock(&sim->print_mutex);
			exit(0);
		}
		i++;
	}
}

void	check_all_ate(t_simulation *sim)
{
	int	i;
	int	ate_enough;

	if (sim->max_meals <= 0)
		return ;
	i = 0;
	ate_enough = 0;
	while (i < sim->philo_count)
	{
		pthread_mutex_lock(&sim->meal_mutex);
		if (sim->meals_counts[i] >= sim->max_meals)
			ate_enough++;
		pthread_mutex_unlock(&sim->meal_mutex);
		i++;
	}
	if (ate_enough == sim->philo_count)
	{
		cleanup(sim);
		exit(0);
	}
}

void	simulation_manager(t_simulation *sim)
{
	while (1)
	{
		check_death(sim);
		check_all_ate(sim);
		usleep(1000);
	}
}
