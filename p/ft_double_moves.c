/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:07:04 by lgracia-          #+#    #+#             */
/*   Updated: 2024/09/30 12:08:25 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse(a, 'a');
	ft_reverse(b, 'b');
	write(1, "rrr\n", 4);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a, 'a');
	ft_rotate(b, 'b');
	write(1, "rr\n", 3);
}

void	ft_pp(t_stack **a, t_stack **b)
{
	ft_push(a, b, 'a');
	ft_push(b, a, 'b');
	write(1, "pp\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a, 'a');
	ft_swap(b, 'b');
	write(1, "ss\n", 3);
}
