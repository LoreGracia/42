/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigne.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:14:59 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/02 10:27:38 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	unsigne(unsigned int d, int *count)
{
	char	c;

	if (d > 9)
		decimal(d / 10, count);
	c = d % 10 + '0';
	character(c, count);
	return (*count);
}
