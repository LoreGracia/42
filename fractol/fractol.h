/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:32:41 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/30 17:02:13 by lgracia-         ###   ########.fr       */
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
# include "Libft/libft.h"

# define WIDTH 812
# define HEIGHT 812

static mlx_image_t* image;

void	t_esc(int x, int y, mlx_image_t *img, int d);
unsigned int	melon(int i, int max);

#endif
