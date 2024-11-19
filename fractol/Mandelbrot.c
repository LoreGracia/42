/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:39:57 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/19 11:21:22 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*float	to_float(int x, int y, mlx_image_t *img, float max)
{
	float i;

	if (x && x != 0)
	{
		i = x * max / (float)img->width;
	//	printf("%d x %f result\n", x, i);
		return (i);
	}
	else if (y && y != 0)
	{
		i = y * max / (float)img->height;
	//	printf("%d y %f y\n", y, i);
		return (i);
	}
	return (0);
}

float	to_floats(int x, int y, mlx_image_t *img)
{
	if (!x && !y)
		return (0);
	else if (x && x != 0)
	{
		if (x < (int)img->width/2)
		{
			return (to_float(x - (int)img->width/2, 0, img, -5.5));
		}
		else if (x > (int)img->width/2)
			return (to_float(x - (int)img->width/2, 0, img, 5.5));
	}
	else if (y && y != 0)
	{
		if (y < (int)img->height/2)
			return (to_float(y - (int)img->height/2, 0, img, -5.5));
		else if (y > (int)img->height/2)
			return (to_float(y - (int)img->height/2, 0, img, 5.5));
	}
	return (0);
}*/

float	to_flo(int val, char c, t_env *e)
{
	if (c == 'x')
		val -= e->cx >> 1;
	else
		val -= e->cy >> 1;
	return (val * (e->px_size));
}

void	mandelbrot(void *p, int y)
{
	int		x;
	size_t	i;
	t_env	*e;

	i = 0;
	e = p;
	x = 0;
	while (x <= (int)e->img->width && y != (int)e->img->height)
	{
		x++;
		e->xo = x;
		e->yo = y;
		t_esc(to_flo(x, 'x', e), to_flo(y, 'y', e), e);
		if (x == (int)e->img->width && y < (int)e->img->height)
		{
			y++;
			x = 0;
		}
		if (x == (int)e->img->width && y == (int)e->img->height)
			break ;
	}
}
