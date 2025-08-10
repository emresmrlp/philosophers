/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:20:14 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 22:10:54 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_program	*program;

	program = (t_program *)malloc(sizeof(t_program));
	if (!program)
		exit_with_error(NULL, "Error: Memory allocation failed");
	program->simulation_running = 1;
	if (validate_args(argc, argv))
	{
		init_data(program, argv);
		start_simulation(program);
		cleanup_data(program);
	}
	else
	{
		exit_with_error(program, "Correct usage: ./philo"\
			" (number of philo [>= 1]) (time to die [>= 1])" \
			" (time to eat [>= 1]) (time to sleep [>= 1])" \
			" (must_eat -optional- [>= 1])");
	}
	return (0);
}
