/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:55:41 by lgracia-          #+#    #+#             */
/*   Updated: 2025/01/22 17:46:23 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

int	thread_init(t_env *env, char **argv)
{
	pthread_mutex_init(&env->mutex, NULL);
	pthread_mutex_init(&env->mutex_death, NULL);
	pthread_mutex_init(&env->mutex_print, NULL);
	pthread_mutex_init(&env->mutex_sleep, NULL);
	pthread_mutex_init(&env->mutex_time, NULL);
	env->death = 0;
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
	while (env->death < env->max)
		;
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
	if (thread_init(&env, argv) != 0)
		return (1);
	pthread_mutex_destroy(&env.mutex);
	pthread_mutex_destroy(&env.mutex_death);
	pthread_mutex_destroy(&env.mutex_print);
	pthread_mutex_destroy(&env.mutex_sleep);
	pthread_mutex_destroy(&env.mutex_time);
	free(env.philo);
	return (0);
}
