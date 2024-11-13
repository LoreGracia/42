/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:25:13 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/13 19:53:55 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clear(t_env	*e)
{
	free((void *)e->mlx);
	free((void *)e->px_size);
	free((void *)e->y);
	free((void *)e->d);
	free((void *)e->f);
	free(e);
	e = NULL;
}
