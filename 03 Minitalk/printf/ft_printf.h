/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:56:57 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/02 14:02:46 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		format(char c, va_list arg, int *count);
int		character(int c, int *count);
int		string(char *s, int *count);
int		pointer(unsigned long v, int *count);
int		decimal(int d, int *count);
int		integer(int d, int *count);
int		unsigne(unsigned int d, int *count);
int		hexlow(unsigned int d, int *count);
int		hexup(unsigned int d, int *count);

#endif
