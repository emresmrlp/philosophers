/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:15:01 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/22 16:27:10 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, count * size);
	return (ptr);
}

static void	free_forks(t_simulation *sim)
{
	if (sim->forks)
	{
		free(sim->forks);
		sim->forks = NULL;
	}
}

static void	free_philos(t_simulation *sim)
{
	if (sim->philos)
	{
		free(sim->philos);
		sim->philos = NULL;
	}
}

static void	free_data(t_simulation *sim)
{
	if (sim->meals_counts)
	{
		free(sim->meals_counts);
		sim->meals_counts = NULL;
	}
	if (sim->last_meal_times)
	{
		free(sim->last_meal_times);
		sim->last_meal_times = NULL;
	}
}

void	free_simulation(t_simulation *sim)
{
	free_data(sim);
	free_forks(sim);
	free_philos(sim);
	if (sim)
	{
		free(sim);
		sim = NULL;
	}
}
