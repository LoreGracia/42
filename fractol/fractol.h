/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:32:41 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/20 20:00:19 by lgracia-         ###   ########.fr       */
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

# define WIDTH 600
# define HEIGHT WIDTH
# define PX_SIZE 0.005
:x
# define MSG "Try './fractol m 2' or '/.fractol j 2 0.279 0.009'\n"

typedef struct s_c
{
	int			xc;
	int			yc;
	mlx_image_t	*img;
}		t_c;

typedef struct s_env
{
	char			type;
	mlx_t			*mlx;
	mlx_image_t		*img;
	float			px_size;
	int				cx;
	int				cy;
	int				d;
	float			x0;
	float			y0;
	int				xo;
	int				yo;
	void			(*f)(void *, int);
	unsigned int	(*p)(int);
	void			(*arrow_scroll)(mlx_key_data_t keydata, void *);
	void			(*arrow)(mlx_key_data_t keydata, void *);
	int				c;
	t_c				earr;
	t_c				earl;
	t_c				face;
	t_c				eyer;
	t_c				eyel;
	t_c				nose;
}	t_env;

void			t_esc(float x, float y, t_env *e);
unsigned int	melon(int i);
unsigned int	grey(int i);
unsigned int	grass(int i);
void			mandelbrot(void *p, int y);
void			pallete(void *param);
void			ft_scrollhook(double xdelta, double ydelta, void *param);
void			arrows_keyhook(mlx_key_data_t keydata, void *param);
void			scroll_arrows_keyhook(mlx_key_data_t keydata, void *param);
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			ft_clear(t_env *e);
void			julia(void *p, int y);
void			three(float *x, float *y, t_env *e);
void			five(float *x, float *y, t_env *e);
void			two(float *x, float *y, t_env *e);
void			n(float *x, float *y, t_env *e);
float			p(float val, float pow);
float			f_flo(float val, float px_size, mlx_image_t *img);

void			panda(void *p, int y);
void			line(void *p, int y);

#endif
