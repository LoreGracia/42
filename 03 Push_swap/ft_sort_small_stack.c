/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:47:23 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/22 12:44:08 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	first_is_biggest(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while ((*a)->num >= tmp->num)
	{
		if (!tmp->next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_sort_small_stack(t_stack **a, t_stack **b, int len)
{
	if (len <= 3)
		ft_sort_three(a, b);
	else
		ft_sort_five(a, b, len);
}

void	ft_sort_three(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_ordered(a, b) == -1)
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		if (first_is_biggest(a) == 1)
			ft_rotate(a, 'a');
		else if ((*a)->num > (*a)->next->num)
			ft_swap(a, 'a');
		else if ((*a)->num > tmp->num)
			ft_rotate(a, 'a');
		else
			ft_rotate(a, 'a');
	}
}

static void	ft_five(t_stack **a, int len, t_stack **b)
{
	if (position(a, len, ft_min(len, a)) == 1 || \
		position(a, len, ft_max(len, a)) == 1)
	{
		while (ft_ordered(a, b) != 1)
			ft_rotate(a, 'a');
	}
	else
	{
		while (ft_ordered(a, b) != 1)
			ft_reverse(a, 'a');
	}
}

void	ft_sort_five(t_stack **a, t_stack **b, int len)
{
	int	i;
	int	next;

	i = 2;
	ft_push(a, b, 'b');
	ft_push(a, b, 'b');
	ft_sort_three(a, b);
	while (ft_ordered(a, b) != 1)
	{
		next = ft_next((*b)->num, a, ft_max(len - i, a), len - i);
		if (*b && (*a)->num == next)
		{
			ft_push(b, a, 'a');
			if (i)
				i--;
		}
		else if (position(a, len, next) == 1)
			ft_rotate(a, 'a');
		else
			ft_reverse(a, 'a');
		if (!*b)
			break ;
	}
	ft_five(a, len, b);
}
