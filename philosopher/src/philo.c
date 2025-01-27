/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:19:39 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/27 12:53:28 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine(t_env *env, int i)
{
	if (env->max == 1)
		talk(env, i, 'f');
	else
	{
		if (i % 2 == 0)
			usleep(env->eat_time * 1000);
		while (1)
		{
			if (die(env))
				break ;
			eat_a(env, i);
			if (env->meals && env->philo[i - 1].meals == env->meals)
			{
				pthread_mutex_lock(&env->mutex_death);
				env->done++;
				pthread_mutex_unlock(&env->mutex_death);
				break ;
			}
		}
	}
}

void	*thread_start(void *arg)
{
	t_env				*env;
	static int			num;
	int					i;

	env = arg;
	pthread_mutex_lock(&env->mutex_death);
	num++;
	i = num;
	pthread_mutex_unlock(&env->mutex_death);
	if (i == env->max)
		env->philo[i - 1].next = &env->philo[0];
	else
		env->philo[i - 1].next = &env->philo[i];
	pthread_mutex_lock(&env->mutex);
	pthread_mutex_unlock(&env->mutex);
	routine(env, i);
	return (0);
}

int	new_thread(t_philo *node, t_env *env)
{
	int	i;

	node->last_meal = 0;
	node->meals = 0;
	pthread_mutex_init(&node->fork, NULL);
	pthread_mutex_init(&node->mutex_meals, NULL);
	i = pthread_create(&node->id, NULL, &thread_start, env);
	if (i != 0)
	{
		env->death++;
		return (-1);
	}
	return (0);
}

t_philo	*create_philo(int max, t_env *env)
{
	t_philo			*philo;
	int				i;

	philo = malloc(sizeof(t_philo) * max);
	if (philo == 0)
		return (0);
	i = 0;
	while (i != max)
	{
		if (new_thread(&philo[i], env) < 0)
			return (philo);
		i++;
	}
	return (philo);
}
