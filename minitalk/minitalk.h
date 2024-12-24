/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:45:22 by lgracia-          #+#    #+#             */
/*   Updated: 2024/12/24 15:47:09 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_env
{
	unsigned int	len;
	unsigned int	l;
	int				bit;
	int				count;
	unsigned char	*s;
}				t_env;

#endif
