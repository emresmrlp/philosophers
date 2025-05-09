/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:04:10 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 22:12:49 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	free_all(t_program *program)
{
	int	i;

	i = 0;
	if (program)
	{
		if (program->philos)
		{
			while (i < program->philo_count)
			{
				if (program->philos[i])
				{
					if (program->philos[i]->right_fork)
						pthread_mutex_destroy(program->philos[i]->right_fork);
					free(program->philos[i]);
				}
				i++;
			}
			free(program->philos);
			program->philos = NULL;
		}
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
