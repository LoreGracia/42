/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:57:40 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/22 19:53:27 by lgracia-         ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (0);
	else
		return (1);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	ptr;
	long	sign;

	if (!*nptr)
		return (0);
	i = 0;
	ptr = 0;
	sign = 1;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		ptr = nptr[i] - '0' + (10 * ptr);
		i++;
	}
	ptr *= sign;
	return (ptr);
}

int	ft_isint(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i++]) != 0)
			return (1);
	}
	return (0);
}
