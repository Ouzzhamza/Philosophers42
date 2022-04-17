/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyber-z3ter <cyber-z3ter@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:26:23 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/17 14:36:06 by cyber-z3ter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*init_mutex(t_info *rules)
{
	int i;

	i = rules->philo_number;
	while (i-- > 0)
	

}

/* **************************************************** */
/*             🅲🆁🅴🅰🆃_🆃🅷🆁🅴🅰🅳🆂                    */
/* **************************************************** */

void	creat_philo(t_info rules)
{
	pthread_t	tid;
	int			i;

	while (rules.philo_number-- <= 0)
		pthread_create(&tid, NULL, philosopher, (void *) *arg);
}

/* **************************************************** */
/*                     🅶🅴🆃_🅸🅽🅵🅾                    */
/* **************************************************** */

int	get_info(int ac, char **av, t_info *rules)
{
	rules->philo_number = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->ate = 0;
	rules->died = 0;
	if (ac == 6)
	{
		rules->number_of_meals = ft_atoi(av[5]);
		if (rules->number_of_meals == 0)
			return (0);
	}
	else
		rules->number_of_meals = 0;
	if (rules->philo_number < 2 || rules->philo_number > 250  || rules->time_to_die < 0 || \
		rules->time_to_sleep < 0 || rules->time_to_sleep < 0)
		return (0);
	if (!init_mutex)
		return (0);
	return(1);
} 

/* **************************************************** */
/*                        🅼🅰🅸🅽                           */
/* **************************************************** */

int	main(int ac, char **av)
{
	t_info	rules;

	if (ac != 5 || ac != 6)
		return (ft_error ("Number of argument is wrong "));
	if (!get_info(ac, av, &rules))
		return (ft_error() && ft_clear());
}
