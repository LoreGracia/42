/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:32:41 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/17 13:01:28 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h> 
# include <math.h>
# include "MLX/include/MLX42/MLX42_Int.h"
# include "Printf/ft_printf.h"
# include "Libft/libft.h"

# define WIDTH 800 
# define HEIGHT WIDTH
# define MAX_ITER 100
# define PX_SIZE 0.005/ (WIDTH /800)

typedef struct s_env
{
	mlx_t	 	*mlx;
	mlx_image_t	*img;
	float		px_size;
	int			y;
	int			d;
	void		(*f)(mlx_image_t*, int, int, float);
}	t_env;

void			t_esc(float x, int x0, float y, int y0, mlx_image_t *img, int d);
unsigned int	melon(int i);
void			mandelbrot(mlx_image_t* img, int x, int y, float px_size);
void			ft_scrollhook(double xdelta, double ydelta, void *param);
void			ft_hook_esc_arrows(void *param);
void			ft_clear(t_env *e);
void			julia(mlx_image_t* img, int x, int y, float px_size);
void			three(float *x, float *y, float x0, float y0);
void			five(float *x, float *y, float x0, float y0);
void			two(float *x, float *y, float x0, float y0);
void			n(float *x, float *y, float x0, float y0, float d);
float			p(float val, float pow);


void			panda(mlx_image_t* img, int x, int y, float px_size);
void			line(mlx_image_t* img, int x, int y, float px_size);

#endif
