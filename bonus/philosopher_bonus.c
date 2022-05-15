/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:48:24 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/15 17:10:09 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

/* **************************************************** */
/*                     🅴🅰🆃🅸🅽🅶                       */
/* **************************************************** */

// void	eating(t_philosopher *philo)
// {
// 	t_info	*rules;

// 	rules = philo->rules;
// 	sem_wait(&(rules->forks[philo->id]));
// 	printing(rules, philo->id, "has taken a right fork");
// 	sem_wait(&(rules->forks[(philo->id + 1) % rules->philo_number]));
// 	printing(rules, philo->id, "has taken a left fork");
// 	philo->last_meal_time = get_time();
// 	printing(rules, philo->id, "is eating");
// 	sleep_time(rules->time_to_eat, rules);
// 	(philo->n_ate)++;
// 	if (philo->n_ate == rules->number_of_meals)
// 		rules->all_ate++;
// 	pthread_mutex_unlock(&(rules->forks[(philo->id + 1) \
// 	% rules->philo_number]));
// 	pthread_mutex_unlock(&(rules->forks[philo->id]));
// }

/* **************************************************** */
/*                 🅿🅷🅸🅻🅾🆂🅾🅿🅷🅴🆁                   */
/* **************************************************** */

void	*routine(t_philosopher	*philo)
{
	printf ("%d/n", philo->id);
	// if (philo->id % 2)
	// 	usleep (200);
	// if (philo->rules->philo_number < 2)
	// {
	// 	printing(rules, philo->id, "died");
	// 	rules->died = 1;
	// }
	// while (!(rules->died))
	// {
	// 	eating(philo);
	// 	printing(rules, philo->id, "is sleeping");
	// 	sleep_time(rules->time_to_sleep, rules);
	// 	printing(rules, philo->id, "is thinking");
	// }
	return (0);
}

/* **************************************************** */
/*                       🆂🆃🅰🆁🆃                       */
/* **************************************************** */

void	start(t_info *rules, t_philosopher *philosopher)
{
	int				i;
	pid_t			pid;

	i = 0;
	rules->first_time = get_time();
	while (i < rules->philo_number)
	{
		pid = fork();
		if (pid == -1)
			ft_error("Error creating a process");
		else if (pid == 0)
			routine (philosopher);
		philosopher[i].last_meal_time = get_time();
		i++;
	}
	//death(rules, philosopher);
	//exiting(rules, philosopher);
}
