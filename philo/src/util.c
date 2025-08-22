/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:50:22 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/22 16:23:53 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_current_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(long time_ms, t_simulation *sim)
{
	long	start_time;

	start_time = get_current_time_ms();
	while ((get_current_time_ms() - start_time) < time_ms)
	{
		if (sim && !is_simulation_running(sim))
			break ;
		usleep(100);
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * sign);
}
