/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:48:24 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/17 20:04:59 by houazzan         ###   ########.fr       */
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
	sem_wait(rules->forks);
	printing(rules, philo->id, "has taken a right fork");
	sem_wait(rules->forks);
	printing(rules, philo->id, "has taken a left fork");
	philo->last_meal_time = get_time();
	printing(rules, philo->id, "is eating");
	//sleep_time(rules->time_to_eat, rules);
	(philo->n_ate)++;
	sem_post(rules->forks);
	sem_post(rules->forks);
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
	philo->last_meal_time = get_time();
	while (!(philo->rules->died))
	{
		eating(philo);
		printing(philo->rules, philo->id, "is sleeping");
		// sleep_time(philo->rules->time_to_sleep, philo->rules);
		// printing(philo->rules, philo->id, "is thinking");
	}
	pthread_detach(philo->thread_id);
	if (philo->rules->died)
		exit (1);
	exit (0);
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
		i++;
	}
	exiting(rules, philosopher);
}
