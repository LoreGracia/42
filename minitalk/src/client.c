/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:09:35 by lgracia-          #+#    #+#             */
/*   Updated: 2024/12/22 16:43:20 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void handler(int sigv, siginfo_t *info, void *a)
{
	(void)sigv;
	(void)a;
	(void)info;
	ft_printf("Signal succesfully delivered\n");
}

int	kill_server(int j, int str, int pid, void *sa)
{
	if (str >> j & 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(1);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
	}
	if (sigaction(SIGUSR1, sa, NULL) != 0)
		exit (0);
	pause();
	return (0);
}

void	ibits(int str, int pid, void *sa)
{
	int		j;
	int		i;

	i = -1;
	j = 32;
	while (j--)
	{
		if (kill_server(j, str, pid, sa) == -1)
			exit(0);
	}
}

void	to_bits(char *str, int pid, void *sa)
{
	int		j;
	int		i;

	i = -1;
	while (str[++i])
	{
		j = 32;
		while (j--)
		{
			if (kill_server(j, str[i], pid, sa) == -1)
				exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (argc < 2)
		return (ft_printf("Please add server pid\n"));
	if (argc < 3)
		return (ft_printf("Please add message\n"));
	if (argc > 3)
		return (ft_printf("Too many arguments\n"));
	ft_printf("%d\n", getpid());
	pid = ft_atoi(argv[1]);
	ibits(ft_strlen(argv[2]), pid, &sa);
	to_bits(argv[2], pid, &sa);
}
