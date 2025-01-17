/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:57:40 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/17 19:08:06 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	gettime(env_t *env)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	if (env == NULL)
		return (tv.tv_sec * 1000);
	else
		return ((tv.tv_sec * 1000) - env->time);
}
