/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:32:41 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/30 17:56:26 by lgracia-         ###   ########.fr       */
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
# include "printf/ft_printf.h"
# include "libft/libft.h"

# define WIDTH 600
# define HEIGHT WIDTH
# define PX_SIZE 0.005
# define MAX_ITER 100
# define MSG "Try './fractol Mandelbrot 2' or '/.fractol Julia 2 0.279 0.009'\n"

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
	double			px_size;
	int				cx;
	int				cy;
	int				d;
	double			x0;
	double			y0;
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
	int				cursorx;
	int				cursory;
	int				button;
}	t_env;

void			t_esc(double x, double y, t_env *e);
unsigned int	melon(int i);
unsigned int	grey(int i);
unsigned int	grade(int i);
unsigned int	grass(int i);
void			mandelbrot(void *p, int y);
void			pallete(void *param);
void			ft_scrollhook(double xdelta, double ydelta, void *param);
void			arrows_keyhook(mlx_key_data_t keydata, void *param);
void			mouse(mouse_key_t keydata, action_t action, \
		modifier_key_t mods, void *param);
void			my_cursor(double xpos, double ypos, void *param);
void			mlx_pos_cursor_zoom(double xpos, double ypos, void *param);
void			scroll_arrows_keyhook(mlx_key_data_t keydata, void *param);
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			ft_clear(t_env *e);
void			julia(void *p, int y);
void			three(double *x, double *y, t_env *e);
void			five(double *x, double *y, t_env *e);
void			two(double *x, double *y, t_env *e);
void			n(double *x, double *y, t_env *e);
double			p(double val, double pow);
double			to_flo(int val, char c, t_env *e);
int				from_flo(double val, char c, t_env *e);
int				j(char **argv, t_env *e);
short			nmapi(const char *s, char c);

void			panda(void *p, int y);
void			line(void *p, int y);

#endif
