/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:48:24 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/09 19:48:50 by houazzan         ###   ########.fr       */
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
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	printing(philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	printing(philo->id, "has taken a fork");
	pthread_mutex_lock(rules->meals);
	printing(philo->id, "is eating");
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

void	*philosopher(void *philosophe)
{
	printf("here\n");
	t_philosopher	*philo;
	t_info			*rules;

	philo = (t_philosopher *)philosophe;
	rules = philo->rules;
	// if(philo->id % 2)
	// 	usleep 
	while (!rules->died)
	{
		eating(philo);
		printing(philo->id, "is sleeping");
		usleep(rules->time_to_sleep * 1000);
		printing(philo->id, "is thinking");
	}
	return (0);
}

/* **************************************************** */
/*                       🆂🆃🅰🆁🆃                      */
/* **************************************************** */

void	start(t_info *rules)
{
	int				i;
	t_philosopher	*philo;

	philo = NULL;
	i = 0;
	rules->first_time = get_time();
	philo = malloc (rules->philo_number * sizeof (t_philosopher));
	while (i < rules->philo_number)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, philosopher, \
			&(philo[i])) != 0)
			ft_error ("Error creating a thread");
		printf("hello\n");
		rules->philosopher[i].last_meal_time = get_time();
		i++;
		death(rules); 
	}
}
