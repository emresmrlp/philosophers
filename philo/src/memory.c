/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:04:10 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/10 10:38:37 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	free_forks(t_program *program)
{
	int	i;

	if (program->forks)
	{
		i = 0;
		while (i < program->philo_count)
		{
			pthread_mutex_destroy(&program->forks[i]);
			i++;
		}
		free(program->forks);
		program->forks = NULL;
	}
}

static void	free_all(t_program *program)
{
	if (program)
	{
		free_forks(program);
		if (program->last_meal_times)
		{
			free(program->last_meal_times);
			program->last_meal_times = NULL;
		}
		if (program->meals_counts)
		{
			free(program->meals_counts);
			program->meals_counts = NULL;
		}
		pthread_mutex_destroy(&program->print_mutex);
		pthread_mutex_destroy(&program->death_check_mutex);
		pthread_mutex_destroy(&program->meal_check_mutex);
		free(program);
		program = NULL;
	}
}

void	cleanup_data(t_program *program)
{
	free_all(program);
	exit(EXIT_SUCCESS);
}

void	exit_with_error(t_program *program, char *error_message)
{
	if (program)
		free_all(program);
	if (error_message)
		printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
