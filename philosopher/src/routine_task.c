/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:59:15 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/26 18:23:36 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	die(t_env *env)
{
	int	i;

	pthread_mutex_lock(&env->mutex_death);
	i = env->death;
	pthread_mutex_unlock(&env->mutex_death);
	return (i);
}

void	talk(t_env *env, int i, char c)
{
	pthread_mutex_lock(&env->mutex_print);
	if (!die(env) && c != 'd')
	{
		if (c == 'f')
			printf("\e[0;1;97m%ld %d \e[0;33mhas taken a fork\n", gettime(env), i);
		else if (c == 'e')
			printf("\e[0;1;97m%ld %d \e[0;32mis eating\n", gettime(env), i);
		else if (c == 's')
			printf("\e[0;1;97m%ld %d \e[0;36mis sleeping\n", gettime(env), i);
		else if (c == 't')
			printf("\e[0;1;97m%ld %d \e[0mis thinking\n", gettime(env), i);

	}
	else if (c == 'd')
		printf("\e[0;1;97m%ld %d \e[0;5;91mdied\n\e[0m", gettime(env), i);
	pthread_mutex_unlock(&env->mutex_print);
}

void	zzz(t_env *env, int i)
{
	talk(env, i, 's');
	usleep(env->sleep_time * 1000);
	talk(env, i, 't');
}

int	eat_a(t_env *env, int i)
{
	pthread_mutex_lock(&env->philo[i - 1].fork);
	if (i == env->max)
		pthread_mutex_lock(&env->philo[0].fork);
	else
		pthread_mutex_lock(&env->philo[i].fork);
	talk(env, i, 'f');
	talk(env, i, 'e');
	pthread_mutex_lock(&env->philo[i - 1].mutex_meals);
	env->philo[i - 1].last_meal = gettime(env);
	env->philo[i - 1].meals++;
	pthread_mutex_unlock(&env->philo[i - 1].mutex_meals);
	usleep(env->eat_time * 1000);
	if (i == env->max)
		pthread_mutex_unlock(&env->philo[0].fork);
	else
		pthread_mutex_unlock(&env->philo[i].fork);
	pthread_mutex_unlock(&env->philo[i - 1].fork);
	zzz(env, i);
	return (0);
}

int	eat_b(t_env *env, int i)
{
	if (i == env->max)
		pthread_mutex_lock(&env->philo[0].fork);
	else
		pthread_mutex_lock(&env->philo[i].fork);
	pthread_mutex_lock(&env->philo[i - 1].fork);
	talk(env, i, 'f');
	talk(env, i, 'e');
	pthread_mutex_lock(&env->philo[i - 1].mutex_meals);
	env->philo[i - 1].last_meal = gettime(env);
	env->philo[i - 1].meals++;
	pthread_mutex_unlock(&env->philo[i - 1].mutex_meals);
	usleep(env->eat_time * 1000);
	pthread_mutex_unlock(&env->philo[i - 1].fork);
	if (i == env->max)
		pthread_mutex_unlock(&env->philo[0].fork);
	else
		pthread_mutex_unlock(&env->philo[i].fork);
	zzz(env, i);
	return (0);
}
