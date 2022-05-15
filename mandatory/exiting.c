/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:30:28 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/15 13:33:14 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

void	exiting(t_info *rules, t_philosopher *philosopher)
{
	int	i;

	i = -1;
	while (++i < rules->philo_number)
		pthread_join(philosopher->thread_id, NULL);
	i = -1;
	while (++i < rules->philo_number)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->write));
}
