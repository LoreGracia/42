/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:40:04 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/13 10:11:46 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
/*{
	write(1, &c, 1);
}*/

int	main(int len, char **arg)
{
	int	i;

	if (len < 2)
		return (0);
	i = 1;
	while (i < len)
	{
		while (*arg[i] != '\0')
		{
			ft_putchar(*arg[i]);
			arg[i]++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
