/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:23:53 by lgracia-          #+#    #+#             */
/*   Updated: 2024/12/19 18:40:00 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
int i = -1;

void	from_bits(int c, int a, int b)
{
	static unsigned char	bit;
	static int				count;
	static int				pid;

	if (count < 32)
	{
		pid |= (c << (31 - ++i));
		count += a + b;
		if (i == 31)
			i = -1;
		usleep(200);
	}
	else
	{
		bit |= (c  << (8 - ++i));
		if (i == 7)
		{
			i = -1;
			if (count >= 32)
				ft_printf("%c", bit / 2);
			bit = 0;
		}
		usleep(200);
		kill(pid, SIGUSR1);
	}

}

void	handler1(int count)
{
	count += -count + 1;
	from_bits(1, count, 0);
}

void	handler(int count)
{
	count += -count + 1;
	from_bits(0, 0, count);
}

int main() 
{ 
	ft_printf("Insert %d to the client\n", getpid());
		signal(SIGUSR1, handler1);
		signal(SIGUSR2, handler);
	while ("\(^v^)/")
	{
		pause();
	}
    return 0; 
} 
