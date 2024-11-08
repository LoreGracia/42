/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_formula.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:50:04 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/08 19:20:39 by lgracia-         ###   ########.fr       */
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

void	two(int *x, int *y, int *xtmp, int x0, int y0)
{
	*xtmp = (*x)^2 - (*y)^2 + x0;
	*y = 2*(*x)*(*y) + y0;
	*x = *xtmp;
}

void	three(int *x, int *y, int *xtmp, int x0, int y0)
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
	else if (d == 2)
		two(x, y, xtmp, x0, y0);
	else if (d == 3)
		three(x, y, xtmp, x0, y0);
	else if (d == 5)
		five(x, y, xtmp, x0, y0);
}

void	t_esc(float x, int x0, float y, int y0, mlx_image_t *img)
{
	int				i;
	unsigned int	color;
	float			xtmp;
	float			xo;
	float			yo;

	i = 0;
//	printf("%d x0 %d y0 %f x %f y\n", x0, y0, x, y);
	xo = x;
	yo = y;
	while (x*x + y*y <= (2*2) && i < MAX_ITER)
	{	
		xtmp = (x)*(x) - (y)*(y) + xo;
		y = 2*(x)*(y) + yo;
		x = xtmp;
	//	M_formula(&x, &y, &xtmp, d, x0, y0);
		i += 1;
	}
	if (i == MAX_ITER)
		color = 0x000000FF;
	else
		color = melon(i);
//	printf("i %d x %d y %d color %x\n", i, x0, y0, color);
	mlx_put_pixel(img, x0, y0, color);
}
