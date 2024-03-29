/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:32:38 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/22 14:18:56 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"
#include "string.h"

/* **************************************************** */
/*                     🅿🆁🅸🅽🆃🅸🅽🅶                    */
/* **************************************************** */

void	printing(t_info *rules, int id, char *str)
{
	sem_wait(rules->write);
	if (!(rules->died))
	{
		printf ("%lld ms %d %s\n", get_time() - rules->first_time, id + 1, str);
	}
	if (ft_strcmp("died", str))
		sem_post(rules->write);
}
