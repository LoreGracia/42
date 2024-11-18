/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:15:30 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/18 18:27:49 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pallete(void *param)
{
	t_env *e;
	e = param;

	if (e->c == 0)
		e->p = melon;
	if (e->c == 1)
		e->p = grey;
	if (e->c == 2)
		e->p = mas;
}

unsigned int	melon(int p)
{
	if (p == 0)
		return (0x50EBCEFF);
	if (p == 1)
		return (0xADFFC7FF);
	if (p == 2)
		return (0xFFFFFFFF);
	if (p > 2 && p < MAX_ITER)
		return (0xFFC3C2FF);
	return (0xFF6E6BFF);
}

unsigned int	grey(int p)
{
	if (p < MAX_ITER)
		return (0x000000FF - (p*100));
	return (0xFFFFFFFF);
}

unsigned int	mas(int p)
{
	if (p == 0)
		return (0xFFFFFFFF);
	if (p == 1)
		return (0x50EBCEFF);
	if (p == 2)
		return (0xADFFC7FF);
	if (p == 3)
		return (0xFFFFFFFF);
	if (p > 3 && p < MAX_ITER)
		return (0xFFC3C2FF);
	return (0xFF6E6BFF);
}
