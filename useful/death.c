/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:48:14 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/07 14:25:42 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <philosopher.h>

void    death(t_info *rules)
{
    if (time_diff(rules->philosopher->last_meal_time) < 0)
        rules->died = 1;
}