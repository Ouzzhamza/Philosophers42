/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:50:30 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/22 14:25:34 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

/* **************************************************** */
/*                    🆂🅻🅴🅴🅿_🆃🅸🅼🅴                  */
/* **************************************************** */

void	sleep_time(long long time, t_info *rules)
{
	long long	i;

	i = get_time();
	while (!(rules->died))
	{
		if (time_diff(i, get_time()) >= time)
			break ;
		usleep (50);
	}
}
