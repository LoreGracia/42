/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:20:09 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/01 12:26:35 by lgracia-         ###   ########.fr       */
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

int panda()
{
	mlx_t* mlx;
	mlx_image_t* img;
	mlx = mlx_init(WIDTH, HEIGHT, "Test", false);
	if (!mlx)
        return (0);
	img = mlx_new_image(mlx, 812, 812);
	if (!img)
        return (0);
	memset(img->pixels, 120, img->width * img->height * sizeof(int32_t));
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        return (0);
	cercle(WIDTH/2 - 200, WIDTH/2 - 200, 100, img, 0x000000FF);
	cercle(WIDTH/2 + 200, WIDTH/2 - 200, 100, img, 0x000000FF);
	cercle(WIDTH/2, WIDTH/2, 300, img, 0xFFFFFFFF);
	cercle(WIDTH/2 - 150, WIDTH/2, 50, img, 0x000000FF);
	cercle(WIDTH/2 + 150, WIDTH/2, 50, img, 0x000000FF);
	cercle(WIDTH/2, WIDTH/2 + 100, 30, img, 0x000000FF);
	mlx_key_hook(mlx, &ft_hook, NULL);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}

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

float	to_float(int x, int y, mlx_image_t *img)
{
	int	max;
	float i;

	max = 2;
	if (!x && !y)
		return (0);
	if (x)
	{
		i = x * max / img->width;
		printf("%d x %d max %d width %f result\n",x, max, img->width, i);
		return (i);
	}
	else if (y)
	{
		i = y * max / img->height;
		printf("%d y %d max %d height %f y\n", y, max, img->height, i);
		return (i);
	}
	return (0);
}

void	mandelbrot_t(mlx_image_t *img, int y, int d)
{
	int x;
	size_t	i;

	x = 0;
	i = 0;
	while (x <= (int)img->width && y != (int)img->height)
	{
		x++;
	//	mlx_put_pixel(img, x, y, color);
		t_esc(to_float(x, 0, img), x, to_float(0, y, img), y, img, d);
		if (x == (int)img->width && y < (int)img->height)
			mandelbrot_t(img, y+1, d);
		if (x == (int)img->width && y == (int)img->height)
			break ;
	}
}

int	fractol(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	mlx_t* mlx;
	mlx_image_t* img;
	mlx = mlx_init(WIDTH, HEIGHT, "Test", false);
	if (!mlx)
		return (0);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (0);
	if (argv[1][0] == 'm')
			mandelbrot_t(img, 0, ft_atoi(argv[2]));
	else if (argv[1][0] == 'j')
	{
		//	else
		//		julia_t(img, 0, ft_atoi(argv[2]));
	}
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	int i;

	if (argc < 2)
		return (0);
	if (argv[1][0] == 'm' || argv[1][0] == 'j')
	{
		if (!argv[2] && argv[1][0] == 'm')
			return (write(2, "Try './fractol m 2'", 20), 0); 
		else if (!argv[2] && argv[1][0] == 'p')
			return (write(2, "Try './fractol j 2'", 20), 0); 
		if (argc > 2)
		{
			i = fractol(argc, argv);
			if (i == 0)
				return (0);
		}	
	}
	if (argv[1][0] == 'p')
		panda();
	else if (argv[1][0] == 'l')
		line();
}
