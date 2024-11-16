/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:54:46 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/16 16:18:18 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	screen(mlx_image_t *img, int y, unsigned int color)
{
	int x;
	size_t	i;

	x = 0;
	i = 0;
	while (x <= (int)img->width && y != (int)img->height)
	{
		x++;
		mlx_put_pixel(img, x, y, color);
		if (x == (int)img->width && y < (int)img->height)
			screen(img, y+1, color);
		if (x == (int)img->width && y == (int)img->height)
			break ;
	}
}

void	line(mlx_image_t* img, int x, int y, float px_size)
{
	(void)x;
	(void)y;
	(void)px_size;
	(void)img;
	int i;
	memset(img->pixels, 120, img->width * img->height * sizeof(int32_t));
	screen(img, 120, 0x50EBCEFF);
	i = 0;
	while (i++ < 100)
		mlx_put_pixel(img, 100 + i, 100, 0xFFFFF);
}

