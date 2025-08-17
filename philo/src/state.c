/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:00:57 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/17 18:31:32 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	destroy_forks(t_simulation *sim)
{
	int	i;

	if (sim->forks == NULL)
		return ;
	i = 0;
	while (i < sim->philo_count)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
}

static void	destroy_mutexes(t_simulation *sim)
{
	if (sim->start_time)
	{
		pthread_mutex_destroy(&sim->access_mutex);
		pthread_mutex_destroy(&sim->print_mutex);
	}
	destroy_forks(sim);
}

void	cleanup(t_simulation *sim)
{
	if (sim == NULL)
		return ;
	destroy_mutexes(sim);
	free_simulation(sim);
}

void	fatal_error(const char *message, t_simulation *sim)
{
	write(2, "Error: ", 7);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	cleanup(sim);
	exit(1);
}
