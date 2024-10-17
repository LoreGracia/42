/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:14:18 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/17 18:48:12 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_next(int b, t_stack **a, int max, int len)
{
	t_stack *tmp;
	int 	i;

	i = 2147483647;
	tmp = *a;
	if (b == max)
		return (ft_min(len, a));
	else
	{
		while (len--)
		{
			if (tmp->num > b)
			{
				if(tmp->num < i)
					i = tmp->num;
			}
			tmp = tmp->next;
		}
	}
	return (i);
}

void	ft_sort_big_stack_t(t_stack **a, t_stack **b, int len, int max)
{
	int	m;
	int l;
	int next;

	l = len - 3;
	m = ft_median(len, a);
	printf("%d||\n", m);
	while (l--)
	{
		ft_push(a, b, 'b');
		if ((*b)->num >= m)
			ft_rotate(b, 'b');
	}	
	printf("Hola\n");
	//ft_sort_small_stack(a, b);
	printf("Adios\n");
	next = ft_next((*b)->num, a, max, len);
	printf("%d||\n", next);
	while (*b)
	{
		next = ft_next((*b)->num, a, max, len);
		while ((*a)->num != next) 
		{
			printf("aNum %d next %d\n", (*a)->num, next);
			if (position(a, len, next) == 1)
			{
					ft_rotate(a, 'a');
			}
			else
			{
					ft_reverse(a, 'a');
			}
			break ;
		}
		break ;
		ft_push(b, a, 'a');
	}
}
