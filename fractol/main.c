/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:20:09 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/08 20:01:43 by lgracia-         ###   ########.fr       */
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

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	mlx_t* a;
	a = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		//mlx_close_callback();
//		mlx_close_window(param);
		exit (0);
	}
}

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
float	to_flo(int val, float *px_size)
{
	val -= WIDTH/2;
	return (val * (*px_size));
}

void	mandelbrot_t(mlx_image_t *img, int y, int d, float* px_size)
{
	int		x;
	size_t	i;

	x = 0;
	i = 0;
	while (x <= (int)img->width && y != (int)img->height)
	{
		x++;
	//	mlx_put_pixel(img, x, y, color);
//		printf("%d x %d y\n", x, y);
		t_esc(to_flo(x, px_size), x, to_flo(y, px_size), y, img);
		if (x == (int)img->width && y < (int)img->height)
			mandelbrot_t(img, y+1, d, px_size);
		if (x == (int)img->width && y == (int)img->height)
			break ;
	}
}

void my_scrollhook(double xdelta, double ydelta, void* px_size)
{
	//(void)px_size;
	// Simple up or down detection.
	if (ydelta > 0)
		*((float*)px_size) += 0.05;
	//	puts("Up!");
	else if (ydelta < 0)
		*((float*)px_size) -= 0.05;
	//	puts("Down!");
	
	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

int	fractol(int argc, char **argv)
{
	mlx_t* mlx;
	mlx_image_t* img;
	float	px_size;

	px_size = PX_SIZE;
	if (argc < 2 || argv[3])
		return (0);
	mlx = mlx_init(WIDTH, HEIGHT, "Fractal", false);
	if (!mlx)
		return (0);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (0);
	//memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	if (argv[1][0] == 'm')
	{
		//memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
		mandelbrot_t(img, 0, ft_atoi(argv[2]), &px_size);
		if (mlx_image_to_window(mlx, img, 0, 0) < 0)
			return (0);
	}
	else if (argv[1][0] == 'j')
	{
		//	else
		//		julia_t(img, 0, ft_atoi(argv[2]));
		if (mlx_image_to_window(mlx, img, 0, 0) < 0)
			return (0);
	}
	mlx_scroll_hook(mlx, &my_scrollhook, &px_size);
	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	int f;

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
			f = fractol(argc, argv);
			if (f == 0)
				return (0);
		}	
	}
	if (argv[1][0] == 'p')
		panda();
	else if (argv[1][0] == 'l')
		line();
}
