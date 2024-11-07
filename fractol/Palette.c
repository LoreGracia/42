/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:15:30 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/07 19:10:50 by lgracia-         ###   ########.fr       */
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
	if (p  == 0)
		return (0x50EBCEFF); //blue
	if (p == 1)
		return (0xADFFC7FF); //green
	if (p == 2)
		return (0xFFFFFFFF); //white
	if (p == 3)
		return (0xFFC3C2FF); //pink
	return (0xFF6E6BFF); //red
}
