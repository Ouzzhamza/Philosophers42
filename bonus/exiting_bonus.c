/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:30:28 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/16 18:58:38 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

void	exiting(t_info *rules, t_philosopher *philosopher)
{
	(void) (rules);
	int	i;
	int	state;

	i = 0;
	while (1)
	{
		waitpid (-1, &state, 0);
		if (state == 1)
			while (i < philosopher->rules->philo_number)
				kill(philosopher->pid, SIGTERM);
	}
}
