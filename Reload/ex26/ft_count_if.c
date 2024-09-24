/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:28:06 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/16 18:38:24 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}
/*
#include <stdio.h>

int	ft_(char *tab)
{
	if(printf("%s\n", tab) > 0)
		return (1);
	else
		return (0);
}

int	main()
{
	char	*array[8] = {"3424522", "234234134", "-4524211", 
	"25234", "-2", "-1", "0", "35454"};

	printf("%d", ft_count_if(array, &ft_));
}*/
