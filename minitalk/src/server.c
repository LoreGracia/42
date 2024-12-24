/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:23:53 by lgracia-          #+#    #+#             */
/*   Updated: 2024/12/24 16:10:46 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_i = -1;

void	manage(t_env *env, int a)
{
	if (!env->l)
	{
		env->len |= (a << (31 - ++g_i));
		env->count++;
		if (env->count == 32)
		{
			g_i = -1;
			env->l = env->len;
			env->s = malloc(sizeof(char) * env->len);
			if (!env->s)
				exit (1);
		}
	}
	else
	{
		env->count = 0;
		env->len = 0;
		env->l = 0;
		g_i = -1;
		ft_printf("%s\n", env->s);
		if (env->s)
			free(env->s);
	}
}

void	from_bits(int a, int pid)
{
	static t_env			env;

	usleep(100);
	if (env.count < 32)
		manage(&env, a);
	else if (env.count >= 32 && env.len)
	{
		env.bit |= (a << (31 - ++g_i));
		if (g_i == 31)
		{
			env.s[env.l - env.len] = env.bit;
			env.bit = 0;
			g_i = -1;
			if (!--env.len)
				manage(&env, a);
		}
	}
	if (kill(pid, SIGUSR1) == -1)
		exit(ft_printf("Signal mixed\n") * 0);
}

void	handler1(int sigv, siginfo_t *info, void *a)
{
	(void)sigv;
	(void)a;
	from_bits(1, info->si_pid);
}

void	handler(int sigv, siginfo_t *info, void *a)
{
	(void)sigv;
	(void)a;
	from_bits(0, info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;
	struct sigaction	sb;

	sa.sa_sigaction = handler1;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sb.sa_sigaction = handler;
	sb.sa_flags = SA_SIGINFO;
	sigemptyset(&sb.sa_mask);
	ft_printf("Insert %d to the client\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sb, NULL))
		exit(0);
	while ("\(^v^)/")
		usleep(100);
	return (0);
}
