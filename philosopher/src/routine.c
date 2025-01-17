/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:24:49 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/17 19:29:50 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_a(env_t *env, int i)
{
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
}

void	routine_b(env_t *env, int i)
{
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

}
