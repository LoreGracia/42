/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_stack_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:14:18 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/05 16:26:36 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ft_sort_big_stack_t(t_stack **a, t_stack **b, int len)
{
	t_stack *tmp;
	int	m;

	tmp = *a;
	m = ft_median(len, a);
	printf("median %d\n", m);
}
