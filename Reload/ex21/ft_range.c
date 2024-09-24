/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:17:42 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/15 12:20:50 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	*array;

	if (min < max)
	{
		array = (int *)malloc(sizeof(int) * (max - min));
		i = min;
		j = 0;
		while (j < max - min)
		{
			array[j] = i;
			j++;
			i++;
		}
		return (array);
	}
	return (0);
}
/*
int	main()
{
	int i = 0;
	int min = 5;
	int max = 9;

	while (i != max - min)
	{
		printf("%d", ft_range(min, max)[i]);
		i++;
	}
}*/
