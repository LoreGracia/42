/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:21:07 by lgracia-          #+#    #+#             */
/*   Updated: 2024/10/22 12:41:39 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(char **argv)
{
	t_stack	*nodo;
	int		i;

	i = 1;
	nodo = malloc(sizeof(t_stack));
	if (nodo == 0)
		return (NULL);
	nodo->num = ft_atoi(argv[i]);
	if (argv[i + 1])
		nodo->next = ft_stacknew(&argv[i++]);
	else
		nodo->next = NULL;
	return (nodo);
}

int	ft_stacksize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*void	printlist(t_stack *lst)
{
	int	size;
	int	str;

	size = ft_stacksize(lst);
	while (lst)
	{
		str = lst->num;
		printf("%d\n", str);
		lst = lst->next;
		size--;
	}
}*/

void	ft_stackclear(t_stack **lst)
{
	t_stack	*next;
	t_stack	*aux;

	aux = *lst;
	while (aux)
	{
		next = aux->next;
		free(aux);
		aux = next;
	}
	*lst = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		max;

	b = NULL;
	if (argc < 2)
		return (-1);
	if (ft_check(argv, argc) == -1)
		return (write(2, "Error\n", 6), 0);
	a = ft_stacknew(argv);
	if (a == 0)
		return (-1);
	if (ft_ordered(&a, &b) == 1)
		return (ft_stackclear(&a), ft_stackclear(&b), 0);
	max = ft_max(argc - 1, &a);
	if (argc <= 6)
		ft_sort_small_stack(&a, &b, argc - 1);
	else if (argc > 6)
		ft_sort_big_stack_r(&a, &b, argc - 1, max);
	return (ft_stackclear(&a), ft_stackclear(&b), 0);
}
