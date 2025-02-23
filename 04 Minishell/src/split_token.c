/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:50:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/22 19:25:17 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	words(char const *s, char c)
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
				return (count);
		}
		i++;
	}
	return (count);
}

static int	starts(char const *s, char c, int next, int point)
{
	int	start;

	start = next;
	if (point == 0)
	{
		while (s[start] && s[start] == c)
		{
			start++;
			//start = iter_start(start, s, &one, &two);
		}
	}
	else
	{
		while ((s[start]) && s[start] != c)
		{
			if (s[start] == '|')
				break;
			start++;
			//start = iter_start(start, s, &one, &two);
		}
	}
	return (start);
}

static void	*full_free(char **str, int words)
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

char	**split_token(char const *s, char c)
{
	char	**str;
	int		i;
	int		count;
	int		start;
	int		end;

	i = 0;
	end = 0;
	count = words(s, c);
	str = malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (end < count)
	{
		start = starts(s, c, end, 0);
		if (start < 0)
			return (NULL);
		end = starts(s, c, start, 1);
		if (end < 0)
			return (NULL);
		str[i] = ft_substr(s, start, end - start);
		if (!str[i])
			return (full_free(str, i));
		i++;
	}
	str[i] = 0;
	return (str);
}
