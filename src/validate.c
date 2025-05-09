/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:38:04 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 18:42:51 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int validate_args(int argc, char **argv)
{
	if (argc == 5 || (argc == 6 && ft_atol(argv[5]) > 0))
	{
		if (ft_atol(argv[1]) > 0 && ft_atol(argv[2]) > 0
			&& ft_atol(argv[3]) > 0 && ft_atol(argv[4]) > 0)
		{
			return (1);
		}
	}
	return (0);
}