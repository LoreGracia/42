/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:25:29 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/30 17:55:17 by lgracia-         ###   ########.fr       */
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
		nmapi(argv[3], 'd') || nmapi(argv[4], 'd'))
		return (-1);
	e->x0 = ft_atoi(argv[3]);
	e->y0 = ft_atoi(argv[4]);
	if (e->x0 >= 4.2 && e->y0 >= 4.2)
		ft_printf("Is advised to use lower levels as 0.270 0.009");
	return (0);
}
