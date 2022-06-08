/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:48:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/20 10:24:53 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

/* **************************************************** */
/*                       🅳🅴🅰🆃🅷                       */
/* **************************************************** */

void	death(t_info *rules, t_philosopher *philosopher)
{
	int			i;
	long long	time;

	i = 0;
	while (1)
	{
		if (i == rules->philo_number)
			i = 0;
		time = time_diff(philosopher[i].last_meal_time, get_time());
		if (time > rules->time_to_die || \
			(rules->all_ate == rules->philo_number))
		{
			if (time > rules->time_to_die)
			{
				printing(rules, philosopher[i].id, "died");
			}
			rules->died = 1;
			break ;
		}
		usleep (100);
		i++;
	}
}
