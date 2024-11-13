/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:20:09 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/13 20:02:43 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol(char **argv, t_env *e)
{
	e->px_size = 0.005 / (WIDTH / 800);
	e->mlx = mlx_init(WIDTH, HEIGHT, "Fractal", false);
	if (!e->mlx)
		return (free(e), ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	printf("1\n");
	img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if (!img)
	{
		mlx_close_window(e->mlx);
		return (ft_printf("%d\n", mlx_strerror(mlx_errno)), -1);
	}
	if (argv[1][0] == 'm')
	{	
		e->y = 0;
		e->d = ft_atoi(argv[2]);
		e->f = mandelbrot;
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
	t_env	*e;

	if (argc < 2)
		return (0);
	e = malloc(sizeof(t_env));
	if (e == 0)
		return (-1);
	if (argv[1][0] == 'm' || argv[1][0] == 'j')
	{
		if (!argv[2] && argv[1][0] == 'm')
			return (write(2, "Try './fractol m 2'", 20), 0);
		else if (!argv[2] && argv[1][0] == 'p')
			return (write(2, "Try './fractol j 2'", 20), 0);
		if (argc > 2)
		{
			if (argv[3] || argv[1][1] || fractol(argv, e) == -1)
				return (ft_printf("%s\n", "EXIT_FAILURE"));
			else
				return (ft_printf("%s\n", "EXIT_SUCCESS"));
		}
	}
	if (argv[1][0] == 'p')
		panda();
	else if (argv[1][0] == 'l')
		line();
	e->f(img, e->y, e->d, e->px_size);
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

}
