/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:48:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/22 12:48:48 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

/* **************************************************** */
/*                       🅳🅴🅰🆃🅷                       */
/* **************************************************** */

void	p_death( void *philo)
{
	int				i;
	int				j;
	long long		time;
	t_philosopher	*philosopher;

	i = 0;
	j = 0;
	philosopher = (t_philosopher *) philo;
	while (!philosopher->rules->died)
	{
		if (i == philosopher->rules->philo_number)
			i = 0;
		time = time_diff(philosopher->last_meal_time, get_time());
		if (time > philosopher->rules->time_to_die)
		{
			printing(philosopher->rules, philosopher[i].id, "died");
			exit (1);
		}
		if (philosopher->n_ate == philosopher->rules->number_of_meals)
			break ;
		i++;
	}
}
