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
		program_exit_error(NULL, "Error: Memory allocation failed");
	program->state = 1;
	if (validate_args(argc, argv))
	{
		program_init(program, argv);
		dinner_start(program);
		program_exit(program);
	}
	else
	{
		program_exit_error(program, "Correct usage: ./philo"\
			" (number of philo [>= 1]) (time to die [>= 1])" \
			" (time to eat [>= 1]) (time to sleep [>= 1])" \
			" (must_eat -optional- [>= 1])");
	}
	return (0);
}
