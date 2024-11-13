/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:39:57 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/13 19:41:59 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_hook_esc_arrows(void *param)
{
	mlx_t	*mlx;

	mlx = param;
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

float	to_flo(int val, float px_size, mlx_image_t *img)
{
	val -= img->width / 2;
	return (val * (px_size));
}

int	mandelbrot(mlx_image_t *img, int y, int d, float px_size)
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
			mandelbrot(img, y + 1, d, px_size);
		if (x == (int)img->width && y == (int)img->height)
			break ;
	}
	return (0);
}

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_env	*e;

	e = param;
	if (ydelta > 0)
	{
	//	printf("%f\n", e->px_size);
			e->px_size /= 1.1;
	//	printf("%f\n", e->px_size);
		e->f(img, e->y, e->d, e->px_size);
	}
	if (ydelta < 0)
	{
		e->px_size *= 1.1;
		e->f(img, e->y, e->d, e->px_size);
	}	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}



/*int	mandelbrot(char **argv)
{
	t_env	*e;

	e = malloc(sizeof(t_env));
	if (e == 0)
		return (-1);
	e->px_size = 0.005 / (WIDTH / 800);
	e->y = 0;
	e->d = ft_atoi(argv[2]);
	e->f = mandelbrot_t;
	e->mlx = mlx_init(WIDTH, HEIGHT, "Fractal", false);
	if (!e->mlx)
		return (ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if (!img)
	{
		mlx_close_window(e->mlx);
		return (ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	}
	e->f(img, e->y, e->d, e->px_size);
	//mandelbrot_t(img, e->y, e->d, e->px_size);
	if (mlx_image_to_window(e->mlx, img, 0, 0) == -1)
	{
		mlx_close_window(e->mlx);
		return (ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	}
	//mlx_scroll_hook(e->mlx, &my_scrollhook, &e->px_size);
	mlx_scroll_hook(e->mlx, &ft_scrollhook, e);
	mlx_loop_hook(e->mlx, ft_hook_esc_arrows, e->mlx);
	mlx_loop(e->mlx);
	mlx_delete_image(e->mlx, img);
	mlx_terminate(e->mlx);
	return (0);
}*/
