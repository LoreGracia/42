/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:20:09 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/28 17:56:11 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_fractol(char **argv, t_env *e)
{
	int	i;

	i = ft_atoi(argv[2]);
	e->arrow = scroll_arrows_keyhook;
	e->arrow_scroll = arrows_keyhook;
	e->button = 0;
	if (e->type == 'm' || argv[1][0] == 'j')
	{
		if (argv[1][0] == 'm')
		{
			if (i < -2 || i == 0 || i == 1)
				return (-1);
			if (i > 6 && i % 2 != 0)
				return (-1);
		}
		e->px_size = 1.0 / (WIDTH >> 2);
		e->cx = WIDTH;
		e->cy = HEIGHT;
		e->c = 0;
		e->d = i;
		e->f = mandelbrot;
		if (e->type == 'j')
		{
			if (!argv[3] || !argv[4])
				return (-1);
			e->x0 = ft_atoi(argv[3]);
			e->y0 = ft_atoi(argv[4]);
			if (e->x0 >= 4.2 && e->y0 >= 4.2)
				ft_printf("Is advised to use lower levels as 0.270 0.009");
			return (1);
		}
	}
	return (0);
}

int	parse(char **argv, t_env *e)
{
	e->type = argv[1][0];
	if (!argv[2] || argv[1][1] || (argv[1][0] != 'j' && argv[3]))
		return (-1);
	if (e->type == 'm' || e->type == 'j')
	{
		if (parse_fractol(argv, e) == -1)
			return (-1);
	}
	if (e->type == 'p')
		e->f = panda;
	if (e->type == 'l')
		e->f = line;
	return (0);
}

int	draw(char **argv, t_env *e)
{
	if (parse(argv, e) == -1)
		return (ft_printf("EXIT FAILURE\n%s", MSG), -1);
	e->mlx = mlx_init(WIDTH, HEIGHT, "Fractal", false);
	if (!e->mlx)
		return (ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if (!e->img)
	{
		mlx_close_window(e->mlx);
		return (ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	}
	if (mlx_image_to_window(e->mlx, e->img, 0, 0) == -1)
	{
		mlx_close_window(e->mlx);
		return (ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	}
	e->f(e, 0);
	mlx_mouse_hook(e->mlx, &mouse, e);
	mlx_scroll_hook(e->mlx, &ft_scrollhook, e);
	mlx_key_hook(e->mlx, &my_keyhook, e);
	mlx_cursor_hook(e->mlx, &mlx_pos_cursor_zoom, e);
	mlx_loop(e->mlx);
	mlx_delete_image(e->mlx, e->img);
	mlx_terminate(e->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc < 1)
		return (0);
	if (draw(argv, &e) == -1)
		return (-1);
	return (0);
}
