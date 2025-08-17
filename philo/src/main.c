/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:46:36 by ysumeral          #+#    #+#             */
/*   Updated: 2025/08/17 14:07:48 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_simulation	*sim;

	init_simulation(argc, argv, &sim);
	simulation_manager(sim);
	join_philos(sim);
	cleanup(sim);
	return (0);
}
