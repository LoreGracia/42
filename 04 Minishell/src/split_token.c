/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:50:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/26 17:45:58 by lgracia-         ###   ########.fr       */
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

int	split_exception(const char *s, int start, int irecursive)
{
	irecursive *= -1;
	if (s[start + 1] == '\\')
	{
		printf("+1 %c\n", s[start + 1]);
		if (split_exception(s, start + 1, irecursive) > 0)
			return (1 * irecursive);
	}
	return (-1 * irecursive);
}

int	split_quotes(char const *s, char c, int *start)
{
	if (s[*start] == c)
	{
		++(*start);
		while (s[*start] != c && split_exception(s, (*start) + 1, -1) < 0)
			++(*start);
	}
	return (0);
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
		}
	}
	else
	{
		while ((s[start]) && s[start] != c)
		{
			if (s[start] == 34)
				split_quotes(s, 34, &start);
			if (s[start] == 39)
				split_quotes(s, 39, &start);
			if (s[start] == '|')
				break;
			else
				start++;
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
