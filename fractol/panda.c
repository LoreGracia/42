/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:30:31 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/17 17:36:17 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cercle(int cx, int cy, int r, mlx_image_t *img, unsigned int color)
{
	float	i;
	int		x;
	int		y;

	while (r--)
	{
		i = 0;
		while (i < 360)
		{
			x = (r * sin(i)) + cx;
			y = (r * cos(i)) + cy;
			mlx_put_pixel(img, x, y, color);
			i += 0.01;
		}
	}
}

void	panda(void *p, int y)
{
	t_env *e;

	(void)y;
	e = p;
	memset(e->img->pixels, 120, e->img->width * e->img->height * sizeof(int32_t));
	cercle(WIDTH / 2 - 200, HEIGHT / 2 - 200, 100, e->img, 0x000000FF);
	cercle(WIDTH / 2 + 200, HEIGHT / 2 - 200, 100, e->img, 0x000000FF);
	cercle(WIDTH / 2, HEIGHT / 2, 300, e->img, 0xFFFFFFFF);
	cercle(WIDTH / 2 - 150, HEIGHT / 2, 50, e->img, 0x000000FF);
	cercle(WIDTH / 2 + 150, HEIGHT / 2, 50, e->img, 0x000000FF);
	cercle(WIDTH / 2, HEIGHT / 2 + 100, 30, e->img, 0x000000FF);
}
