/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:20:09 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/17 15:33:36 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_fractol(char **argv, t_env *e)
{
	int	i;

	i = ft_atoi(argv[2]);
	if (argv[1][0] == 'm')
	{
		if (i < -2 || i == 0 || i == 1)
			return (-1);
		if (i > 6 && i % 2 != 0)
			return (-1);
		e->px_size = 0.005 / (WIDTH / 800);
		e->y = 0;
		e->d = ft_atoi(argv[2]);
		e->f = mandelbrot;
		return (1);
	}
	else if (argv[1][0] == 'j')
	{
		e->f = julia;
		return (1);
	}
	return (0);
}

int	parse(char **argv, t_env *e)
{
	int	i;

	if (argv[1][1])
		return (write(2, "Try './fractol m 2'\n", 21), -1);
	if (argv[1][0] == 'm' || argv[1][0] == 'j')
	{
		if (!argv[2] || argv[3] || argv[1][1])
			return (write(2, "Try './fractol m 2'\n", 21), -1);
		i = parse_fractol(argv, e);
		if (i == -1)
			return (-1);
		else if (i == 1)
			return (0);
	}
	else
	{
		if (argv[1][0] == 'p')
			e->f = panda;
		if (argv[1][0] == 'l')
			e->f = line;
	}
	return (0);
}

int	draw(char **argv, t_env *e)
{
	if (parse(argv, e) == -1)
		return (write(2, "EXIT_FAILURE", 12), -1);
	e->mlx = mlx_init(WIDTH, HEIGHT, "Fractal", false);
	if (!e->mlx)
		return (ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if (!e->img)
	{
		mlx_close_window(e->mlx);
		return (ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	}
	e->f(e->img, e->y, e->d, e->px_size);
	if (mlx_image_to_window(e->mlx, e->img, 0, 0) == -1)
	{
		mlx_close_window(e->mlx);
		return (free(e), ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	}
	mlx_scroll_hook(e->mlx, &ft_scrollhook, e);
	mlx_loop_hook(e->mlx, ft_hook_esc_arrows, e);
	mlx_loop(e->mlx);
	mlx_delete_image(e->mlx, e->img);
	mlx_terminate(e->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc < 2)
		return (0);
	if (draw(argv, &e) == -1)
		return (-1);
	return (0);
}
