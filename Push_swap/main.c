/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:21:07 by lgracia-          #+#    #+#             */
/*   Updated: 2024/09/30 12:17:50 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	printlist(t_stack *lst)
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
}

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
	else if (ft_ordered(&a, &b) == 0)
		printlist(a);
	if (argc <= 6)
		ft_sort_small_stack(&a, &b);
	else if (argc > 6)
		printlist(a);
		//ft_sort_big_stack(&a, &b);
	return (0);
}
