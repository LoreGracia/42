/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_formula.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:50:04 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/09 17:00:21 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_pow(float val, float pow)
{
	float	i;

	i = val;
	pow -= 1;
	while (pow--)
		i *= val;
	return (i);
}

void	nOne(float *x, float *y, float *xtmp, float x0, float y0)
{
	float	d;

	d = ft_pow(*x, 2) + ft_pow(*y, 2);
	if (d == 0)
		return ;
	*xtmp = (*x)/d + x0;
	*y = -(*y)/d + y0;
}

void	nTwo(float *x, float *y, float *xtmp, float x0, float y0)
{
	float d;

	d = ft_pow(*x, 4) + 2 * (*x)*(*x) * (*y)*(*y) + ft_pow(*y, 4);
	if (d == 0)
		return ;
	*xtmp = ((*x)*(*x) + (*y)*(*y)) / d + x0;
	*y = -2*(*x)*(*y) / d + y0;
	*x = *xtmp;
}

void	three(float *x, float *y, float *xtmp, float x0, float y0)
{
	*xtmp = (*x)*(*x)*(*x) - 3 *(*x)*((*y)*(*y)) + x0;
	*y = 3*(*x)*(*x)*(*y)-(*y)*(*y)*(*y) + y0;
	*x = *xtmp;
}

void	five(float *x, float *y, float *xtmp, float x0, float y0)
{
	*xtmp = ft_pow(*x, 5)-10*ft_pow(*x, 3)*(*y)*(*y)+5*(*x)*ft_pow(*y, 4)+x0;
	*y =  5 *ft_pow(*x, 4)*(*y)-10*(*x)*(*x)*ft_pow(*y, 3)+ft_pow(*y, 5)+y0;
	*x = *xtmp;

}

void	two(float *x, float *y, float *xtmp, float x0, float y0)
{
	*xtmp = ft_pow(*x, 2) - (*y)*(*y) + x0;
	*y = 2*(*x)*(*y) + y0;
	*x = *xtmp;
}

void	n(float *x, float *y, float *xtmp, float x0, float y0, int d)
{
	float	i;

	i = (float)d*(float)atan2((double)*y,(double)*x);
	*xtmp = ft_pow((ft_pow(*x, 2) + ft_pow(*x, 2)), (float)d/2)*cos(i) + x0;
	*y = ft_pow((ft_pow(*x, 2) + ft_pow(*x, 2)), (float)d/2)*sin(i) + y0;
	*x = *xtmp;
}


void	M_formula(float *x, float *y, float *xtmp, float d, float x0, float y0)
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
	else
		n(x, y, xtmp, x0, y0, d);
}

void	t_esc(float x, int x0, float y, int y0, mlx_image_t *img, int d)
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
		/*xtmp = (x)*(x) - (y)*(y) + xo;
		y = 2*(x)*(y) + yo;
		x = xtmp;*/
		M_formula(&x, &y, &xtmp, d, xo, yo);
		i += 1;
	}
	if (i == MAX_ITER)
		color = 0x000000FF;
	else
		color = melon(i);
//	printf("i %d x %d y %d color %x\n", i, x0, y0, color);
	mlx_put_pixel(img, x0, y0, color);
}
