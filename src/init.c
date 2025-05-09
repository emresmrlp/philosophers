/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:22:20 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 22:10:29 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	philos_init(t_program *program)
{
	int	i;

	i = 0;
	program->philos = (t_philo **)malloc(sizeof(t_philo *)
			* program->philo_count);
	if (!program->philos)
		program_exit_error(program, "Error: Memory allocation failed");
	while (i < program->philo_count)
	{
		program->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!program->philos[i])
			program_exit_error(program, "Error: Memory allocation failed");
		program->philos[i]->id = i;
		program->philos[i]->last_eat_time = 0;
		program->philos[i]->left_fork = NULL;
		program->philos[i]->right_fork = NULL;
		i++;
	}
}

void	program_init(t_program *program, char **argv)
{
	int	i;

	i = 0;
	program->state = 1;
	program->philo_count = ft_atol(argv[1]);
	program->death_time = ft_atol(argv[2]);
	program->eat_time = ft_atol(argv[3]);
	program->sleep_time = ft_atol(argv[4]);
	program->must_eat = -1;
	if (argv[5])
		program->must_eat = ft_atol(argv[5]);
	philos_init(program);
}
