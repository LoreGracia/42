/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:59:15 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/17 19:30:34 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	talk(env_t *env, int i, char c)
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
	else if (c == 'd')
		printf("%ld %d died\n", gettime(env), i);
	pthread_mutex_unlock(&env->mutex_print);
}

void	die(env_t *env, int i)
{
	if (env->life_time < gettime(env) - env->philo[i - 1].last_meal)
	{
		talk(env, i, 'd');
		env->death++;
	}
}

void	eat(env_t *env, int i)
{
	long	t;

	pthread_mutex_lock(&env->philo[i - 1].fork);
	talk(env, i, 'f');
	if (i - 1 == env->max)
		pthread_mutex_lock(&env->philo[0].fork);
	else
		pthread_mutex_lock(&env->philo[i].fork);
	t = gettime(env);
	talk(env, i, 'e');
	usleep(env->eat_time * 1000);
	//while (gettime() - t < env->eat_time)
	//	;
	pthread_mutex_unlock(&env->philo[i - 1].fork);
	if (i == env->max)
		pthread_mutex_unlock(&env->philo[0].fork);
	else
		pthread_mutex_unlock(&env->philo[i].fork);
}

void	zzz(env_t *env, int i)
{
	long	t;

	t = gettime(env);
	usleep(env->sleep_time * 1000);
	talk(env, i, 's');
	//while (t - env->sleep_time < t)
}
