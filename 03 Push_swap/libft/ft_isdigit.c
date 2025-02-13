/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:22:11 by lgracia-          #+#    #+#             */
/*   Updated: 2024/09/20 18:34:49 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > '/' && c < ':')
		return (2048);
	else
		exit(write(1, &"Error\n", 6) * 0);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_isdigit('9'));
	printf("%d\n", ft_isdigit('a'));
}*/
