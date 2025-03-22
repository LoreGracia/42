/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:50:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/03/22 19:01:56 by lgracia-         ###   ########.fr       */
/*   Updated: 2025/03/12 12:44:57 by mcullell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	split_double_quotes(char **string, int *start, char **env)
{
	char	*s;

	s = *string;
	if (s[*start] == '\"')
	{
		++(*start);
		while (s[(*start)] != '\"')
		{
			s = expand(s, start, env);
			if (s[*start] && s[*start] != '\"')
				++(*start);
			if (!s[*start])
				return (1);
		}
		*string = s;
	}
	return (0);
}

int	split_single_quote(char *s, int *start)
{
	if (s[*start] == '\'')
	{
		++(*start);
		while (s[*start] != '\'')
		{
			++(*start);
			if (!s[*start])
				return (1);
		}
	}
	return (0);
}

int	starts(char **string, char c, int next)
{
	int		start;
	char	*s;

	s = *string;
	start = next;
	while (s[start] && s[start] == c)
		start++;
	return (start);
}

int	ends(char **string, char c, int next, char **env)
{
	int		start;
	char	*s;

	s = *string;
	start = next;
	while (s[start] && s[start] != c)
	{
		if (split_double_quotes(&s, &start, env))
			return (-1);
		if (split_single_quote(s, &start))
			return (-1);
		s = expand(s, &start, env);
		if (s[start] == '|')
			break ;
		else
			start++;
	}
	*string = s;
	return (start);
}

char	**split_token(char *s, char c, char **env)
{
	char	**str;
	int		i;
	int		count;
	int		start;
	int		end;

	i = 0;
	end = 0;
	count = 0;
	words(s, c, &count);
	str = ft_calloc((count + 1), sizeof(char *));
	if (!s)
		return (NULL);
	while (end < count)
	{
		start = starts(&s, c, end);
		if (start < 0)
			return (NULL);
		end = ends(&s, c, start, env);
		if (end < 0)
			return (NULL);
		words(s, c, &count);
		if (s[start] == '\"' && c == ' ')
			start++;
		str[i] = ft_substr(s, start, end - start);
		if (s[end - 1] == '\"' && c == ' ')
		{
			str = remallocstr(str, count);
			str[i] = ft_substr(s, start, end - 1 - start);
		}
		else
		{
			str = remallocstr(str, count);
			str[i] = ft_substr(s, start, end - start);
		}
		i++;
	}
	str[i] = 0;
	return (str);
}
