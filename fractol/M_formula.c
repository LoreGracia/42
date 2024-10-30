/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_formula.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:50:04 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/30 19:08:59 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	nTwo(int *x, int *y, int *xtmp, int x0, int y0)
{
	*xtmp = (*x)*2 + (*y)^2 + x0;
	*y = 2*(*x)*(*y) + y0;
	*x = *xtmp;
}

void	nOne(int *x, int *y, int *xtmp, int x0, int y0)
{
	*xtmp = (*x)*2 + (*y)^2 + x0;
	*y = 2*(*x)*(*y) + y0;
	*x = *xtmp;
}

void	one(int *x, int *y, int *xtmp, int x0, int y0)
{
	*xtmp = (*x)*2 + (*y)^2 + x0;
	*y = 2*(*x)*(*y) + y0;
	*x = *xtmp;
}


void	two(int *x, int *y, int *xtmp, int x0, int y0)
{
	*xtmp = (*x)*2 + (*y)^2 + x0;
	*y = 2*(*x)*(*y) + y0;
	*x = *xtmp;
}

void	five(int *x, int *y, int *xtmp, int x0, int y0)
{

	*xtmp = (*x)*2 + (*y)^2 + x0;
	*y = 2*(*x)*(*y) + y0;
	*x = *xtmp;
}

void	M_formula(int *x, int *y, int *xtmp, int d, int x0, int y0)
{
	if (d == -2)
		nTwo(x, y, xtmp, x0, y0);
	else if (d == -1)
		nOne(x, y, xtmp, x0, y0);
	else if (d == 1) 
		one(x, y, xtmp, x0, y0);
	if (d == 2)
		two(x, y, xtmp, x0, y0);
	else if (d == 5)
		five(x, y, xtmp, x0, y0);
}

void	t_esc(int x, int y, mlx_image_t *img, int d)
{
	int i;
	int max;
	unsigned int color;
	int x0;
	int y0;
	int	xtmp;

	i = 0;
	max = 1000;
	x0 = x;
	y0 = y;
//	printf("0\n");
	while (x*x + y*y <= (2*2) && i < max)
	{
		M_formula(&x, &y, &xtmp, d, x0, y0);
		i += 1;
	}
//	printf("1\n");
	if (i == max)
		color = 0x000000FF;
	else
		color = melon(i, max);
	//printf("%x\n", color);
	printf("i %d x %d y %d color %x\n", i, x0, y0, color);
	mlx_put_pixel(img, x0, y0, color);
}
