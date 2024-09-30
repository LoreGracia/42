/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:47:23 by lgracia-          #+#    #+#             */
/*   Updated: 2024/09/30 12:15:34 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_sort_small_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;


	while (ft_ordered(a, b) != 1)
	{
		tmp = *a;
		while ((*a)->num >= tmp->num)
		{
			if (!tmp->next)
			{
				ft_rotate(a, 'a');
				break ;
			}
			tmp = tmp->next;
		}
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		if ((*a)->num > (*a)->next->num)
			ft_swap(a, 'a');
		else if ((*a)->num > tmp->num)
			ft_rotate(a, 'a');
		else
			ft_reverse(a, 'a');
	}
}*/

void	ft_sort_small_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	while (ft_ordered(a, b) != 1)
	{
		tmp = *a;
		while ((*a)->num >= tmp->num)
		{
			if (!tmp->next)
			{
				ft_rotate(a, 'a');
				break ;
			}
			tmp = tmp->next;
		}
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		if ((*a)->num > (*a)->next->num)
			ft_swap(a, 'a');
		else if ((*a)->num > tmp->num)
			ft_rotate(a, 'a');
		else
			ft_reverse(a, 'a');
	}
}
