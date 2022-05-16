/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:48:24 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/16 19:02:32 by houazzan         ###   ########.fr       */
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
	sem_wait(&(rules->forks[philo->id]));
	printing(rules, philo->id, "has taken a right fork");
	sem_wait(&(rules->forks[(philo->id + 1) % rules->philo_number]));
	printing(rules, philo->id, "has taken a left fork");
	philo->last_meal_time = get_time();
	printing(rules, philo->id, "is eating");
	sleep_time(rules->time_to_eat, rules);
	sem_post(&(rules->forks[philo->id]));
	sem_post(&(rules->forks[(philo->id + 1) % rules->philo_number]));
	(philo->n_ate)++;
	if (philo->n_ate == rules->number_of_meals)
		rules->all_ate++;
}

/* **************************************************** */
/*                 🅿🅷🅸🅻🅾🆂🅾🅿🅷🅴🆁                   */
/* **************************************************** */

void	*process_routine(t_philosopher	*philo)
{
	if (philo->id % 2)
		usleep (200);
	if (pthread_create(&(philo->thread_id), NULL, (void *)p_death, \
		(&philo)) != 0)
		ft_error ("Error creating a thread");
	while (!(philo->rules->died))
	{
		eating(philo);
		printing(philo->rules, philo->id, "is sleeping");
		sleep_time(philo->rules->time_to_sleep, philo->rules);
		printing(philo->rules, philo->id, "is thinking");
	}
	pthread_join(philo->thread_id, NULL);
	return (NULL);
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
		philosopher[i].pid = fork();
		if (philosopher[i].pid == -1)
			ft_error("Error creating a process");
		if (philosopher[i].pid == 0)
			process_routine(&philosopher[i]);
		philosopher[i].last_meal_time = get_time();
		i++;
	}
	exiting(rules, philosopher);
}
