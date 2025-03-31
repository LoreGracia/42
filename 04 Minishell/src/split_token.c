/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:50:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/03/31 16:38:12 by lgracia-         ###   ########.fr       */
/*   Updated: 2025/03/12 12:44:57 by mcullell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*delete_strchar(char *s, int *start, char c)
{
	int		len;
	char	*new;

	if (*start && s[*start - 1] != ' ' && c == ' ')
	{
		len = ft_strlen(s) - 1;
		new = ft_calloc(1, len);
		ft_strlcpy(new, s, *start + 1);
		new = ft_strjoin(new, &s[*start + 1]);
		free(s);
		return (new);
	}
	++(*start);
	return (s);
}

int	split_double_quotes(char **string, int *start, char **env, char c)
{
	char	*s;

	s = *string;
	if (s[*start] == '\"')
	{
		s = delete_strchar(s, start, c);
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
	while (s && s[start] && s[start] != c)
	{
		if (split_double_quotes(&s, &start, env, c))
			return (-1);
		if (split_single_quote(s, &start))
			return (-1);
		s = expand(s, &start, env);
		if (!s[start] || s[start] == '|')
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
	words(s, c, &count);
	str = ft_calloc((count + 2), sizeof(char *));
	count = ccount(s, c);
	if (!s)
		return (NULL);
	while (i != count + 1)
	{
		start = starts(&s, c, end);
		end = ends(&s, c, start, env);
		if (end < 0)
			return (NULL);
		if ((s[start] == '\"' && c == ' ') || (s[start] == '\'' && c == ' '))
			start++;
		if ((s[end - 1] == '\"' && c == ' ') || (s[start - 1] == '\'' && c == ' '))
		{
			str[i] = ft_calloc(end - 1 -start, sizeof(char));
			str[i] = ft_substr(s, start, end - 1 - start);
		}
		else
		{
			str[i] = ft_calloc(end - start, sizeof(char));
			str[i] = ft_substr(s, start, end - start);
		}
		str = reallocstr(str, &count, c, s);
		if (!s[i])
			end = 1;
		i++;
	}
	str[i] = NULL;
	return (str);
}
