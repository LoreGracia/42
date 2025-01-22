/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:57:40 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/22 13:00:49 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long	gettime(t_env *env)
{
	struct timeval	tv;
	unsigned long	time;

	if (env == NULL)
	{
		gettimeofday(&tv, NULL);
		time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	}
	else
	{
		pthread_mutex_lock(&env->mutex_time);
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - env->time;
		pthread_mutex_unlock(&env->mutex_time);
	}
	return (time);
}
