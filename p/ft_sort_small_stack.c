/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:47:23 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/17 18:26:19 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	if_simple_compare(t_stack **a, t_stack *tmp)
{
	if ((*a)->num > (*a)->next->num)
		ft_swap(a, 'a');
	else if ((*a)->num > tmp->num)
		ft_rotate(a, 'a');
}*/

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

/*void	ft_sort_small_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_ordered(a, b) == 1)
	{;
    		tmp = *a
		while (tmp->next)
			tmp = tmp->next;
   		if (first_is_biggest(a) == 1)
			ft_rotate(a, 'a');
		if ((*a)->num > (*a)->next->num)
			ft_swap(a, 'a');
		else if ((*a)->num > tmp->num)
			ft_rotate(a, 'a');
		else
			ft_rotate(a, 'a');
	}
}*/

/*static int	last_is_smallest(t_stack **a, t_stack *tmp)
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
}*/
#include <stdio.h>
void	ft_sort_small_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_ordered(a, b) == -1)
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
		/*else if(last_is_smallest(a, tmp) == 1 && first_is_biggest(a) == 1)
		{
			ft_push(a, b, 'b');
			ft_reverse(a, 'a');
			ft_push(b, a, 'a');
		}*/
		else
			ft_rotate(a, 'a');
	}
}

int	ft_median(int len, t_stack **a)
{
	t_stack *tmp;
	long i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		i += tmp->num;
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (i / len);
}

/*static int ft_bit_max(int i)
{
	if (i < 256)
		i = 8;
	else if (i < 65536)
		i = 16;
	else
		i = 32;
	return (i);
}*/

int	ft_max(int	len, t_stack **a)
{
	t_stack *tmp;
	int i;

	i = -2147483648;
	tmp = *a;
	while (len--)
	{
		if (tmp->num > i)
			i = tmp->num;
		tmp = tmp->next;
	}
	//i = ft_bit_max(i);
	return (i);
}

int	ft_min(int	len, t_stack **a)
{
	t_stack *tmp;
	int i;

	i = 2147483647;
	tmp = *a;
	while (len--)
	{
		if (tmp->num < i)
			i = tmp->num;
		tmp = tmp->next;
	}
	return (i);
}

/*void	pos(t_stack **stack, int len)
{
	t_stack *tmp;

	tmp = *stack;
	len = len / 2;
	while (tmp)
	{
		if (tmp->num >= len)
			tmp->p = -1;
		else
			tmp->p = 1;
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}*/	

int	position(t_stack **stack, int len, int next)
{
	t_stack *tmp;
	int	i;

	tmp = *stack;
	len = len / 2;
	i = 0;
	while (tmp->num != next)
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
		i++;
	}
		if (i >= len)
			return (-1);
		else
			return (1);
}	
