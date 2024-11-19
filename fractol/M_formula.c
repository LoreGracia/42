/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_formula.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:50:04 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/19 12:00:52 by lgracia-         ###   ########.fr       */
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

void	n0ne(float *x, float *y, t_env *e)
{
	float	d;

	d = p(*x, 2) + p(*y, 2);
	if (d == 0)
		return ;
	*x = (*x) / d + e->x0;
	*y = -(*y) / d + e->y0;
}

void	ntwo(float *x, float *y, t_env *e)
{
	float	d;
	float	xtmp;

	d = p(*x, 4) + 2 * (*x) * (*x) * (*y) * (*y) + p(*y, 4);
	if (d == 0)
		return ;
	xtmp = ((*x) * (*x) - (*y) * (*y)) / d + e->x0;
	*y = -2 * (*x) * (*y) / d + e->y0;
	*x = xtmp;
}

void	m_formula(float *x, float *y, t_env *e)
{
	if (e->d == -2)
		ntwo(x, y, e);
	else if (e->d == -1)
		n0ne(x, y, e);
	else if (e->d == 2)
		two(x, y, e);
	else if (e->d == 3)
		three(x, y, e);
	else if (e->d == 5)
		five(x, y, e);
	else
	{
		n(x, y, e);
	}
}

void	t_esc(float x, float y, t_env *e)
{
	int				i;
	unsigned int	c;

	i = 0;
	e->x0 = x;
	e->y0 = y;
	while (x * x + y * y <= 4 && i < MAX_ITER)
	{
		m_formula(&x, &y, e);
		++i;
	}
	pallete(e);
	c = e->p(i);
	mlx_put_pixel(e->img, e->xo, e->yo, c);
}
