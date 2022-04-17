/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:29:44 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/16 17:15:16 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	ft_clear(void)
{
	return (1);
}
