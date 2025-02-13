/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:43:40 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/22 12:43:42 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_median(int len, t_stack **a)
{
	t_stack	*tmp;
	long	i;

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

int	ft_max(int len, t_stack **a)
{
	t_stack	*tmp;
	int		i;

	i = -2147483648;
	tmp = *a;
	while (len--)
	{
		if (tmp->num > i)
			i = tmp->num;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_min(int len, t_stack **a)
{
	t_stack	*tmp;
	int		i;

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

int	position(t_stack **stack, int len, int next)
{
	t_stack	*tmp;
	int		i;

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
