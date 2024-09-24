/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:12:36 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/02 13:27:42 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	character(int c, int *count)
{
	if (write(1, &c, 1) != -1)
		(*count)++;
	else
		*count = -1;
	return (*count);
}
/*
#include <stdio.h>
int main(void)
{
	ft_printf("%c\n", '0');
	ft_printf(" %c \n", '0');
	ft_printf(" %c\n", '0' - 256);
	ft_printf("%c \n", '0' + 256);
	ft_printf(" %c %c %c \n", '0', 0, '1');
	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	ft_printf(" %c %c %c \n", '1', '2', '3');
	ft_printf(" %c %c %c \n", '2', '1', 0);
	ft_printf(" %c %c %c \n\n", 0, '1', '2');

	printf(" %c \n", '0');
	printf(" %c\n", '0' - 256);
	printf("%c \n", '0' + 256);
	printf(" %c %c %c \n", '0', 0, '1');
	printf(" %c %c %c \n", ' ', ' ', ' ');
	printf(" %c %c %c \n", '1', '2', '3');
	printf(" %c %c %c \n", '2', '1', 0);
	printf(" %c %c %c \n", 0, '1', '2');

}*/
