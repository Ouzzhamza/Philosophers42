/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:26:23 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/16 17:01:45 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher(void *)
{

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

int	get_info(int ac, char **av, t_info rules)
{
	rules.philo_number = ft_atoi(av[1]);
	rules.time_to_die = ft_atoi(av[2]);
	rules.time_to_eat = ft_atoi(av[3]);
	rules.time_to_sleep = ft_atoi(av[4]);
	if (ac == 7)
		rules.number_of_meals = ft_atoi(av[5]);
	else
		rules.number_of_meals = 0;
}

/* **************************************************** */
/*                        🅼🅰🅸🅽                       */
/* **************************************************** */

int	main(int ac, char **av)
{
	t_info	rules;

	if (ac < 6 || ac > 7)
		return (ft_error ("Number of argument is wrong "));
	if (!get_info(ac, av, rules))
		return (ft_error() && ft_clear());
	creat_philo(rules);
}
