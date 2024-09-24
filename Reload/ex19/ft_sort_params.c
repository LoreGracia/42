/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:57:08 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/16 11:34:08 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
/*{
	write(1, &c, 1);
}*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char **s1, char **s2)
{
	char	*i;

	i = *s1;
	*s1 = *s2;
	*s2 = i;
}

void	ft_print_argc(int len, char **argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (argc[i][j] != '\0')
		{
			ft_putchar(argc[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int len, char **argc)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (i < len - 1)
	{
		while (j < len)
		{
			if (ft_strcmp(argc[i], argc[j]) > 0)
			{
				ft_swap(&argc[i], &argc[j]);
			}
			j++;
		}
		j = i + 1;
		i++;
	}
	ft_print_argc(len, argc);
}
