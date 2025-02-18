/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:32:06 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/16 16:37:32 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (start > ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	i = 0;
	sub = malloc(len * sizeof(char) + 1);
	if (sub == NULL)
		return (0);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = ft_strlen(s1);
	while (i < j && ft_strchr(set, s1[i]) != 0)
		i++;
	while (j >= 0 && ft_strchr(set, s1[j]) != 0 && j > i)
		j--;
	s = ft_substr(s1, i, (j + 1 - i));
	if (s == 0)
		return (0);
	return (s);
}
