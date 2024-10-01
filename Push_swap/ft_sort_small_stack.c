/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:47:23 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/01 17:35:29 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_simple_compare(t_stack **a, t_stack *tmp)
{
	if ((*a)->num > (*a)->next->num)
		ft_swap(a, 'a');
	else if ((*a)->num > tmp->num)
		ft_rotate(a, 'a');
}

/*void	ft_sort_small_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_ordered(a, b) != 1)
	{
		if (first_is_biggest(a) == 1)
		ft_rotate(a, 'a');
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		if_simple_compare(a, tmp);
	}
}*/

static int	last_is_smallest(t_stack **a, t_stack *tmp)
{
	t_stack *stack;

	stack = *a;
	while (stack->num <= tmp->num)
		{
			if (!stack->next)
				return (1);
			stack = stack->next;
		}
	return (0);
}

static int	first_is_biggest(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	while ((*a)->num >= tmp->num)
		{
			if (!tmp->next)
				return (1);
			tmp = tmp->next;
		}
	return (0);
}

void	ft_sort_small_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_ordered(a, b) != 1)
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		  	//ft_reverse(a, 'a');
		//if_simple_compare(a, tmp);
		if (first_is_biggest(a) == 1)
			ft_rotate(a, 'a');
		else if ((*a)->num > (*a)->next->num)
			ft_swap(a, 'a');
		else if ((*a)->num > tmp->num)
			ft_rotate(a, 'a');
		else if(last_is_smallest(a, tmp) == 1 && first_is_biggest(a) == 1)
		{
			ft_push(a, b, 'b');
			ft_reverse(a, 'a');
			ft_push(b, a, 'a');
		}
		else
			ft_rotate(a, 'a');
	}
}
