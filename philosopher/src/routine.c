/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:24:49 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/22 13:10:00 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	routine_a(t_env *env, int i)
{
	usleep(1000);
	while (env->death == 0)
	{
		if (eat_a(env, i))
			break ;
	}
}

void	routine_b(t_env *env, int i)
{
	while (env->death == 0)
	{
		if (eat_a(env, i))
			break ;
		if (die(env, i) != 0)
			break ;
	}
}
