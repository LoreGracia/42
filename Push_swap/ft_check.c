/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:31:27 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/22 12:40:55 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ordered(t_stack **stack, t_stack **b)
{
	t_stack	*a;

	a = *stack;
	while (a->next && a->num < a->next->num)
		a = a->next;
	if ((!*b) && !a->next)
		return (1);
	if (!a->next)
		return (0);
	return (-1);
}

int	ft_check(char **argv, int argc)
{
	int		i;
	int		j;
	long	tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atol(argv[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (-1);
		j = 1;
		while (i + j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[i + j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
