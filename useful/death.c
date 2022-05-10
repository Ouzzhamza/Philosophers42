/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:48:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/10 22:41:44 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../mandatory/philosopher.h"

void	death(t_info *rules)
{
	if (time_diff(rules->philosopher->last_meal_time) < 0)
		rules->died = 1;
}
