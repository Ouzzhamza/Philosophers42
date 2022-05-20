/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:48:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/20 17:55:21 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

void	dead(t_philosopher *philosopher, int i, long long time)
{
	if (time > philosopher->rules->time_to_die)
	{
		printing(philosopher->rules, philosopher[i].id, "died");
		philosopher->rules->died = 1;
		exit(1);
	}
}

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
		time = time_diff(philosopher->last_meal_time, get_time());
		if (time > philosopher->rules->time_to_die || \
			(philosopher->rules->all_ate == philosopher->rules->philo_number))
		{
			dead(philosopher, i, time);
			philosopher->rules->died = 1;
			break ;
		}
		usleep (100);
		i++;
	}
}
