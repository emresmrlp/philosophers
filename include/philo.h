/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:16:54 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/10 13:54:10 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# define MESSAGE_TAKE_FORK "has taken a fork"
# define MESSAGE_EAT "is eating"
# define MESSAGE_SLEEP "is sleeping"
# define MESSAGE_THINK "is thinking"
# define MESSAGE_DIED "died"

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	*fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			last_eat_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
}	t_philo;

typedef struct s_program
{
	t_philo	**philos;
	t_fork	**forks;
	int		state;
	long	dinner_start;
	long	dinner_duration;
	long	philo_count;
	long	death_time;
	long	eat_time;
	long	sleep_time;
	long	must_eat;
}	t_program;

long	ft_atol(char *str);
int		validate_args(int argc, char **argv);
void	dinner_start(t_program *philo);
long	get_current_time_ms(void);
void	program_init(t_program *philo, char **argv);
void	program_exit(t_program *philo);
void	program_exit_error(t_program *philo, char *error_message);

#endif