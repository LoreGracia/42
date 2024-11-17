/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:15:30 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/17 15:24:48 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*unsigned int	melon(int i)
{
	if (i == 0)
		return (0x50EBCEFF); //blue
	else if (i == 1)
		return (0xADFFC7FF); //green
	else if (i == 2)
		return (0xFFFFFFFF); //white
	else if (i == 3)
		return (0xFFC3C2FF); //pink
	else if (i > 3)
		return (0xFF6E6BFF); //red
	else
		return (0xFFFFFFFF);
}*/

unsigned int	melon(int p)
{
	if (p == 0)
		return (0x50EBCEFF);
	if (p == 1)
		return (0xADFFC7FF);
	if (p == 2)
		return (0xFFFFFFFF);
	if (p == 3)
		return (0xFFC3C2FF);
	return (0xFF6E6BFF);
}
