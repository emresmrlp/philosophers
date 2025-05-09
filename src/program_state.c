/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:04:10 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 19:19:19 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	free_all(t_philo *philo)
{
	if (philo)
	{
		free(philo);
		philo = NULL;
	}
}

void	program_exit(t_philo *philo)
{
	free_all(philo);
	exit(EXIT_SUCCESS);
}

void	program_exit_error(t_philo *philo, char *error_message)
{
	if (philo)
		free_all(philo);
	if (error_message)
		printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
