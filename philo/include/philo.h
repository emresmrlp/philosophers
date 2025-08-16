/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:45:32 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/16 22:07:59 by ysumeral         ###   ########.fr       */
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
	pthread_t			thread;
	struct s_simulation	*simulation;
}	t_philo;

typedef struct s_simulation
{
	t_philo	*philos;
	t_mutex	*forks;
	t_mutex	check_death_mutex;
	t_mutex	check_meal_mutex;
	t_mutex	print_mutex;
	int		simulation_running;
	int		philo_count;
	int		max_meals;
	int		*meals_counts;
	long	*last_meal_times;
	long	start_time;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
}	t_simulation;

void	*philo_routine(void *arg);
void	simulation_manager(t_simulation *sim);
void	*ft_calloc(size_t count, size_t size);
void	free_simulation(t_simulation *sim);
void	cleanup(t_simulation *sim);
void	fatal_error(const char *message, t_simulation *sim);
int		is_simulation_running(t_simulation *sim);
void	init_simulation(int argc, char **argv, t_simulation **sim);
void	parse_args(int argc, char **argv, t_simulation *sim);
int		ft_strlen(const char *s);
long	ft_atol(const char *str);
long	get_current_time_ms(void);
void	ft_usleep(long time_ms);

#endif