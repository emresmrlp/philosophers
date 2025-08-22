/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:16:19 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/22 16:27:27 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_philos(t_simulation *sim)
{
	int	i;

	sim->philos = (t_philo *)ft_calloc(sim->philo_count, sizeof(t_philo));
	if (!sim->philos)
		return (fatal_error("Memory allocation for philosophers failed", sim));
	i = 0;
	while (i < sim->philo_count)
	{
		sim->philos[i].id = i + 1;
		sim->philos[i].left_fork_id = i;
		if (sim->philo_count == 1)
			sim->philos[i].right_fork_id = -1;
		else
			sim->philos[i].right_fork_id = (i + 1) % sim->philo_count;
		sim->philos[i].simulation = sim;
		pthread_create(&sim->philos[i].thread, NULL, philo_routine,
			&sim->philos[i]);
		i++;
	}
	return (0);
}

static int	init_forks(t_simulation *sim)
{
	int	i;

	sim->forks = (t_mutex *)ft_calloc(sim->philo_count, sizeof(t_mutex));
	if (!sim->forks)
		return (fatal_error("Memory allocation for forks failed", sim));
	i = 0;
	while (i < sim->philo_count)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
			return (fatal_error("Mutex initialization failed", sim));
		i++;
	}
	return (0);
}

static int	init_data(t_simulation *sim)
{
	int	i;

	sim->start_time = get_current_time_ms();
	sim->simulation_running = 1;
	sim->meals_counts = (int *)ft_calloc(sim->philo_count, sizeof(int));
	if (!sim->meals_counts)
		return (fatal_error("Memory allocation for meals counts failed", sim));
	sim->last_meal_times = (long *)ft_calloc(sim->philo_count, sizeof(long));
	if (!sim->last_meal_times)
		return (fatal_error("Memory allocation for last meal times failed",
				sim));
	i = 0;
	while (i < sim->philo_count)
	{
		sim->meals_counts[i] = 0;
		sim->last_meal_times[i] = 0;
		i++;
	}
	pthread_mutex_init(&sim->print_mutex, NULL);
	pthread_mutex_init(&sim->access_mutex, NULL);
	return (0);
}

int	join_philos(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_count)
	{
		if (pthread_join(sim->philos[i].thread, NULL) != 0)
			return (fatal_error("Thread join failed", sim));
		i++;
	}
	return (0);
}

int	init_simulation(int argc, char **argv, t_simulation **sim)
{
	*sim = (t_simulation *)ft_calloc(1, sizeof(t_simulation));
	if (!*sim)
		return (fatal_error("Memory allocation for simulation failed", *sim));
	if (parse_args(argc, argv, *sim))
		return (1);
	if (init_data(*sim))
		return (1);
	if (init_forks(*sim))
		return (1);
	if (init_philos(*sim))
		return (1);
	return (0);
}
