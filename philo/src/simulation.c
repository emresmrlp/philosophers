/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:17:20 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/16 22:05:25 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	//stagger gerekli unutma!! (dead lock)
	while (is_simulation_running(philo->simulation))
	{
		//eat
		if (!is_simulation_running(philo->simulation))
			break;
		//sleep
		if (!is_simulation_running(philo->simulation))
			break;
		//think
	}
	return (NULL);
}

int is_simulation_running(t_simulation *sim)
{
	int	running;

	pthread_mutex_lock(&sim->check_death_mutex);
	running = sim->simulation_running;
	pthread_mutex_unlock(&sim->check_death_mutex);
	return (running);
}

void	simulation_manager(t_simulation *sim)
{
	while (is_simulation_running(sim))
	{
		//monitor kontrol
		ft_usleep(100);
	}
}
