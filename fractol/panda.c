/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:30:31 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/17 15:28:22 by lgracia-         ###   ########.fr       */
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

void	panda(mlx_image_t *img, int x, int y, float px_size)
{
	(void)x;
	(void)y;
	(void)px_size;
	(void)img;
	memset(img->pixels, 120, img->width * img->height * sizeof(int32_t));
	cercle(WIDTH / 2 - 200, HEIGHT / 2 - 200, 100, img, 0x000000FF);
	cercle(WIDTH / 2 + 200, HEIGHT / 2 - 200, 100, img, 0x000000FF);
	cercle(WIDTH / 2, HEIGHT / 2, 300, img, 0xFFFFFFFF);
	cercle(WIDTH / 2 - 150, HEIGHT / 2, 50, img, 0x000000FF);
	cercle(WIDTH / 2 + 150, HEIGHT / 2, 50, img, 0x000000FF);
	cercle(WIDTH / 2, HEIGHT / 2 + 100, 30, img, 0x000000FF);
}
