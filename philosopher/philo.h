/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:59:22 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/24 16:43:50 by lgracia-         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		id;
	pthread_mutex_t	fork;
	unsigned long	last_meal;
	int				meals;
	int				i;
}					t_philo;

typedef struct t_env
{
	t_philo			*philo;
	int				death;
	int				max;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_death;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_sleep;
	pthread_mutex_t	mutex_time;
	unsigned long	time;
	unsigned long	life_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	int				meals;
	int				done;
}				t_env;

void				free_philo(t_env *env);
int					ft_isint(char *s);
long				ft_atoi(const char *nptr);
int					ft_isdigit(int c);
void				talk(t_env *env, int i, char c);
void				zzz(t_env *env, int i);
void				eat_a(t_env *env, int i);
void				eat_b(t_env *env, int i);
unsigned long		gettime(t_env *env);
t_philo				*create_philo(int max, t_env *env);
int					if_death(t_env *env, t_philo *philo);
int					death(t_philo *philo);
void				routine_a(t_env *env, int i);
void				routine_b(t_env *env, int i);

#endif
