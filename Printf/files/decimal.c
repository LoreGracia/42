/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:13:18 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/02 13:44:10 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	decimal(int d, int *count)
{
	char	c;

	if (d == -2147483648)
		return (string("-2147483648", count));
	if (d < 0)
	{
		character('-', count);
		d *= -1;
	}
	if (d > 9)
		decimal(d / 10, count);
	c = d % 10 + '0';
	character(c, count);
	return (*count);
}
