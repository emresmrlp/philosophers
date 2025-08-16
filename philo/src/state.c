/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:00:57 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/16 20:36:09 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	destroy_forks(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_count)
	{
		if (pthread_mutex_destroy(&sim->forks[i]) != 0)
			fatal_error("Mutex destruction failed", sim);
		i++;
	}
}

static void	destroy_mutexes(t_simulation *sim)
{
	destroy_forks(sim);
}

void	cleanup(t_simulation *sim)
{
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
