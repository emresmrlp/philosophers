/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:16:54 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 18:43:10 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	long	philo_num;
	long	death_time;
	long	eat_time;
	long	sleep_time;
	long	must_eat;
}	t_philo;

long	ft_atol(char *str);
int		validate_args(int argc, char **argv);
void	program_init(t_philo *philo, char **argv);
void	program_exit(t_philo *philo);
void	program_exit_error(t_philo *philo, char *error_message);

#endif