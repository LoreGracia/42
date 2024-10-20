/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:18:19 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/05 15:59:04 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (length != 0 && count < len)
	{
		l = len + 1;
		while (l != 0 && count < len)
		{
			if (tmp->num == ft_next(i, a, max, len)) 
			{
				tmp->index = count;
				i = tmp->num;
				count++;
			}
			if (!tmp->next)
				tmp = *a;
			else
				tmp = tmp->next;
			l--;
		}
		length--;
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
			if (!((*a)->index >> i & 1))
				ft_push(a, b, 'b');
			else
				ft_rotate(a, 'a');
		}
		while (*b)
			ft_push(b, a, 'a');
		i++;
	}
}
