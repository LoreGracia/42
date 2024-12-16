/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:10:30 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/02 13:54:26 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	format(char f, va_list arg, int *count)
{
	if (f == 'c')
		character(va_arg(arg, int), count);
	else if (f == 's')
		string(va_arg(arg, char *), count);
	else if (f == 'p')
		pointer(va_arg(arg, unsigned long int), count);
	else if (f == 'd' || f == 'i')
		decimal(va_arg(arg, int), count);
	else if (f == 'u')
		unsigne(va_arg(arg, unsigned int), count);
	else if (f == 'x')
		hexlow(va_arg(arg, int), count);
	else if (f == 'X')
		hexup(va_arg(arg, int), count);
	else if (f == '%')
		character('%', count);
	return (*count);
}
