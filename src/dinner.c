/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:16:52 by ysumeral          #+#    #+#             */
/*   Updated: 2025/05/10 14:19:31 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// STILL TEST VALUE, JUST IGNORE PLEASE.. (YSUMERAL)
static void	dinner_turn(t_program *program)
{
	printf("dinner duration %ld\n", program->dinner_duration);
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
		program->dinner_duration = get_current_time_ms()
			- program->dinner_start;
		if (eat_count > 0)
		{
			eat_count--;
			if (eat_count == 0)
				program->state = 0;
		}
		while (i < program->philo_count)
		{
			if ((get_current_time_ms() - program->philos[i]->last_eat_time)
				>= program->death_time)
				program->state = 0;
			i++;
		}
		dinner_turn(program);
	}
}
