/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:48:24 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/10 22:48:09 by houazzan         ###   ########.fr       */
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
	//pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	printing(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	printing(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&rules->meals);
	printing(rules, philo->id, "is eating");
	//philo->last_meal_time = get_time();
	// pthread_mutex_unlock(&(rules->meal_check));
	// smart_sleep(rules->time_eat, rules);
	// (philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[(philo->id + 1) % rules->philo_number]));
	pthread_mutex_unlock(&(rules->forks[philo->id]));
}

/* **************************************************** */
/*                 🅿🅷🅸🅻🅾🆂🅾🅿🅷🅴🆁                   */
/* **************************************************** */

void	*philosopher(void *philosophe)
{
	t_philosopher	*philo;
	t_info			*rules;

	philo = (t_philosopher *)philosophe;
	rules = philo->rules;
	if (philo->id % 2)
		usleep (15000);
	while (1)
	{
		eating(philo);
		printing(rules, philo->id, "is sleeping");
		usleep(rules->time_to_sleep * 1000);
		printing(rules, philo->id, "is thinking");
	}
	return (0);
}

/* **************************************************** */
/*                       🆂🆃🅰🆁🆃                      */
/* **************************************************** */

void	start(t_info *rules)
{
	int				i;

	i = 0;
	rules->first_time = get_time();
	while (i < rules->philo_number)
	{
		if (pthread_create(&(rules->philosopher[i].thread_id), NULL, \
			philosopher, &(rules->philosopher[i])) != 0)
			ft_error ("Error creating a thread");
		rules->philosopher[i].last_meal_time = get_time();
		i++;
	}
	death(rules);
}
