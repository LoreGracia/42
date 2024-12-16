/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:23:53 by lgracia-          #+#    #+#             */
/*   Updated: 2024/12/16 15:40:14 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
int i = -1;

void	from_bits(char c, int a, int b)
{
	static unsigned char	bit;
	static int				count;
	static int				pid;

	bit |= (c - '0') << (7 - ++i);
	if (count <= 55)
	{
		count += a + b;
		if (i == 7)
		{
			pid += bit;
			pid *= 10;
			//ft_printf("count is %d\n", count);
			ft_printf("%d\n", bit);
			ft_printf("this is pid %d\n", pid);
		}
	}
	if (i == 7)
	{
		i = -1;
		if (count > 55)
		{
			ft_printf("%c", bit);
			kill(pid / 100, SIGUSR1);
		}
		bit = 0;
	}
}

void	handler1(int count)
{
	count += -count + 1;
	from_bits('1', count, 0);
}

void	handler(int count)
{
	count += -count + 1;
	from_bits('0', 0, count);
}

int main() 
{ 
	ft_printf("Insert %d to the client\n", getpid());
		signal(SIGUSR1, handler1);
		signal(SIGUSR2, handler);
		signal(SIGUSR1, handler1);
		signal(SIGUSR2, handler);
	while ("\(^v^)/")
	{
		pause();
	}
    return 0; 
} 
