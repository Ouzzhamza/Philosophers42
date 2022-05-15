/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:31:02 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/14 21:17:25 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

int	ft_atoi(char const *str)
{
	int			i;
	long int	res;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		ft_error ("Error : No negative numbers allowed");
	if (str[i] == '+')
		i++;
	res = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i++] - '0');
		else
			ft_error ("Error : Only digits allowed");
	}
	if (res > MAX_INT || res < MIN_INT)
		ft_error ("Error : number out of range");
	return (res);
}
