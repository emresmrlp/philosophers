/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:20:14 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 19:31:23 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		program_exit_error(NULL, "Error: Memory allocation failed");
	if (validate_args(argc, argv))
	{
		program_init(philo, argv);
		program_exit(philo);
	}
	else
	{
		program_exit_error(philo, "Correct usage: ./philo"\
			" (number of philo [>= 1]) (time to die [>= 1])" \
			" (time to eat [>= 1]) (time to sleep [>= 1])" \
			" (must_eat -optional- [>= 1])");
	}
	return (0);
}
