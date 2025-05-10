/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:10:53 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/10 14:11:51 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	forks_init(t_program *program)
{
	int	i;

	i = 0;
	program->forks = (t_fork **)malloc(sizeof(t_fork *)
			* program->philo_count);
	if (!program->forks)
		program_exit_error(program, "Error: Memory allocation failed");
	while (i < program->philo_count)
	{
		program->forks[i] = (t_fork *)malloc(sizeof(t_fork));
		if (!program->forks[i])
			program_exit_error(program, "Error: Memory allocation failed");
		program->forks[i]->fork = (pthread_mutex_t *)
			malloc(sizeof(pthread_mutex_t));
		if (!program->forks[i]->fork)
			program_exit_error(program, "Error: Memory allocation failed");
		program->forks[i]->id = i;
		pthread_mutex_init(program->forks[i]->fork, NULL);
		i++;
	}
}

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
		program->philos[i]->last_eat_time = program->dinner_start;
		if (i == 0)
			program->philos[i]->left_fork = program->forks[program->philo_count
				- 1];
		else
			program->philos[i]->left_fork = program->forks[i - 1];
		program->philos[i]->right_fork = program->forks[i];
		i++;
	}
}

void	program_init(t_program *program, char **argv)
{
	program->state = 1;
	program->dinner_start = get_current_time_ms();
	program->dinner_duration = 0;
	program->philo_count = ft_atol(argv[1]);
	program->death_time = ft_atol(argv[2]);
	program->eat_time = ft_atol(argv[3]);
	program->sleep_time = ft_atol(argv[4]);
	program->must_eat = -1;
	if (argv[5])
		program->must_eat = ft_atol(argv[5]);
	forks_init(program);
	philos_init(program);
}
