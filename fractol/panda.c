/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:30:31 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/18 16:26:00 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cercle(t_c c, int r, mlx_image_t *img, unsigned int color)
{
	float	i;
	int		x;
	int		y;

	while (r--)
	{
		i = 0;
		while (i < 360)
		{
			x = (r * sin(i)) + c.xc;
			y = (r * cos(i)) + c.yc;
			mlx_put_pixel(img, x, y, color);
			i += 0.01;
		}
	}
}

void	panda(void *p, int y)
{
	t_env	*e;

	(void)y;
	e = p;
	memset(e->img->pixels, 120, e->img->width \
			* e->img->height * sizeof(int32_t));
	e->earr.xc = WIDTH / 2 - 200;
	e->earl.xc = WIDTH / 2 + 200;
	e->eyer.xc = WIDTH / 2 - 150;
	e->eyel.xc = WIDTH / 2 + 150;
	e->face.xc = WIDTH / 2;
	e->nose.xc = WIDTH / 2;
	e->earr.yc = HEIGHT / 2 - 200;
	e->earl.yc = HEIGHT / 2 - 200;
	e->eyer.yc = HEIGHT / 2;
	e->eyel.yc = HEIGHT / 2;
	e->face.yc = HEIGHT / 2;
	e->nose.yc = HEIGHT / 2 + 100;
	cercle(e->earr, 100, e->img, 0x000000FF);
	cercle(e->earl, 100, e->img, 0x000000FF);
	cercle(e->face, 300, e->img, 0xFFFFFFFF);
	cercle(e->eyer, 50, e->img, 0x000000FF);
	cercle(e->eyel, 50, e->img, 0x000000FF);
	cercle(e->nose, 30, e->img, 0x000000FF);
}
