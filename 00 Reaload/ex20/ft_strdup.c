/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:13:38 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/16 12:06:03 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*s;

	len = 0;
	while (src[len] != '\0')
		len++;
	s = (char *)malloc(sizeof(*s) * (len + 1));
	if (!s)
		return (0);
	len = 0;
	while (src[len] != '\0')
	{
		s[len] = src[len];
		len++;
	}
	s[len] = '\0';
	return (s);
}
/*
#include <stdio.h>

int	main ()
{
	printf("%s", ft_strdup("hola"));
}*/
