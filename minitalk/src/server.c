/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:23:53 by lgracia-          #+#    #+#             */
/*   Updated: 2024/12/22 17:26:40 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int i = -1;

void	from_bits(int a, int pid)
{
	static int				bit;
	static int				count;
	static unsigned int		len;

	usleep(200);
	if (count < 32)
	{
		len |= (a << (31 - ++i));
		count++;
		if (count == 32)
		{
			i = -1;
		}
	}
	else if (count >= 32 && len)
	{
		bit |= (a << (31 - ++i));
		if (i == 31)
		{
			ft_printf("%c", bit);
			len--;
			bit = 0;
			i = -1;
		}
	}
	else
	{
		count = 0;
		len = 0;
		i = -1;
		from_bits(a, pid);
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

int	main() 
{
	struct	sigaction	sa;
	struct	sigaction	sb;

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
		pause();
		//sleep(1);
    return 0; 
} 
