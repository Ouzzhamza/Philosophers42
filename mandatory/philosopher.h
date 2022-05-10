/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:08:33 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/10 16:31:54 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

/* **************************************************** */
/*                  🅳🅰🆃🅰 🆂🆃🆁🆄🅲🆃                  */
/* **************************************************** */
typedef struct philosopher
{
	int					id;
	int					left_fork_id;
	int					right_fork_id;
	int					last_meal_time;
	struct s_info		*rules;
	pthread_t			thread_id;

}	t_philosopher;

typedef struct s_info
{
	int				philo_number;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				number_of_meals;
	int				ate;
	int				died;
	long long		first_time;
	pthread_mutex_t	*meals;
	pthread_mutex_t	*forks;
	t_philosopher	*philosopher;
}	t_info;

/* **************************************************** */
/*             🆁🅴🅶🆄🅻🅰🆁 🅵🆄🅽🅲🆃🅸🅾🅽🆂             */
/* **************************************************** */

int			ft_atoi(char const *str);
int			ft_strlen(char *str);
int			ft_clear(void);
int			ft_error(char *str);
void		start(t_info *rules);
void		printing(t_info *rules ,int id, char *str);
int			init_mutex(t_info *rules);
long long	get_time(void);
long long	time_diff(long long last_meal);
void		death(t_info *rules);

#endif
