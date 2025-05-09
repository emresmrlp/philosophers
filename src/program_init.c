/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:22:20 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 19:18:19 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	program_init(t_philo *philo, char **argv)
{
	philo->philo_num = ft_atol(argv[1]);
	philo->death_time = ft_atol(argv[2]);
	philo->eat_time = ft_atol(argv[3]);
	philo->sleep_time = ft_atol(argv[4]);
	if (argv[5])
		philo->must_eat = ft_atol(argv[5]);
	else
		philo->must_eat = -1;
}
