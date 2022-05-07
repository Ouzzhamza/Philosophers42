/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:48:24 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/07 18:42:48 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <philosopher.h>

/* **************************************************** */
/*                     🅴🅰🆃🅸🅽🅶                       */
/* **************************************************** */

void	eating(t_philosopher *philo)
{
	t_info *rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	printing(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	printing(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meals));
	printing(rules, philo->id, "is eating");
	//philo->last_meal_time = get_time();
	// pthread_mutex_unlock(&(rules->meal_check));
	// smart_sleep(rules->time_eat, rules);
	// (philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
	
}

/* **************************************************** */
/*                 🅿🅷🅸🅻🅾🆂🅾🅿🅷🅴🆁                   */
/* **************************************************** */

void	philosopher(void *philosophe)
{
	t_philosopher	*philo;
	t_info			*rules;

	philo = (t_philosopher	*)philosophe;
	rules = philo->rules;
	// if(philo->id % 2)
	// 	usleep
	while (!rules->died)
	{
		eating(philo);
		printing(rules, philo->id, "is sleeping");
		sleping();
		printing(rules, philo->id, "is thinking");
	}
}

/* **************************************************** */
/*                       🆂🆃🅰🆁🆃                      */
/* **************************************************** */

void    start(t_info *rules)
{
	int				i;
	t_philosopher	*philo;

	i = rules->philo_number;
	rules->first_time = get_time();
	while (i < 0)
	{
		if (pthread_create(&(philo[i].id), NULL, &philosopher, &(philo[i])))
    		return (0);
		rules->philosopher[i].last_meal_time = get_time();
		i++;
	}
	death(rules);
}
