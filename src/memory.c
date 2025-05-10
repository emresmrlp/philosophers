/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:04:10 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/10 14:12:16 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	free_forks(t_program *program)
{
	int	i;

	i = 0;
	if (program->forks)
	{
		while (i < program->philo_count)
		{
			if (program->forks[i])
			{
				if (program->forks[i]->fork)
				{
					pthread_mutex_destroy(program->forks[i]->fork);
					free(program->forks[i]->fork);
				}
				free(program->forks[i]);
			}
			i++;
		}
		free(program->forks);
		program->forks = NULL;
	}
}

static void	free_philos(t_program *program)
{
	int	i;

	i = 0;
	if (program->philos)
	{
		while (i < program->philo_count)
		{
			if (program->philos[i])
				free(program->philos[i]);
			i++;
		}
		free(program->philos);
		program->philos = NULL;
	}
}

static void	free_all(t_program *program)
{
	if (program)
	{
		free_philos(program);
		free_forks(program);
		free(program);
		program = NULL;
	}
}

void	program_exit(t_program *program)
{
	free_all(program);
	exit(EXIT_SUCCESS);
}

void	program_exit_error(t_program *program, char *error_message)
{
	if (program)
		free_all(program);
	if (error_message)
		printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
