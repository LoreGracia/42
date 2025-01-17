/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:59:22 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/17 19:14:51 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philo
{
	pthread_t		id;
	pthread_mutex_t	fork;
	long			last_meal;
	long			last_rest;
}					t_philo;

typedef struct env_s
{
	t_philo			*philo;
	int				death;
	int				max;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_sleep;
	long			time;
	long			life_time;
	long			eat_time;
	long			sleep_time;
	long			meals;
}				env_t;

void		die(env_t *env, int i);
void		zzz(env_t *env, int i);
void		eat(env_t *env, int i);
long		gettime(env_t *env);
t_philo		*create_philo(int max, env_t *env);
int			if_death(env_t *env, t_philo *philo);
int			death(t_philo *philo);

#endif
