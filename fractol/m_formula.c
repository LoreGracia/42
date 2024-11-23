/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_formula.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:50:04 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/21 19:24:12 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	p(double val, double pow)
{
	double	i;

	i = val;
	pow -= 1;
	while (pow--)
		i *= val;
	return (i);
}

void	n0ne(double *x, double *y, t_env *e)
{
	double	d;

	d = p(*x, 2) + p(*y, 2);
	if (d == 0)
		return ;
	*x = (*x) / d + e->x0;
	*y = -(*y) / d + e->y0;
}

void	ntwo(double *x, double *y, t_env *e)
{
	double	d;
	double	xtmp;

	d = p(*x, 4) + 2 * (*x) * (*x) * (*y) * (*y) + p(*y, 4);
	if (d == 0)
		return ;
	xtmp = ((*x) * (*x) - (*y) * (*y)) / d + e->x0;
	*y = -2 * (*x) * (*y) / d + e->y0;
	*x = xtmp;
}

void	m_formula(double *x, double *y, t_env *e)
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

void	t_esc(double x, double y, t_env *e)
{
	int				i;
	unsigned int	c;

	i = 0;
	if (e->type == 'm')
	{
		e->x0 = x;
		e->y0 = y;
	}
	while (x * x + y * y <= 4 && i < MAX_ITER)
	{
		m_formula(&x, &y, e);
		++i;
	}
	pallete(e);
	c = e->p(i);
	mlx_put_pixel(e->img, e->xo, e->yo, c);
}
