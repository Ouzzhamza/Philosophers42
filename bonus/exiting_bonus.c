/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:30:28 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/20 17:15:58 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

void	exiting(t_info *rules, t_philosopher *philosopher)
{
	int	i;
	int	state;

	i = 0;
	while (1)
	{
		waitpid (-1, &state, 0);
		if (state != 0)
		{
			while (i < rules->philo_number)
			{
				kill(philosopher[i].pid, 9);
				i++;
			}
			free (philosopher);
			break ;
		}
	}
	sem_close(rules->write);
	sem_close(rules->forks);
	sem_unlink("/philosopher_write");
	sem_unlink("/philosopher_forks");
}
