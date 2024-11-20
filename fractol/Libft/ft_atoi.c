/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:23:32 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/20 18:40:36 by lgracia-         ###   ########.fr       */
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

static void	parse_atoi(int *i, const char *nptr, float *f, int *sign)
{
	while (blanks(nptr[*i]) == 0)
		*i += 1;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i++] == '-')
			*sign *= -1;
	}
	if (ft_strchr(nptr, '.') != 0)
	{
		*f = 0.1;
		*i += 2;
	}
}

float	ft_atod(const char *nptr)
{
	int		i;
	float	ptr;
	int		sign;
	float	f;
	int		dlen;

	i = 0;
	ptr = 0;
	sign = 1;
	f = 0;
	parse_atoi(&i, nptr, &f, &sign);
	dlen = i;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		ptr = nptr[i] - '0' + (10 * ptr);
		i++;
	}
	dlen = i - dlen;
	ptr *= sign;
	while (f && dlen--)
		ptr = (ptr * f);
	return (ptr);
}

float	ft_atoi(const char *nptr)
{
	int		i;
	float	ptr;
	int		sign;
	float	o;

	i = 0;
	ptr = 0;
	sign = 1;
	o = 0;
	if (ft_strchr(nptr, '.') != 0)
		o = ft_atod(nptr);
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		ptr = nptr[i] - '0' + (10 * ptr);
		i++;
	}
	ptr *= sign;
	ptr += o;
	return (ptr);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_atoi("\n\t\r-123-45678"));
}*/
