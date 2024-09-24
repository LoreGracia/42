/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:26:48 by lgracia-          #+#    #+#             */
/*   Updated: 2024/09/24 11:50:58 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	int tmp;
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

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a, 'a');
	ft_swap(b, 'b');
	write(1, "ss\n", 3);
}

void	ft_push(t_stack **a, t_stack **b, int c)
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

void	ft_pp(t_stack **a, t_stack **b)
{
	ft_push(a, b, 'a');
	ft_push(b, a, 'b');
	write(1, "pp\n", 3);
}

