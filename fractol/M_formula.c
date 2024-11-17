/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_formula.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:50:04 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/17 19:46:27 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	p(float val, float pow)
{
	float	i;

	i = val;
	pow -= 1;
	while (pow--)
		i *= val;
	return (i);
}

void	n0ne(float *x, float *y, float x0, float y0)
{
	float	d;

	d = p(*x, 2) + p(*y, 2);
	if (d == 0)
		return ;
	*x = (*x) / d + x0;
	*y = -(*y) / d + y0;
}

void	ntwo(float *x, float *y, float x0, float y0)
{
	float	d;
	float	xtmp;

	d = p(*x, 4) + 2 * (*x) * (*x) * (*y) * (*y) + p(*y, 4);
	if (d == 0)
		return ;
	xtmp = ((*x) * (*x) - (*y) * (*y)) / d + x0;
	*y = -2 * (*x) * (*y) / d + y0;
	*x = xtmp;
}

void	m_formula(float *x, float *y, float d, float x0, float y0)
{
	if (d == -2)
		ntwo(x, y, x0, y0);
	else if (d == -1)
		n0ne(x, y, x0, y0);
	else if (d == 2)
		two(x, y, x0, y0);
	else if (d == 3)
		three(x, y, x0, y0);
	else if (d == 5)
		five(x, y, x0, y0);
	else
	{
		n(x, y, x0, y0, d);
	}
}

void	t_esc(float x, float y, t_env *e)
{
	int				i;
	unsigned int	c;
	float			xo;
	float			yo;

	//printf("%f x %f y\n", x, y);
	i = 0;
	xo = x;
	yo = y;
	while (x * x + y * y <= (2 * 2) && i < MAX_ITER)
	{
		m_formula(&x, &y, e->d, xo, yo);
		i += 1;
	}
	if (i == MAX_ITER)
		c = 0x000000FF;
	else
		c = melon(i);
	mlx_put_pixel(e->img, f_flo(xo, e->px_size, e->img), f_flo(yo, e->px_size, e->img), c);
	printf("%f x %f y\n", f_flo(xo, e->px_size, e->img), f_flo(yo, e->px_size, e->img));
}
