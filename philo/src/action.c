/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 23:56:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/22 15:54:33 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_action(const char *message, t_philo *philo)
{
	long	current_time;

	if (!philo || !philo->simulation || !message || philo->id < 1
		|| philo->id > philo->simulation->philo_count)
		return ;
	pthread_mutex_lock(&philo->simulation->print_mutex);
	if (!is_simulation_running(philo->simulation))
	{
		pthread_mutex_unlock(&philo->simulation->print_mutex);
		return ;
	}
	current_time = get_current_time_ms() - philo->simulation->start_time;
	printf("%ld %d %s\n", current_time, philo->id, message);
	pthread_mutex_unlock(&philo->simulation->print_mutex);
}

void	act_sleep(t_philo *philo)
{
	if (!is_simulation_running(philo->simulation))
		return ;
	print_action(MESSAGE_SLEEP, philo);
	ft_usleep(philo->simulation->time_to_sleep, philo->simulation);
}

void	act_think(t_philo *philo)
{
	if (!is_simulation_running(philo->simulation))
		return ;
	print_action(MESSAGE_THINK, philo);
	if (philo->simulation->philo_count > 2)
	{
		if (philo->simulation->time_to_die > 600)
			ft_usleep(1, philo->simulation);
		else if (philo->simulation->time_to_die > 300)
			usleep(500);
		else
			usleep(100);
	}
}

static void	act_take_forks(t_philo *philo)
{
	if (philo->simulation->philo_count == 1)
	{
		pthread_mutex_lock(&philo->simulation->forks[philo->left_fork_id]);
		print_action(MESSAGE_TAKE_FORK, philo);
		ft_usleep(philo->simulation->time_to_die, philo->simulation);
		pthread_mutex_unlock(&philo->simulation->forks[philo->left_fork_id]);
		return ;
	}
	if (philo->left_fork_id < philo-> right_fork_id)
	{
		pthread_mutex_lock(&philo->simulation->forks[philo->left_fork_id]);
		pthread_mutex_lock(&philo->simulation->forks[philo->right_fork_id]);
	}
	else
	{
		pthread_mutex_lock(&philo->simulation->forks[philo->right_fork_id]);
		pthread_mutex_lock(&philo->simulation->forks[philo->left_fork_id]);
	}
	print_action(MESSAGE_TAKE_FORK, philo);
	print_action(MESSAGE_TAKE_FORK, philo);
}

void	act_eat(t_philo *philo)
{
	if (!is_simulation_running(philo->simulation))
		return ;
	act_take_forks(philo);
	if (philo->simulation->philo_count == 1)
		return ;
	pthread_mutex_lock(&philo->simulation->access_mutex);
	philo->simulation->last_meal_times[philo->id - 1] = get_current_time_ms()
		- philo->simulation->start_time;
	philo->simulation->meals_counts[philo->id - 1]++;
	pthread_mutex_unlock(&philo->simulation->access_mutex);
	print_action(MESSAGE_EAT, philo);
	ft_usleep(philo->simulation->time_to_eat, philo->simulation);
	pthread_mutex_unlock(&philo->simulation->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&philo->simulation->forks[philo->right_fork_id]);
}
