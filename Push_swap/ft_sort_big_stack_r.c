/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:18:19 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/10 19:19:25 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
#include <stdio.h>
void	ft_index(t_stack **a, int len,  int max)
{
	t_stack	*tmp;
	int		l;
	int		i;
	int		count;
	int		length;

	tmp = *a;
	length = len;
	i = max;
	count = 0;
	while (length--)
	{
		l = len;
		while (l--)
		{
			if (tmp->num == ft_next(i, a, max, len)) 
			{
				tmp->index = count;
				i = tmp->num;
				count++;
			}
			tmp = tmp->next;
			if (!tmp)
				tmp = *a;
		}
	}
}

void	ft_sort_big_stack_r(t_stack **a, t_stack **b, int len, int max)
{
	int i;
	int l;

	i = 1;
	ft_index(a, len, max);
	while (ft_ordered(a, b) != 1)
	{
		l = len;
		while (l--)
		{
			if (!((*a)->num >> i & 1))
				ft_push(a, b, 'b');
			else
				ft_rotate(a, 'a');
		}
		while (*b)
			ft_push(b, a, 'a');
		i++;
	}
}
