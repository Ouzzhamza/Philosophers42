/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:30:28 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/22 14:22:59 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"
/* **************************************************** */
/*                     🅴🆇🅸🆃🅸🅽🅶                      */
/* **************************************************** */

void	exiting(t_info *rules, t_philosopher *philosopher)
{
	int	i;
	int	stat_loc;
	int	j;

	i = 0;
	j = 0;
	while (j < philosopher->rules->philo_number)
	{
		waitpid (-1, &stat_loc, 0);
		if (stat_loc != 0)
		{
			while (i < rules->philo_number)
			{
				kill(philosopher[i].pid, SIGKILL);
				i++;
			}
			free (philosopher);
			break ;
		}
		++j;
	}
	sem_close(rules->write);
	sem_close(rules->forks);
	sem_unlink("/philosopher_write");
	sem_unlink("/philosopher_forks");
}
