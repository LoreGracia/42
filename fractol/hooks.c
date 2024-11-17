/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:19 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/17 17:34:15 by lgracia-         ###   ########.fr       */
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

void	ft_hook_esc_arrows(void *param)
{
	t_env	*e;

	e = param;
	if (mlx_is_key_down(e->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(e->mlx);
	if (mlx_is_key_down(e->mlx, MLX_KEY_UP))
		e->img->instances[0].y += 5;
	if (mlx_is_key_down(e->mlx, MLX_KEY_DOWN))
		e->img->instances[0].y -= 5;
	if (mlx_is_key_down(e->mlx, MLX_KEY_LEFT))
		e->img->instances[0].x += 5;
	if (mlx_is_key_down(e->mlx, MLX_KEY_RIGHT))
		e->img->instances[0].x -= 5;
}
