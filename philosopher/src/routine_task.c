/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:59:15 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/22 16:56:51 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	talk(t_env *env, int i, char c)
{
	if (!die(env, i))
	{
		pthread_mutex_lock(&env->mutex_print);
		if (c == 'f')
			printf("%ld %d has taken a fork\n", gettime(env), i);
		else if (c == 'e')
			printf("%ld %d is eating\n", gettime(env), i);
		else if (c == 's')
			printf("%ld %d is sleeping\n", gettime(env), i);
		else if (c == 't')
			printf("%ld %d is thinking\n", gettime(env), i);
		pthread_mutex_unlock(&env->mutex_print);
		return (0);
	}
	return (1);
}

int	die(t_env *env, int i)
{
	pthread_mutex_lock(&env->mutex_death);
	if (env->death != 0 || env->life_time < gettime(env)
		- env->philo[i - 1].last_meal)
	{
		env->death++;
		if (env->death == 1)
			printf("%ld %d died\n", gettime(env), i);
		printf("%lu = %ld %ld, %lu\n", env->life_time, gettime(env), env->philo[i - 1].last_meal, gettime(env) - env->philo[i - 1].last_meal);
		return (pthread_mutex_unlock(&env->mutex_death), 1);
	}
	return (pthread_mutex_unlock(&env->mutex_death), 0);
}

int	zzz(t_env *env, int i)
{
	long	t;

	t = gettime(env);
	if (talk(env, i, 's'))
		return (1);
	return (0);
	usleep(env->sleep_time);
	if (talk(env, i, 't'))
		return (1);
	return (0);
}

int	eat_b(t_env *env, int i)
{
	if (i == env->max)
		pthread_mutex_lock(&env->philo[0].fork);
	else
		pthread_mutex_lock(&env->philo[i].fork);
	if (talk(env, i, 'f'))
		return (1);
	if (die(env, i))
		return (1);
	pthread_mutex_lock(&env->philo[i - 1].fork);
	if (talk(env, i, 'f'))
		return (1);
	if (talk(env, i, 'e'))
		return (1);
	usleep(env->eat_time);
	env->philo[i - 1].last_meal = gettime(env);
	env->philo[i - 1].meals++;
	if (i == env->max)
		pthread_mutex_unlock(&env->philo[0].fork);
	else
		pthread_mutex_unlock(&env->philo[i].fork);
	pthread_mutex_unlock(&env->philo[i - 1].fork);
	return (zzz(env, i));
}

int	eat_a(t_env *env, int i)
{
	pthread_mutex_lock(&env->philo[i - 1].fork);
	if (talk(env, i, 'f'))
		return (1);
	if (die(env, i))
		return (1);
	if (i == env->max)
		pthread_mutex_lock(&env->philo[0].fork);
	else
		pthread_mutex_lock(&env->philo[i].fork);
	if (talk(env, i, 'f'))
		return (1);
	if (talk(env, i, 'e'))
		return (1);
	usleep(env->eat_time * 1000);
	env->philo[i - 1].last_meal = gettime(env);
	env->philo[i - 1].meals++;
	pthread_mutex_unlock(&env->philo[i - 1].fork);
	if (i == env->max)
		pthread_mutex_unlock(&env->philo[0].fork);
	else
		pthread_mutex_unlock(&env->philo[i].fork);
	return (zzz(env, i));
}
