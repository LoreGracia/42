/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:32:41 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/17 19:44:30 by lgracia-         ###   ########.fr       */
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
	void		(*f)(void *, int);
}	t_env;

void			t_esc(float x, float y, t_env *e);
unsigned int	melon(int i);
void			mandelbrot(void *p, int y);
void			ft_scrollhook(double xdelta, double ydelta, void *param);
void			ft_hook_esc_arrows(void *param);
void			ft_clear(t_env *e);
void			julia(void *p, int y);
void			three(float *x, float *y, float x0, float y0);
void			five(float *x, float *y, float x0, float y0);
void			two(float *x, float *y, float x0, float y0);
void			n(float *x, float *y, float x0, float y0, float d);
float			p(float val, float pow);
float			f_flo(float val, float px_size, mlx_image_t *img);

void			panda(void *p, int y);
void			line(void *p, int y);

#endif
