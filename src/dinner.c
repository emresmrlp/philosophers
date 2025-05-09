/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral < ysumeral@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:16:52 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/09 22:12:32 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// TEST VALUE, JUST IGNORE PLEASE.. (YSUMERAL)
static void	dinner_turn(t_program *program)
{
	program->philos[1]->last_eat_time += 20;
}

void	dinner_start(t_program *program)
{
	int	eat_count;
	int	i;

	eat_count = program->must_eat;
	i = 0;
	while (program->state)
	{
		i = 0;
		if (eat_count > 0)
		{
			eat_count--;
			if (eat_count == 0)
				program->state = 0;
		}
		while (i < program->philo_count)
		{
			if (program->philos[i]->last_eat_time >= program->death_time)
				program->state = 0;
			i++;
		}
		dinner_turn(program);
	}	
}
