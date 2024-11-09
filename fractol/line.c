/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:54:46 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/09 16:54:59 by lgracia-         ###   ########.fr       */
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

int	line()
{
	int i;
	mlx_t* mlx;
	mlx_image_t* img;

	mlx = mlx_init(WIDTH, HEIGHT, "Test", false);
	if (!mlx)
		return (0);
	img = mlx_new_image(mlx, 400, 300);
	if (!img)
		return (0);
	memset(img->pixels, 120, img->width * img->height * sizeof(int32_t));
	screen(img, 120, 0x50EBCEFF);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (0);
	i = 0;
	while (i++ < 100)
		mlx_put_pixel(img, 100 + i, 100, 0xFFFFF);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}

