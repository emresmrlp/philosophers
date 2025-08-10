/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:30:00 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/10 13:25:17 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <limits.h>

static int	is_digits(const char *s)
{
	int i;

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

static int	parse_positive_long(const char *s, long *out)
{
	unsigned long	acc;
	int				i;

	if (!is_digits(s))
		return (0);
	acc = 0;
	i = 0;
	while (s[i])
	{
		acc = acc * 10 + (s[i] - '0');
		if (acc > LONG_MAX)
			return (0);
		i++;
	}
	if (acc == 0)
		return (0);
	*out = (long)acc;
	return (1);
}

static int	parse_int_limited(const char *s, int *out)
{
	long	val;

	if (!parse_positive_long(s, &val))
		return (0);
	if (val > INT_MAX)
		return (0);
	*out = (int)val;
	return (1);
}

int	validate_args(int argc, char **argv)
{
	long	die;
	long	eat;
	long	sleep_time;
	int		philos;
	long	must_eat;

	if (!(argc == 5 || argc == 6))
		return (0);
	if (!parse_int_limited(argv[1], &philos))
		return (0);
	if (!parse_positive_long(argv[2], &die))
		return (0);
	if (!parse_positive_long(argv[3], &eat))
		return (0);
	if (!parse_positive_long(argv[4], &sleep_time))
		return (0);
	if (argc == 6)
	{
		if (!parse_positive_long(argv[5], &must_eat))
			return (0);
	}
	return (1);
}
