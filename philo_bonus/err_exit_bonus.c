/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:29:44 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/15 17:12:56 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

/* **************************************************** */
/*                     🅵🆃_🅴🆁🆁🅾🆁                    */
/* **************************************************** */

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit (0);
}
