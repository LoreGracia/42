/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:14:18 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/05 19:55:09 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_next(int b, t_stack **a, int max)
{
	t_stack *tmp;
	int i;

	i = 2147483647;
	if (b = max)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->num < i)
				i = tmp->num;
			if(!tmp->next)
				break ;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			if (tmp->num > b && tmp->num <= i)
				i = tmp->num;
			if(!tmp->next)
				break ;
			tmp = tmp->next;
		}
	}
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
	//	print("%d|\n", l);
		ft_push(a, b, 'b');
		if ((*b)->num >= m)
			ft_rotate(b, 'b');
	}	
	ft_pos(b, len);
	ft_sort_small_stack(a, b);
	tmp = *a;
	while (*b)
	{
		next = ft_next((*b)->num, a, max);
		while (tmp->num != next)
		{
			ft_rotate(a, 'a');
		}
	}
}
