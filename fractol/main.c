/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:20:09 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/11 17:46:44 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_hook_esc_arrows(void* param)
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

float	to_flo(int val, float *px_size, mlx_image_t *img)
{
	val -= img->width/2;
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
		t_esc(to_flo(x, px_size, img), x, to_flo(y, px_size, img), y, img, d);
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
	{
		*((float*)px_size) += 0.05;
	//	mlx_close_window(mlx);
	//	ft_printf("%d\n", mlx_strerror(mlx_errno));
	//	return(-1);
	}
	//	puts("Up!");
	else if (ydelta < 0)
	{
		*((float*)px_size) -= 0.05;
	//	mlx_close_window(mlx);
	//	ft_printf("%d\n", mlx_strerror(mlx_errno));
	//	return(-1);
	}
	//	puts("Down!");
	
	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

void ft_scrollhook(double xdelta, double ydelta, void* mlx)
{
	//(void)px_size;
	// Simple up or down detection.
	if (ydelta > 0)
	{
		if (mlx_image_to_window(mlx, img, 0, 0) == -1)
		{
			mlx_delete_image(mlx, img);
			mlx_close_window(mlx);
			ft_printf("%d\n", mlx_strerror(mlx_errno));
			return;
		}	
	}
	//	puts("Up!");
	else if (ydelta < 0)
	{
		mlx_delete_image(mlx, img);
		if (mlx_image_to_window(mlx, img, 0, 0) == -1)
		{
			mlx_close_window(mlx);
			ft_printf("%d\n", mlx_strerror(mlx_errno));
			return;
		}	
	}
	//	puts("Down!");
	
	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

int	mandelbrot(char **argv, float px_size)
{
	mlx_t* mlx;
	
	mlx = mlx_init(WIDTH, HEIGHT, "Fractal", false);
	if (!mlx)
	{
		ft_printf("%d\n", mlx_strerror(mlx_errno));
		return(-1);
	}
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		mlx_close_window(mlx);
		ft_printf("%s\n", mlx_strerror(mlx_errno));
		return(-1);
	}
	mandelbrot_t(img, 0, ft_atoi(argv[2]), &px_size);
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		ft_printf("%d\n", mlx_strerror(mlx_errno));
		return(-1);
	}
	mlx_scroll_hook(mlx, &my_scrollhook, &px_size);
	//mlx_scroll_hook(mlx, &ft_scrollhook, &px_size);
	mlx_loop_hook(mlx, ft_hook_esc_arrows, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}

int	fractol(char **argv)
{
	if (argv[1][0] == 'm')
	{
		//memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
		if ((mandelbrot(argv, 0.005) == -1))
				return (-1);
	}
	else if (argv[1][0] == 'j')
	{
		//if (julia_t(img, 0, ft_atoi(argv[2])) == -1);
				return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
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
			if (argv[3] || argv[1][1] || fractol(argv) == -1)
				return (ft_printf("%s\n","EXIT_FAILURE"));
			else
				return (ft_printf("%s\n","EXIT_SUCCESS"));
		}	
	}
	if (argv[1][0] == 'p')
		panda();
	else if (argv[1][0] == 'l')
		line();
}
