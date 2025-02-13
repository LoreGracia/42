/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:29:30 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/16 11:05:20 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>

int main()
{
	printf("%d\n", ft_strcmp("hello", "hola"));
	printf("%d\n", ft_strcmp("hoa", "hola"));
	printf("%d\n", ft_strcmp("hola", "hola"));
	printf("%d\n", ft_strcmp("b", "d"));
	printf("%d\n", ft_strcmp("c", "a"));
	printf("%d\n", ft_strcmp("ab", "aa"));
}*/
