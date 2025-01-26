/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:55:41 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/26 18:27:08 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	thread_init(t_env *env, char **argv)
{
	pthread_mutex_init(&env->mutex, NULL);
	pthread_mutex_init(&env->mutex_death, NULL);
	pthread_mutex_init(&env->mutex_print, NULL);
	pthread_mutex_init(&env->mutex_sleep, NULL);
	if (pthread_mutex_init(&env->mutex_time, NULL) == -1)
		printf("ESTOY JODIDAMENTE MALITO\n");
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
	if (env->philo == 0)
		return (1);
	env->time = gettime(NULL);
	pthread_mutex_unlock(&env->mutex);
	return (0);
}

int	keep_open(t_env *env, char **argv)
{
	int	i;

	if (thread_init(env, argv) != 0)
		return (1);
	while (!env->death)
	{
		i = 0;
		while (!env->death && i != env->max)
		{
			pthread_mutex_lock(&env->philo[i].mutex_meals);
			if	(env->life_time <= gettime(env) - env->philo[i].last_meal)
			{
				talk(env, i + 1, 'd');
				pthread_mutex_lock(&env->mutex_death);
				env->death++;
				pthread_mutex_unlock(&env->mutex_death);
				pthread_mutex_unlock(&env->philo[i].mutex_meals);
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
	i = 0;
	while (i < env->max)
	{
		pthread_join(env->philo[i].id, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;
	int		i;

	if (argc > 6)
		return (printf("To many arguments\n"), 1);
	if (argc < 5)
		return (printf("Arguments missing\n"), 1);
	i = 0;
	while (++i < argc)
	{
		if (ft_isint(argv[i]) != 0)
			return (printf("Enter digits\n"), 1);
		if (ft_atoi(argv[i]) < 1)
			return (printf("Argument is too low\n"), 1);
	}
	if (keep_open(&env, argv) != 0)
		return (1);
	i = -1;
	while(++i != env.max)
	{
		pthread_mutex_destroy(&env.philo[i].fork);
	}
	free(env.philo);
	pthread_mutex_destroy(&env.mutex);
	pthread_mutex_destroy(&env.mutex_death);
	pthread_mutex_destroy(&env.mutex_print);
	pthread_mutex_destroy(&env.mutex_sleep);
	pthread_mutex_destroy(&env.mutex_time);
	free(env.philo);
	return (0);
}
