/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:26:23 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/10 15:08:56 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* **************************************************** */
/*                    🅵🅸🅻_🅸🅽🅵🅾                     */
/* **************************************************** */
int	init_mutex(t_info *rules)
{
	int	i;

	i = 0;
	rules->forks = malloc (rules->philo_number * sizeof(pthread_mutex_t));
	while (i < rules->philo_number)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

/* **************************************************** */
/*                    🅵🅸🅻_🅸🅽🅵🅾                     */
/* **************************************************** */

int	init_philo(t_info *rules)
{
	int	i;

	i = 0;
	rules->philosopher = malloc (rules->philo_number * sizeof (t_philosopher));
	while (i < rules->philo_number)
	{
		rules->philosopher[i].id = i;
		rules->philosopher[i].left_fork_id = i;
		rules->philosopher[i].right_fork_id = (i + 1) % rules->philo_number;
		rules->philosopher->last_meal_time = 0;
		i++;
	}
	return (1);
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
	if (rules->philo_number < 2 || rules->time_to_die < 0 || \
		rules->time_to_sleep < 0 || rules->time_to_sleep < 0)
		return (0);
	init_mutex(rules);
	init_philo(rules);
	return (1);
}

/* **************************************************** */
/*                        🅼🅰🅸🅽                        */
/* **************************************************** */

int	main(int ac, char **av)
{
	t_info	rules;

	if (ac != 5 && ac != 6)
		return (ft_error("Number of argument is wrong"));
	if (!get_info(ac, av, &rules))
		return (ft_error("Probleme In Information") && ft_clear());
	start(&rules);
	return (0);
}
