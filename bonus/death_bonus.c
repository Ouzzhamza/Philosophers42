/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:48:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/17 12:54:39 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

/* **************************************************** */
/*                       🅳🅴🅰🆃🅷                       */
/* **************************************************** */

void	p_death( void *philo)
{
	int				i;
	long long		time;
	t_philosopher	*philosopher;

	i = 0;
	philosopher = (t_philosopher *) philo;
	while (1)
	{
		if (i == philosopher->rules->philo_number)
			i = 0;
		time = time_diff(philosopher[i].last_meal_time, get_time());
		if (time > philosopher->rules->time_to_die || \
			(philosopher->rules->all_ate == philosopher->rules->philo_number))
		{
			if (time > philosopher->rules->time_to_die)
			{
				printing(philosopher->rules, philosopher[i].id, "died");
				philosopher->rules->died = 1;
				exit(1);
			}
			philosopher->rules->died = 1;
			break ;
		}
		usleep (100);
		i++;
	}
}
