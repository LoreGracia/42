/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:18:19 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/04 14:50:02 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bits(t_stack **a, t_stack **b, int i)
{
	t_stack *tmp;

	tmp = *b;
	while (tmp)
	{
		if ((tmp->num >> i & 1))
			ft_push(b, a, 'a');
		else 
			ft_rotate(b, 'b');
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}
#include <stdio.h>
void	ft_sort_big_stack_r(t_stack **a, t_stack **b, int max)
{
	t_stack *tmp;
	int i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		printf("%d\n", tmp->num);	
		if (!(tmp->num >> i & 1))
			ft_push(a, b, 'b');
		else
			ft_rotate(a, 'a');
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	ft_sort_bits(a, b, i + 1);
	while (*b)
		ft_push(b, a, 'a');
	if (i != max && ft_ordered(a, b) != 1)
		ft_sort_big_stack_r(a, b, i++);
}
