/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:10:08 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/07 19:04:32 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	arg;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count = format(s[++i], arg, &count);
			if (s[i] != '\0')
				i++;
		}
		else
		{
			count = character(s[i], &count);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	char	*s = NULL;
	ft_printf("%d\nFT |\n\n", ft_printf("\n%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n",\
	'a', s, s, 32, 64, 264, INT_MIN, -10));
	printf("%d\nPRINTF |\n\n", printf("\n%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n", \
	'a', s, s, 32, 64, 264, INT_MIN, -10));
}*/
