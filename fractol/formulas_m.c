/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas_m.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:58:01 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/17 12:58:17 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	three(float *x, float *y, float x0, float y0)
{
	float			xtmp;

	xtmp = (*x) * (*x) * (*x) - 3 * (*x) * ((*y) * (*y)) + x0;
	*y = 3 * (*x) * (*x) * (*y) - (*y) * (*y) * (*y) + y0;
	*x = xtmp;
}

void	five(float *x, float *y, float x0, float y0)
{
	float			xtmp;

	xtmp = p(*x, 5) - 10 * p(*x, 3) * (*y) * (*y) + 5 * (*x) * p(*y, 4) + x0;
	*y = 5 * p(*x, 4) * (*y) - 10 * (*x) * (*x) * p(*y, 3) + p(*y, 5) + y0;
	*x = xtmp;
}

void	two(float *x, float *y, float x0, float y0)
{
	float			xtmp;

	xtmp = p(*x, 2) - (*y) * (*y) + x0;
	*y = 2 * (*x) * (*y) + y0;
	*x = xtmp;
}

void	n(float *x, float *y, float x0, float y0, float d)
{
	float	i;
	float	xtmp;

	i = d * (float)atan2((double)*y, (double)*x);
	xtmp = p((p(*x, 2) + p(*y, 2)), d / 2) * cos(i) + x0;
	*y = p((p(*x, 2) + p(*y, 2)), d / 2) * sin(i) + y0;
	*x = xtmp;
}
