/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:17:20 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/17 18:31:28 by ysumeral         ###   ########.fr       */
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
		pthread_mutex_lock(&philo->simulation->access_mutex);
		if (!philo->simulation->simulation_running)
		{
			pthread_mutex_unlock(&philo->simulation->access_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->simulation->access_mutex);
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
	long	last_meal_time;

	i = 0;
	while (i < sim->philo_count)
	{
		current_time = get_current_time_ms() - sim->start_time;
		pthread_mutex_lock(&sim->access_mutex);
		last_meal_time = sim->last_meal_times[i];
		pthread_mutex_unlock(&sim->access_mutex);
		if (current_time - last_meal_time > sim->time_to_die)
		{
			print_action(MESSAGE_DIED, &sim->philos[i]);
			pthread_mutex_lock(&sim->access_mutex);
			sim->simulation_running = 0;
			pthread_mutex_unlock(&sim->access_mutex);
			join_philos(sim);
			cleanup(sim);
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
		pthread_mutex_lock(&sim->access_mutex);
		if (sim->meals_counts[i] >= sim->max_meals)
			ate_enough++;
		pthread_mutex_unlock(&sim->access_mutex);
		i++;
	}
	if (ate_enough == sim->philo_count)
	{
		pthread_mutex_lock(&sim->access_mutex);
		sim->simulation_running = 0;
		pthread_mutex_unlock(&sim->access_mutex);
		join_philos(sim);
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
