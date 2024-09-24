/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:16:01 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/02 14:03:06 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexup(unsigned int d, int *count)
{
	char	*s;
	char	str;

	s = "0123456789ABCDEF";
	if (d > 15)
		hexup(d / 16, count);
	str = s[d % 16];
	character(str, count);
	return (*count);
}
