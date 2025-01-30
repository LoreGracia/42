/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:55:41 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/30 18:14:04 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	thread_init(t_env *env, char **argv)
{
	pthread_mutex_init(&env->mutex, NULL);
	pthread_mutex_init(&env->mutex_death, NULL);
	pthread_mutex_init(&env->mutex_print, NULL);
	pthread_mutex_init(&env->mutex_sleep, NULL);
	pthread_mutex_init(&env->mutex_time, NULL);
	env->death = 0;
	env->done = 0;
	env->max = ft_atoi(argv[1]);
	env->life_time = ft_atoi(argv[2]);
	env->eat_time = ft_atoi(argv[3]);
	env->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		env->meals = ft_atoi(argv[5]);
	else
		env->meals = 0;
	pthread_mutex_lock(&env->mutex);
	env->philo = create_philo(env->max, env);
	env->time = gettime(NULL);
	pthread_mutex_unlock(&env->mutex);
}

void	death(t_env *env, int i)
{
	talk(env, i + 1, 'd');
	pthread_mutex_lock(&env->mutex_death);
	env->death++;
	pthread_mutex_unlock(&env->mutex_death);
	pthread_mutex_unlock(&env->philo[i].mutex_meals);
}

void	keep_open(t_env *env, int i)
{
	while (!env->death)
	{
		i = 0;
		while (!env->death && i != env->max)
		{
			pthread_mutex_lock(&env->philo[i].mutex_meals);
			if (env->life_time <= gettime(env) - env->philo[i].last_meal)
			{
				death(env, i);
				break ;
			}
			pthread_mutex_unlock(&env->philo[i].mutex_meals);
			pthread_mutex_lock(&env->mutex_death);
			if (env->done == env->max)
			{
				env->death++;
				pthread_mutex_unlock(&env->mutex_death);
				break ;
			}
			pthread_mutex_unlock(&env->mutex_death);
			i++;
		}
	}
}

void	destroy(t_env *env, int i)
{
	if (env->death < 0)
		env->max -= env->max - (env->death * -1);
	while (++i != env->max)
	{
		pthread_join(env->philo[i].id, NULL);
		pthread_mutex_destroy(&env->philo[i].fork);
	}
	free(env->philo);
	pthread_mutex_destroy(&env->mutex);
	pthread_mutex_destroy(&env->mutex_death);
	pthread_mutex_destroy(&env->mutex_print);
	pthread_mutex_destroy(&env->mutex_sleep);
	pthread_mutex_destroy(&env->mutex_time);
}

int	main(int argc, char **argv)
{
	t_env	env;
	int		i;

	if (argc > 6)
		return (printf("\e[91mTo many arguments\n"), 1);
	if (argc < 5)
		return (printf("\e[91mArguments missing\n"), 1);
	i = 0;
	while (++i < argc)
	{
		if (ft_isint(argv[i]) != 0)
			return (printf("\e[91mEnter digits, positive numbers\n"), 1);
		if (ft_atoi(argv[i]) < 1)
			return (printf("\e[91mArgument is too low\n"), 1);
	}
	thread_init(&env, argv);
	keep_open(&env, 0);
	destroy(&env, -1);
	return (0);
}
