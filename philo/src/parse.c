/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:23:03 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/16 20:58:47 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_digits(const char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	validate_arg_int(const char *arg)
{
	long	value;

	if (!is_digits(arg))
		return (0);
	value = ft_atol(arg);
	if (value > INT_MAX)
		return (0);
	return (1);
}

static int	validate_arg_long(const char *arg)
{
	long	value;

	if (!is_digits(arg))
		return (0);
	value = ft_atol(arg);
	if (value > LONG_MAX)
		return (0);
	return (1);
}

void	parse_args(int argc, char **argv, t_simulation *sim)
{
	if (!(argc == 5 || argc == 6))
		fatal_error("Invalid number of arguments", sim);
	if (!validate_arg_int(argv[1]) || ft_atol(argv[1]) <= 0)
		fatal_error("Invalid philosopher count", sim);
	if (!validate_arg_long(argv[2]))
		fatal_error("Invalid time to die", sim);
	if (!validate_arg_long(argv[3]))
		fatal_error("Invalid time to eat", sim);
	if (!validate_arg_long(argv[4]))
		fatal_error("Invalid time to sleep", sim);
	if (argc == 6 && !validate_arg_int(argv[5]))
		fatal_error("Invalid number of meals", sim);
	sim->philo_count = (int)ft_atol(argv[1]);
	sim->time_to_die = ft_atol(argv[2]);
	sim->time_to_eat = ft_atol(argv[3]);
	sim->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		sim->max_meals = (int)ft_atol(argv[5]);
	else
		sim->max_meals = -1;
}
