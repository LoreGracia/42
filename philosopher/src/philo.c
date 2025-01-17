/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:19:39 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/17 19:31:56 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*thread_start(void *arg)
{
	env_t				*env;
	static int			i;

	env = arg;
	i++;
	pthread_mutex_lock(&env->mutex);
	pthread_mutex_unlock(&env->mutex);
	if (i % 2 == 0)
		usleep(100);
	while (env->death == 0)
	{
		die(env, i);
		pthread_mutex_lock(&env->mutex);
		if (env->death != 0)
			break ;
		pthread_mutex_unlock(&env->mutex);
		eat(env, i);
		die(env, i);
		pthread_mutex_lock(&env->mutex);
		if (env->death != 0)
			break ;
		pthread_mutex_unlock(&env->mutex);
		zzz(env, i);
	}
	return (0);
}

int	new_thread(t_philo *node, int i, env_t *env)
{
	node->last_meal = 0;
	node->last_rest = 0;
	pthread_mutex_init(&node->fork, NULL);
	i = pthread_create(&node->id, NULL, &thread_start, env);
	if (i != 0)
		return (-1);
	pthread_detach(node->id);
	return (0);
}

t_philo	*create_philo(int max, env_t *env)
{
	t_philo			*philo;
	int				i;

	philo = malloc(sizeof(t_philo) * max);
	if (philo == 0)
		return (0);
	i = 0;
	while (i != max)
	{
		if (new_thread(&philo[i], i + 1, env) < 0)
		return (0);
		i++;
	}
	return (philo);
}
