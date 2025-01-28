/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:59:22 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/28 19:53:09 by lgracia-         ###   ########.fr       */
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
	pthread_mutex_t	mutex_meals;
	unsigned long	last_meal;
	int				meals;
	int				i;
	pthread_mutex_t	*next;
}					t_philo;

typedef struct s_env
{
	t_philo			*philo;
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
	int				death;
	int				max;
}				t_env;

int					ft_isint(char *s);
int					ft_isdigit(int c);
long				ft_atoi(const char *nptr);
unsigned long		gettime(t_env *env);
int					die(t_env *env);
void				eat_a(t_env *env, int i);
void				talk(t_env *env, int i, char c);
void				zzz(t_env *env, int i);
t_philo				*create_philo(int max, t_env *env);

#endif
