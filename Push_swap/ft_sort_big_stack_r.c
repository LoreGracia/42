/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:18:19 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/08 20:00:29 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big_stack_r(t_stack **a, t_stack **b, int len, int max)
{
	int i;
	int l;

	i = 1;
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
