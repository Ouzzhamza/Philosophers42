/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:48:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/21 20:15:22 by houazzan         ###   ########.fr       */
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
	while (!philosopher->rules->died)
	{
		if (philosopher->n_ate == philosopher->rules->number_of_meals)
			exit (0);
		if (i == philosopher->rules->philo_number)
			i = 0;
		time = time_diff(philosopher->last_meal_time, get_time());
		if (time > philosopher->rules->time_to_die)
		{
			printing(philosopher->rules, philosopher[i].id, "died");
			sem_wait(philosopher->rules->write);
			philosopher->rules->died = 1;
			exit (1);
		}
		if (philosopher->rules->died == 1)
			break ;
		i++;
	}
}
