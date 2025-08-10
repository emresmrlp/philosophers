/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:16:54 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/10 12:57:11 by ysumeral         ###   ########.fr       */
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

typedef struct s_program
{
	pthread_mutex_t	*forks;
	int				philo_count;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_required;	
	long			start_time;
	int				simulation_running;
	int				all_ate;
	long			*last_meal_times;
	int				*meals_counts;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_check_mutex;
	pthread_mutex_t	meal_check_mutex;
}	t_program;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			last_meal_time;
	int				meals_count;
	int				left_fork_id;
	int				right_fork_id;
	t_program		*program;
}	t_philo;

long	ft_atol(char *str);
int		validate_args(int argc, char **argv);
void	start_simulation(t_program *program);
void	dinner_start(t_program *program);
long	get_current_time_ms(void);
void	init_data(t_program *program, char **argv);
void	cleanup_data(t_program *program);
void	exit_with_error(t_program *program, char *error_message);
void	*philosopher_routine(void *arg);
void	do_action(t_philo *philo, int action);
void	print_status(t_philo *philo, char *message);
int		check_death(t_program *program);
int		check_all_ate(t_program *program);
void	ft_usleep(long time_ms);
int		is_simulation_running(t_program *program);

#endif