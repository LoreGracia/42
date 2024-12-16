/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:12:51 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/06 11:04:20 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	string(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
		return (string("(null)", count));
	while (s[i] != '\0')
	{
		character(s[i], count);
		i++;
	}
	return (*count);
}
