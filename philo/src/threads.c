/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:40:00 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/10 13:06:56 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	init_philos(t_philo *philos, t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].program = program;
		philos[i].left_fork_id = i;
		philos[i].right_fork_id = (i + 1) % program->philo_count;
		philos[i].last_meal_time = program->last_meal_times[i];
		philos[i].meals_count = program->meals_counts[i];
		i++;
	}
}

static void	start_threads(t_philo *philos, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]);
		i++;
	}
}

void	dinner_start(t_program *program)
{
	t_philo		*philos;
	int			i;

	philos = malloc(sizeof(t_philo) * program->philo_count);
	if (!philos)
		return ;
	init_philos(philos, program);
	start_threads(philos, program->philo_count);
	while (is_simulation_running(program))
	{
		if (check_death(program) || check_all_ate(program))
			break ;
		usleep(100);
	}
	i = 0;
	while (i < program->philo_count)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	free(philos);
}

void	start_simulation(t_program *program)
{
	dinner_start(program);
}
