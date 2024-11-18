/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas_m.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:58:01 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/18 11:49:58 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	three(float *x, float *y, t_env *e)
{
	float			xtmp;

	xtmp = (*x) * (*x) * (*x) - 3 * (*x) * ((*y) * (*y)) + e->x0;
	*y = 3 * (*x) * (*x) * (*y) - (*y) * (*y) * (*y) + e->y0;
	*x = xtmp;
}

void	five(float *x, float *y, t_env *e)
{
	float			xtmp;

	xtmp = p(*x, 5) - 10 * p(*x, 3) * (*y) * (*y) + 5 * (*x) * p(*y, 4) + e->x0;
	*y = 5 * p(*x, 4) * (*y) - 10 * (*x) * (*x) * p(*y, 3) + p(*y, 5) + e->y0;
	*x = xtmp;
}

void	two(float *x, float *y, t_env *e)
{
	float			xtmp;

	xtmp = p(*x, 2) - (*y) * (*y) + e->x0;
	*y = 2 * (*x) * (*y) + e->y0;
	*x = xtmp;
}

void	n(float *x, float *y, t_env *e)
{
	float	i;
	float	xtmp;

	i = e->d * (float)atan2((double)*y, (double)*x);
	xtmp = p((p(*x, 2) + p(*y, 2)), e->d / 2) * cos(i) + e->x0;
	*y = p((p(*x, 2) + p(*y, 2)), e->d / 2) * sin(i) + e->y0;
	*x = xtmp;
}
