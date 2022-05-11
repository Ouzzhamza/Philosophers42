/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:48:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/11 21:49:18 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../mandatory/philosopher.h"

void	death(t_info *rules, t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (!(rules->number_of_meals))
	{
		while (i < rules->philo_number && !(rules->died))
		{
			pthread_mutex_lock(&(rules->meals));
			if (time_diff(philosopher[i].last_meal_time, \
				get_time()) > rules->time_to_die)
				rules->died = 1;
			pthread_mutex_unlock(&(rules->meals));
			usleep (100);
			i++;
		}
		if (rules->died)
			break ;
		i = 0;
	}
	while (rules->number_of_meals != -1 && i < rules->philo_number && \
			philosopher[i].n_ate >= rules->number_of_meals)
		i++;
	if (time_diff(philosopher->last_meal_time, get_time()) < 0)
		rules->died = 1;
}
