/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:15:30 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/06 12:30:24 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	melon(int i)
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
}

/*unsigned int	melon(int i, int max)
{
	int p;

	p = i * 1000 / max;
	printf("%d %d\n", i, p);
	if (p < 20)
		return (0x50EBCEFF); //blue
	else if (p < 40 && p > 20)
		return (0xADFFC7FF); //green
	else if (p < 60 && p > 40)
		return (0xFFFFFFFF); //white
	else if (p < 80 && p > 60)
		return (0xFFC3C2FF); //pink
	else if (p < 100 && p > 80)
		return (0xFF6E6BFF); //red
	else
		return (0xFFFFFFFF);
}*/
