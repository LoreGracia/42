/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:09:35 by lgracia-          #+#    #+#             */
/*   Updated: 2024/12/16 15:40:52 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void handler()
{
	ft_printf("Signal succesfully delivered");
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
		ft_printf("bit is %c\n", bit);
		j = 8;
		while (j--)
		{
			if (bit >> j & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
				ft_printf("envia 1\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
				ft_printf("envia 0\n");
			}
			signal(SIGUSR1, handler);
			//pause();
		}
		i++;
	}
}

void	ibits(int str, int pid)
{
	int		i;
	int		j;
	int		bit;

	i = 0;
	while (str)
	{
		bit = str % 10;
		ft_printf("bit is %d\n", bit);
		j = 8;
		while (j--)
		{
			if (bit >> j & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
				ft_printf("envia 1\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
				ft_printf("envia 0\n");
			}
			usleep(200);
		}
		str /= 10;
	}
}


int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 2)
		return (ft_printf("Please add server pid"));
	if (argc < 3)
		return (ft_printf("Please add message"));
	if (argc > 3)
		return (ft_printf("Too many arguments"));
	pid = ft_atoi(argv[1]);
	ft_printf("my pid is %d", getpid());
	ibits(getpid(), pid);
	to_bits(argv[2], pid);
}
