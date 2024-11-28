/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:15:30 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/28 11:15:07 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pallete(void *param)
{
	t_env	*e;

	e = param;
	if (e->c == 1)
	{
		e->p = melon;
		printf("melon\n");
	}
	if (e->c == 0)
	{
		e->p = grey;
		printf("grey\n");
	}
	if (e->c == 2)
	{
		e->p = grass;
		printf("grass\n");
	}
	if (e->c == 3)
	{
		e->p = grade;
		printf("grade");
	}
}

unsigned int	grass(int p)
{
	if (p == 0)
		return (0x042940FF);
	if (p == 1)
		return (0x005C53FF);
	if (p == 2)
		return (0x9FC131FF);
	if (p == 3)
		return (0xDBF227FF);
	if (p > 3 && p < MAX_ITER)
		return (0xDBF227FF + (p * 100));
	return (0x042940FF);
}

unsigned int	grey(int p)
{
	if (p < MAX_ITER)
		return ((0x000000ff - (p * 100)));
	return (0xFFFFFFFF);
}

unsigned int	grade(int p)
{
	if (p < MAX_ITER)
		return ((0xDBF227FF * (p / 2)));
	return (0x042940FF);
}

unsigned int	melon(int p)
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
		return (0xFFC3C2FF * (p / 4));
	return (0xFF6E6BFF);
}
