/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:23:32 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/22 11:23:05 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	blanks(const char i)
{
	if (i == ' ' || i == '\r' || i == '\n')
		return (0);
	if (i == '\t' || i == '\v' || i == '\f')
		return (0);
	return (1);
}

long	ft_atol(const char *nptr)
{
	long int	i;
	long int	ptr;
	int			sign;

	i = 0;
	ptr = 0;
	sign = 1;
	while (blanks(nptr[i]) == 0)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
		if (nptr[i] == ' ')
			exit(write(1, "ERROR\n", 6) * 0);
	}
	while (nptr[i] && ft_isdigit(nptr[i]) > 0)
	{
		ptr = nptr[i] - '0' + (10 * ptr);
		i++;
	}
	ptr *= sign;
	return (ptr);
}
/*:
#include <stdio.h>

int	main()
{
	printf("%ld\n", ft_atoi("\n\t\r123456789112"));
}*/
