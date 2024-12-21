/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:23:53 by lgracia-          #+#    #+#             */
/*   Updated: 2024/12/21 18:02:16 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
int i = -1;

//void	get_pid(int *pid, int *count, int *i);

void	from_bits(int c, int pid)
{
	static int				bit;
	static int				count;
	static int				len;

	usleep(200);
	if (count < 32)
	{
		len |= (c << (31 - ++i));
		count++;
		if (count == 32)
		{
			i = -1;
			len -= '0';
		}
		if (kill(pid, SIGUSR1) == -1)
			exit (ft_printf("Signal mixed\n") * 0);
	}
	else if (len)
	{
		bit |= (c  << (31 - ++i));
		if (i == 31)
		{
			ft_printf("%c", bit);
			len--;
			bit = 0;
			i = -1;
		}
		if (kill(pid, SIGUSR1) == -1)
			exit (ft_printf("Signal mixed\n") * 0);
	}
	else
	{
		count = 0;
		len = 0;
		i = -1;
		from_bits(c, pid);
	}
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

int main() 
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
    return 0; 
} 
