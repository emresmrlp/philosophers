/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:16:54 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 22:11:34 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	long			last_eat_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_program
{
	t_philo	**philos;
	int		state;
	long	philo_count;
	long	death_time;
	long	eat_time;
	long	sleep_time;
	long	must_eat;
}	t_program;

long	ft_atol(char *str);
int		validate_args(int argc, char **argv);
void	dinner_start(t_program *philo);
void	program_init(t_program *philo, char **argv);
void	program_exit(t_program *philo);
void	program_exit_error(t_program *philo, char *error_message);

#endif