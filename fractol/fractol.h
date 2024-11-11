/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:32:41 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/11 17:45:26 by lgracia-         ###   ########.fr       */
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
# define PX_SIZE 0.005

static mlx_image_t* img;

typedef struct s_fract
{
	void 				*px_size;
	mlx_image_t*		img;
	struct t_fract		*next;
	struct t_fract		*prev;
}			t_fract;

void	t_esc(float x, int x0, float y, int y0, mlx_image_t *img, int d);
unsigned int	melon(int i);

int	panda();
int line();

#endif
