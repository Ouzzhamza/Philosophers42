/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:30:28 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/21 20:04:22 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

void	exiting(t_info *rules, t_philosopher *philosopher)
{
	int	i;
	int	state;
	int	j;

	i = 0;
	j = 0;
	while (j < philosopher->rules->philo_number)
	{
		waitpid (-1, &state, 0);
		if (state != 0)
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
