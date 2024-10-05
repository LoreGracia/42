/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:26:48 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/05 18:24:37 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	int		tmp;
	t_stack	*a;

	a = *stack;
	if (a && a->next)
	{
		tmp = a->num;
		a->num = a->next->num;
		a->next->num = tmp;
	}
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_push(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;

	tmp = *b;
	if (*a && !*b)
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = NULL;
	}
	else if (*a && *b)
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = tmp;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*a;
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		a = *stack;
		tmp = *stack;
		*stack = (*stack)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = a;
		a->next = NULL;
		a->p = -1;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_reverse(t_stack **stack, char c)
{
	t_stack	*a;
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		a = *stack;
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		a = tmp->next;
		a->next = *stack;
		*stack = a;
		tmp->next = NULL;
		tmp->p = 1;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}
