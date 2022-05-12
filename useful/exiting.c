/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:30:28 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/12 19:00:39 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../mandatory/philosopher.h"


void	exiting(t_info *rules, t_philosopher *philosopher)
{
	int	i;

	i = -1;
	while (++i < rules->philo_number)
		pthread_join(philosopher[i].thread_id, NULL);
	// i = -1;
	// while (++i < rules->philo_number)
}
