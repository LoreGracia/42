/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:39:57 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/28 16:09:56 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*double	to_double(int x, int y, mlx_image_t *img, double max)
{
	double i;

	if (x && x != 0)
	{
		i = x * max / (double)img->width;
	//	printf("%d x %f result\n", x, i);
		return (i);
	}
	else if (y && y != 0)
	{
		i = y * max / (double)img->height;
	//	printf("%d y %f y\n", y, i);
		return (i);
	}
	return (0);
}

double	to_doubles(int x, int y, mlx_image_t *img)
{
	if (!x && !y)
		return (0);
	else if (x && x != 0)
	{
		if (x < (int)img->width/2)
		{
			return (to_double(x - (int)img->width/2, 0, img, -5.5));
		}
		else if (x > (int)img->width/2)
			return (to_double(x - (int)img->width/2, 0, img, 5.5));
	}
	else if (y && y != 0)
	{
		if (y < (int)img->height/2)
			return (to_double(y - (int)img->height/2, 0, img, -5.5));
		else if (y > (int)img->height/2)
			return (to_double(y - (int)img->height/2, 0, img, 5.5));
	}
	return (0);
}*/

double	to_flo(int val, char c, t_env *e)
{
	if (c == 'x')
		val -= e->cx >> 1;
	else
		val -= e->cy >> 1;
	return (val * (e->px_size));
}

int	from_flo(double val, char c, t_env *e)
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
	x = -1;
	while (x < (int)e->img->width && y != (int)e->img->height)
	{
		x++;
		e->xo = x;
		e->yo = y;
		t_esc(to_flo(x, 'x', e), to_flo(y, 'y', e), e);
		if (x == (int)e->img->width && y < (int)e->img->height)
		{
			y++;
			x = -1;
		}
		if (x == (int)e->img->width && y == (int)e->img->height)
			break ;
	}
}

/*void	mandelbrot(void *p, int y)
{
	int		x;
	size_t	i;
	t_env	*e;

	i = 0;
	e = p;
	while (y < (int)e->img->width)
	{
		x = 0;
		while (x < (int)e->img->width)
		{
			e->xo = x;
			e->yo = y;
			t_esc(to_flo(x, 'x', e), to_flo(y, 'y', e), e);
			x++;
		}
		y++;
	}
}*/
