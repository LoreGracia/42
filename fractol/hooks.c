/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:19 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/18 18:13:07 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_env	*e;

	e = param;
	if (ydelta > 0)
	{
		e->px_size /= 1.1;
		e->f(e, e->y);
	}
	if (ydelta < 0)
	{
		e->px_size *= 1.1;
		e->f(e, e->y);
	}
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_env *e;

	e = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(e->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT)
	{
		e->cy += 5;
		e->f(e, e->y);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT)
	{
		e->cy -= 5;
		e->f(e, e->y);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
	{
		e->cx += 5;
		e->f(e, e->y);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
	{
		e->cx -= 5;
		e->f(e, e->y);
	}
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
	{
		if (e->c != 2)
			e->c += 1;
		else
			e->c = 0;
		e->f(e, e->y);
	}
}
