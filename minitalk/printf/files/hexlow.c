/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexlow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:15:25 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/02 14:24:18 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlow(unsigned int d, int *count)
{
	char	*s;
	char	str;

	s = "0123456789abcdef";
	if (d > 15)
		hexlow(d / 16, count);
	str = s[d % 16];
	character(str, count);
	return (*count);
}
