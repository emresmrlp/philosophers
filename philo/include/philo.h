/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:45:32 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/22 16:27:50 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# define MESSAGE_TAKE_FORK "has taken a fork"
# define MESSAGE_EAT "is eating"
# define MESSAGE_SLEEP "is sleeping"
# define MESSAGE_THINK "is thinking"
# define MESSAGE_DIED "died"

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int					id;
	int					right_fork_id;
	int					left_fork_id;
	pthread_t			thread;
	struct s_simulation	*simulation;
}	t_philo;

typedef struct s_simulation
{
	t_philo	*philos;
	t_mutex	*forks;
	t_mutex	access_mutex;
	t_mutex	print_mutex;
	int		philo_count;
	int		max_meals;
	int		*meals_counts;
	long	*last_meal_times;
	long	start_time;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		simulation_running;
}	t_simulation;

int		is_simulation_running(t_simulation *sim);
void	print_action(const char *message, t_philo *philo);
void	act_sleep(t_philo *philo);
void	act_think(t_philo *philo);
void	act_eat(t_philo *philo);
void	*philo_routine(void *arg);
void	simulation_manager(t_simulation *sim);
void	*ft_calloc(size_t count, size_t size);
void	free_simulation(t_simulation *sim);
void	cleanup(t_simulation *sim);
int		fatal_error(const char *message, t_simulation *sim);
int		init_simulation(int argc, char **argv, t_simulation **sim);
int		join_philos(t_simulation *sim);
int		parse_args(int argc, char **argv, t_simulation *sim);
int		ft_strlen(const char *s);
long	ft_atol(const char *str);
long	get_current_time_ms(void);
void	ft_usleep(long time_ms, t_simulation *sim);

#endif