/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:46:36 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/22 12:12:21 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_simulation	*sim;

	if (init_simulation(argc, argv, &sim) != 0)
		return (1);
	simulation_manager(sim);
	if (join_philos(sim) != 0)
		return (1);
	cleanup(sim);
	return (0);
}
