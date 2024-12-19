/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:09:35 by lgracia-          #+#    #+#             */
/*   Updated: 2024/12/19 18:40:16 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void handler()
{
	ft_printf("Signal succesfully delivered\n");
}

void	to_bits(char *str, int pid)
{
	int		i;
	int		j;
	int		bit;

	i = 0;
	while (str[i])
	{
		bit = str[i];
		j = 8;
		while (j--)
		{
			if (bit >> j & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			ft_printf("EA");
			signal(SIGUSR1, handler);
			pause();
		}
		i++;
	}
}

void	ibits(int str, int pid)
{
	int		j;

	j = 32;
	while (j--)
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
		usleep(2000);
	}
}


int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 2)
		return (ft_printf("Please add server pid\n"));
	if (argc < 3)
		return (ft_printf("Please add message\n"));
	if (argc > 3)
		return (ft_printf("Too many arguments\n"));
	pid = ft_atoi(argv[1]);
	ibits(getpid(), pid);
	to_bits(argv[2], pid);
}
