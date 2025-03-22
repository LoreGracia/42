/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:50:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/03/22 19:01:23 by lgracia-         ###   ########.fr       */
/*   Updated: 2025/03/12 12:44:57 by mcullell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	words(char *s, char c, int *old)
{
	int	count;     
	int	i;

	i = 0;
	if (s[i] == c || s[i])
		count = 0;
	else
		count = 1;
	while (s[i])
	{
		if (s[i] == c || s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i] != c && s[i] != 0)
				count++;
			if (!s[i])
				break ;
		}
		i++;
	}
	*old = count;
}

/*int	split_exception( char *s, char c, int start, int irecursive)
{
	irecursive *= -1;
	if (s[start] == c && s[start + 1] == '\\')
	{
		printf("+1 %c\n", s[start + 1]);
		if (split_exception(s, '\\', start + 1, irecursive) > 0)
			return (1 * irecursive);
	}
	return (-1 * irecursive);
}*/

void	*full_free(char **str, int words)
{
	int	i;

	i = 0;
	while (i != words)
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

char	**remallocstr(char **str, int count)
{
	char	**s;
	int		i;

	i = 0;
	s = ft_calloc((count + 1), sizeof(char *));
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[i] = ft_strdup(str[i]);
		i++;
	}
	free(str);
	return (s);
}
