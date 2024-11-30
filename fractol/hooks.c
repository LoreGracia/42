/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:19 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/30 17:36:52 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	is_cursor_close(void *param)
{
	t_env	*e;
	int		w;

	e = param;
	w = (int)e->img->width / 2;
	if (e->button == 1)
	{
		if (e->cursorx <= w)
			e->cx += (e->cursorx - w) * -1 * 1.1;
		if (e->cursorx > w)
			e->cx -= (e->cursorx - w) * 1.1;
		if (e->cursory <= w)
			e->cy += (e->cursory - w) * -1 * 1.1;
		if (e->cursory > w)
			e->cy -= (e->cursory - w) * 1.1;
	}
}

void	is_cursor_far(void *param)
{
	t_env	*e;
	int		w;

	e = param;
	w = (int)e->img->width / 2;
	if (e->button == 1)
	{
		if (e->cursorx <= w)
			e->cx -= (e->cursorx - w) * -1 / 1.1;
		if (e->cursorx > w)
			e->cx += (e->cursorx - w) / 1.1;
		if (e->cursory <= w)
			e->cy -= (e->cursory - w) * -1 / 1.1;
		if (e->cursory > w)
			e->cy += (e->cursory - w) / 1.1;
	}
}

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
	t_env	*e;

	e = param;
	if (ydelta > 0)
	{
		e->px_size /= 1.1;
		is_cursor_close(e);
	}
	else if (ydelta < 0)
	{
		e->px_size *= 1.1;
		is_cursor_far(e);
	}
	if (xdelta < 0)
	{
		e->px_size /= 1.1;
		is_cursor_close(e);
	}
	else if (xdelta > 0)
	{
		e->px_size *= 1.1;
		is_cursor_far(e);
	}
	e->f(e, 0);
}

void	mouse(mouse_key_t key, action_t action, \
		modifier_key_t mods, void *param)
{
	t_env	*e;
	int		mid;

	e = param;
	(void)mods;
	mid = e->img->width;
	if (key == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		e->cx = mid;
		e->cy = mid;
	}
	if (key == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
	{
		if (e->button != 1)
			e->button = 1;
		else
			e->button = 0;
	}
	e->f(e, 0);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*e;

	e = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(e->mlx);
	e->arrow(keydata, e);
	e->arrow_scroll(keydata, e);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
	{
		if (e->c != 3)
			e->c += 1;
		else
			e->c = 0;
		e->f(e, 0);
	}
}
