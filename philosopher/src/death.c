/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:38:10 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/16 17:31:17 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	death(t_philo *lst)
{
	int	s;

	s = pthread_join(lst->id, NULL);
	if (s != 0)
		return (1);
	free(lst);
	return (0);
}

int	if_death(env_t	*env, t_philo *philo)
{
	if (env->death != 0)
		return (0);
	else
		return (death(philo));
	return (0);
}
