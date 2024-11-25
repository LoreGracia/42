/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:54:46 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/23 22:40:11 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	screen(mlx_image_t *img, int y, unsigned int color)
{
	int		x;
	size_t	i;

	x = -1;
	i = 0;
	while (x < (int)img->width && y != (int)img->height)
	{
		x++;
		mlx_put_pixel(img, x, y, color);
		if (x == (int)img->width && y < (int)img->height)
			screen(img, y + 1, color);
		if (x == (int)img->width && y == (int)img->height)
			break ;
	}
}

void	line(void *p, int y)
{
	int		i;
	t_env	*e;

	(void)y;
	e = p;
	memset(e->img->pixels, 120, e->img->width * \
			e->img->height * sizeof(int32_t));
	screen(e->img, 120, 0x50EBCEFF);
	i = 0;
	while (i++ < 100)
		mlx_put_pixel(e->img, 100 + i, 100, 0xFFFFF);
}
