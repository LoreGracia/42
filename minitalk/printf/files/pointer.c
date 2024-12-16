/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:20:27 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/02 13:30:22 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	pointer2(unsigned long d, int *count)
{
	char	*s;
	char	str;

	s = "0123456789abcdef";
	if (d > 15)
		pointer2(d / 16, count);
	str = s[d % 16];
	character(str, count);
	return (*count);
}

int	pointer(unsigned long d, int *count)
{
	if (!d)
		return (string("(nil)", count));
	character('0', count);
	character('x', count);
	pointer2(d, count);
	return (*count);
}
