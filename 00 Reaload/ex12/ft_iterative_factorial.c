/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:15:39 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/10 18:45:07 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	if (nb == 0)
		return (1);
	if (nb > 0 && nb <= 12)
	{
		while (i <= nb)
		{
			result = result * i;
			i++;
		}
		return (result);
	}
	else
		return (0);
}
/*
#include <stdio.h>

int main()
{
	printf("%d\n", ft_iterative_factorial(-100));
	printf("%d\n", ft_iterative_factorial(32));
	printf("%d\n", ft_iterative_factorial(-0));
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(1));
	printf("%d\n", ft_iterative_factorial(-2));
	printf("%d\n", ft_iterative_factorial(12));
}*/
