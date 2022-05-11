/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:32:38 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/11 16:05:12 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../mandatory/philosopher.h"


/* **************************************************** */
/*                     🅿🆁🅸🅽🆃🅸🅽🅶                    */
/* **************************************************** */

void	printing(t_info *rules, int id, char *str)
{
	pthread_mutex_lock(&rules->write);
	if ((rules->died))
	{
		printf ("%lli %d %s\n", get_time() - rules->first_time, id + 1, str);
	}
	pthread_mutex_unlock(&rules->write);
}
