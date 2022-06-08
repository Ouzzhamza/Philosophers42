/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:48:24 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/22 15:11:34 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

/* **************************************************** */
/*                     🅴🅰🆃🅸🅽🅶                       */
/* **************************************************** */

void	eating(t_philosopher *philo)
{
	t_info	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	printing(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	printing(rules, philo->id, "has taken a fork");
	philo->last_meal_time = get_time();
	printing(rules, philo->id, "is eating");
	sleep_time(rules->time_to_eat, rules);
	(philo->n_ate)++;
	if (philo->n_ate == rules->number_of_meals)
		rules->all_ate++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

/* **************************************************** */
/*                 🅿🅷🅸🅻🅾🆂🅾🅿🅷🅴🆁                   */
/* **************************************************** */

void	*routine(void *philosophe)
{
	t_philosopher	*philo;
	t_info			*rules;

	philo = (t_philosopher *)philosophe;
	rules = philo->rules;
	if (philo->id % 2)
		usleep (200);
	while (!(rules->died))
	{
		eating(philo);
		printing(rules, philo->id, "is sleeping");
		sleep_time(rules->time_to_sleep, rules);
		printing(rules, philo->id, "is thinking");
	}
	return (0);
}

/* **************************************************** */
/*                       🆂🆃🅰🆁🆃                       */
/* **************************************************** */

void	start(t_info *rules, t_philosopher *philosopher)
{
	int				i;

	i = 0;
	rules->first_time = get_time();
	while (i < rules->philo_number)
	{
		if (pthread_create(&(philosopher[i].thread_id), NULL, \
			routine, &(philosopher[i])) != 0)
			ft_error ("Error creating a thread");
		philosopher[i].last_meal_time = get_time();
		i++;
	}
	death(rules, philosopher);
	exiting(rules, philosopher);
}
