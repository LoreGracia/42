/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:26:56 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/10 18:50:00 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0)
		return (1);
	return (ft_recursive_factorial(nb - 1) * nb);
}
/*
#include <stdio.h>

int	main()
{
	printf ("%d\n", ft_recursive_factorial(12));
	printf ("%d\n", ft_recursive_factorial(5));
	printf ("%d\n", ft_recursive_factorial(32));
	printf ("%d\n", ft_recursive_factorial(-5));
	printf ("%d\n", ft_recursive_factorial(0));
}*/
