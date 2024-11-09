/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:30:31 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/09 21:29:54 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int main(void)
{
	void	*mlx;
	mlx_image_t* img;

	mlx = mlx_init(WIDTH, HEIGHT, "HELLO", false);
	if (!mlx)
		return (0);
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (0);
	mlx_put_pixel(img, 0,0, 0xFF0000FF);
	mlx_put_pixel(img, 10, 10, 0xFF0000FF);
	mlx_loop(mlx);
}*/

static void ft_hook(mlx_key_data_t keydata, void* param)
{
	mlx_t *a;
	a = param;
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Panda ");

	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("lazyyyyyyyyy");

	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("y");
}

void	cercle(int cx, int cy, int r, mlx_image_t* img, unsigned int color)
{
	float	i;
	int	x;
	int	y;

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

void my_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x -= 5;
}

int panda()
{
	mlx_t* mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "Test", false);
	if (!mlx)
        return (0);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
        return (0);
	memset(img->pixels, 120, img->width * img->height * sizeof(int32_t));
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        return (0);
	cercle(WIDTH/2 - 200, HEIGHT/2 - 200, 100, img, 0x000000FF);
	cercle(WIDTH/2 + 200, HEIGHT/2 - 200, 100, img, 0x000000FF);
	cercle(WIDTH/2, HEIGHT/2, 300, img, 0xFFFFFFFF);
	cercle(WIDTH/2 - 150, HEIGHT/2, 50, img, 0x000000FF);
	cercle(WIDTH/2 + 150, HEIGHT/2, 50, img, 0x000000FF);
	cercle(WIDTH/2, HEIGHT/2 + 100, 30, img, 0x000000FF);
	mlx_key_hook(mlx, &ft_hook, NULL);
	mlx_loop_hook(mlx, my_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}
