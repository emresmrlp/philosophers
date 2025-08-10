/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 00:00:00 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/10 13:38:35 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_status(t_philo *philo, char *message)
{
	long	current_time;

	pthread_mutex_lock(&philo->program->print_mutex);
	if (is_simulation_running(philo->program))
	{
		current_time = get_current_time_ms() - philo->program->start_time;
		printf("%ld %d %s\n", current_time, philo->id, message);
	}
	pthread_mutex_unlock(&philo->program->print_mutex);
}

int	is_simulation_running(t_program *program)
{
	int	running;

	pthread_mutex_lock(&program->death_check_mutex);
	running = program->simulation_running;
	pthread_mutex_unlock(&program->death_check_mutex);
	return (running);
}

static void	take_forks(t_philo *philo)
{
	if (philo->program->philo_count == 1)
	{
		pthread_mutex_lock(&philo->program->forks[philo->right_fork_id]);
		print_status(philo, MESSAGE_TAKE_FORK);
		ft_usleep(philo->program->time_to_die);
		pthread_mutex_unlock(&philo->program->forks[philo->right_fork_id]);
		return ;
	}
	if (philo->left_fork_id < philo->right_fork_id)
	{
		pthread_mutex_lock(&philo->program->forks[philo->left_fork_id]);
		pthread_mutex_lock(&philo->program->forks[philo->right_fork_id]);
	}
	else
	{
		pthread_mutex_lock(&philo->program->forks[philo->right_fork_id]);
		pthread_mutex_lock(&philo->program->forks[philo->left_fork_id]);
	}
	print_status(philo, MESSAGE_TAKE_FORK);
	print_status(philo, MESSAGE_TAKE_FORK);
}

static void	eat_routine(t_philo *philo)
{
	take_forks(philo);
	if (philo->program->philo_count == 1)
		return ;
	print_status(philo, MESSAGE_EAT);
	pthread_mutex_lock(&philo->program->meal_check_mutex);
	philo->last_meal_time = get_current_time_ms();
	philo->meals_count++;
	philo->program->last_meal_times[philo->id - 1] = philo->last_meal_time;
	philo->program->meals_counts[philo->id - 1] = philo->meals_count;
	pthread_mutex_unlock(&philo->program->meal_check_mutex);
	ft_usleep(philo->program->time_to_eat);
	pthread_mutex_unlock(&philo->program->forks[philo->right_fork_id]);
	pthread_mutex_unlock(&philo->program->forks[philo->left_fork_id]);
	ft_usleep(1);
}

void	do_action(t_philo *philo, int action)
{
	if (action == 1)
		eat_routine(philo);
	else if (action == 2)
	{
		print_status(philo, MESSAGE_SLEEP);
		ft_usleep(philo->program->time_to_sleep);
	}
	else if (action == 3)
		print_status(philo, MESSAGE_THINK);
	else if (action == 0)
		print_status(philo, MESSAGE_TAKE_FORK);
}
