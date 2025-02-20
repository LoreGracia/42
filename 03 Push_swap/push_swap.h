/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:14:24 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/22 12:43:01 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		ft_check(char **argv, int argc);
int		ft_next(int b, t_stack **a, int max, int len);
void	ft_index(t_stack **a, int len, int max);
int		ft_max(int len, t_stack **a);
int		ft_min(int len, t_stack **a);
int		ft_stacksize(t_stack *lst);
t_stack	*ft_stacknew(char **argv);
int		ft_ordered(t_stack	**stack, t_stack **b);
void	ft_stackclear(t_stack **lst);
void	ft_swap(t_stack **stack, char c);
void	ft_push(t_stack **a, t_stack **b, char c);
void	ft_rotate(t_stack **stack, char c);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_reverse(t_stack **stack, char c);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_sort_small_stack(t_stack **a, t_stack **b, int len);
void	ft_sort_three(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b, int len);
void	ft_sort_big_stack_r(t_stack **a, t_stack **b, int len, int max);
int		position(t_stack **a, int len, int next);

#endif
