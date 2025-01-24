/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:19:39 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/24 19:28:02 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine(t_env *env, int i)
{
	if (env->max == 1)
	{
		talk(env, i, 'f');
		env->death++;
		talk(env, i, 'd');
	}
	while (env->death == 0)
	{
		if (i % 2 != 0)
			eat_a(env, i);
		else
			eat_b(env, i);
		if (env->meals && env->philo[i - 1].meals == env->meals)
		{
			env->done++;
			break ;
		}
	}
}

void	*thread_start(void *arg)
{
	t_env				*env;
	static int			num;
	int					i;

	env = arg;
	num++;
	i = num;
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
	i = pthread_create(&node->id, NULL, &thread_start, env);
	if (i != 0)
		return (-1);
	pthread_detach(node->id);
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
			return (0);
		i++;
	}
	return (philo);
}
