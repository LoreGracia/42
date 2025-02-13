/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:25:29 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/05 17:11:22 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_arrows_keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*e;

	e = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
	{
		e->cy += 5;
		e->f(e, 0);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
	{
		e->cy -= 5;
		e->f(e, 0);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
	{
		e->cx += 5;
		e->f(e, 0);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
	{
		e->cx -= 5;
		e->f(e, 0);
	}
}

void	arrows_keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*e;

	e = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		e->cy += 5;
		e->f(e, 0);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		e->cy -= 5;
		e->f(e, 0);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		e->cx += 5;
		e->f(e, 0);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		e->cx -= 5;
		e->f(e, 0);
	}
}

void	mlx_pos_cursor_zoom(double xpos, double ypos, void *param)
{
	t_env	*e;

	e = param;
	e->cursorx = xpos;
	e->cursory = ypos;
}

int	j(char **argv, t_env *e)
{
	if (ft_strncmp("Julia", argv[1], 6) != 0 || \
		nmapi(argv[3], 'd') || nmapi(argv[4], 'd') || argv[5])
		return (-1);
	if (argv[3][0] == '-')
	{
		e->x0 = ft_atoi(&argv[3][1]);
		e->x0 *= -1;
	}
	else
		e->x0 = ft_atoi(argv[3]);
	if (argv[4][0] == '-')
	{
		e->y0 = ft_atoi(&argv[4][1]);
		e->y0 *= -1;
	}
	else
		e->y0 = ft_atoi(argv[4]);
	if (e->x0 >= 4.2 && e->y0 >= 4.2 && e->x0 >= -4.2 && e->y0 >= -4.2)
		ft_printf("Is advised to use lower levels as 0.270 0.009");
	return (0);
}
