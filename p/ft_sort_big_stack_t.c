/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:14:18 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/08 16:00:40 by lgracia-         ###   ########.fr       */
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
	t_stack *tmp;
	int	m;
	int 	l;
	int 	next;

	l = len - 3;
	m = ft_median(len, a);
	while (l--)
	{
		ft_push(a, b, 'b');
		if ((*b)->num >= m)
			ft_rotate(b, 'b');
	}	
	ft_sort_small_stack(a, b);
	tmp = *a;
	next = ft_next((*b)->num, a, max, len);
	//printf("%d||\n", next);
	while (*b)
	{
		next = ft_next((*b)->num, a, max, len);
		if (position(a, len, next) == 1)
		{
			while (tmp->num != next)
				ft_rotate(a, 'a');
		}
		else
		{
			while (tmp->num != next)
				ft_reverse(a, 'a');
		}
		ft_push(b, a, 'a');
	}
}
