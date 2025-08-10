/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:10:53 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/10 10:38:38 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	forks_init(t_program *program)
{
	int	i;

	i = 0;
	program->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* program->philo_count);
	if (!program->forks)
		exit_with_error(program, "Error: Memory allocation failed");
	while (i < program->philo_count)
	{
		pthread_mutex_init(&program->forks[i], NULL);
		i++;
	}
}

static void	init_shared_data(t_program *program)
{
	int	i;

	program->last_meal_times = malloc(sizeof(long) * program->philo_count);
	program->meals_counts = malloc(sizeof(int) * program->philo_count);
	if (!program->last_meal_times || !program->meals_counts)
		exit_with_error(program, "Memory allocation failed");
	i = 0;
	while (i < program->philo_count)
	{
		program->last_meal_times[i] = get_current_time_ms();
		program->meals_counts[i] = 0;
		i++;
	}
}

void	init_data(t_program *program, char **argv)
{
	program->simulation_running = 1;
	program->all_ate = 0;
	program->start_time = get_current_time_ms();
	program->philo_count = ft_atol(argv[1]);
	program->time_to_die = ft_atol(argv[2]);
	program->time_to_eat = ft_atol(argv[3]);
	program->time_to_sleep = ft_atol(argv[4]);
	program->meals_required = -1;
	if (argv[5])
		program->meals_required = ft_atol(argv[5]);
	init_shared_data(program);
	pthread_mutex_init(&program->print_mutex, NULL);
	pthread_mutex_init(&program->death_check_mutex, NULL);
	pthread_mutex_init(&program->meal_check_mutex, NULL);
	forks_init(program);
}
