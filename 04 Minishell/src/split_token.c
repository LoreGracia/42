/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:50:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/03/11 19:04:52 by lgracia-         ###   ########.fr       */
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

/*int	split_exception(const char *s, char c, int start, int irecursive)
{
	irecursive *= -1;
	if (s[start] == c && s[start + 1] == '\\')
	{
		printf("+1 %c\n", s[start + 1]);
		if (split_exception(s, '\\', start + 1, irecursive) > 0)
			return (printf("exception of exception %c\n", s[start + 1]) * 1 * irecursive);
	}
	return (-1 * irecursive);
}*/
const char	*expand(const char *s, int *start, char **env)
{
	int		i;
	char	*tmp;
	char	*new;
	int		len;

	if (s[*start] == 36)
	{
		len = 0;
		while (s[*start + len] && s[*start + len] != ' ' || s[*start + len] != )
			len++;
		printf("echo \n");
		tmp = malloc(len + 1);
		if (!tmp || !ft_strlcpy(tmp, &s[*start], len))
			return (NULL);
		while (env[i] && ft_strcmp(tmp, env[i]))
			i++;
		if (!env[i])
			tmp = "";
		else
		{
			free(tmp);
			tmp = ft_strdup(env[i]);
		}
		i = ft_strlen(s) - len + ft_strlen(tmp);
		new = malloc(i + 1);
		if (!new)
			return (NULL);
		ft_strlcpy(new, s, *start);
		ft_strjoin(new, tmp);
		ft_strjoin(new, &s[*start + len]);
		*start += *start + len;
	//	/free(s);
	//	s = (const char *)new;
	//	free(new);
		return (new);
	}
	return (s);
}

int	split_double_quotes(char const *s, int *start, char** env)
{
	(void)env;
	if (s[*start] == '\"')
	{
		++(*start);
		while (s[*start] != '\"')
		{
			s = (const char*)expand(s, start, env);
			++(*start);
			if (!s[*start])
				return (1);
		}
	}
	return (0);
}

int	split_single_quote(char const *s, int *start)
{
	printf("dah\n");
	if (s[*start] == '\'')
	{
		++(*start);
		while (s[*start] != '\'')
		{
			printf("dah\n");
			++(*start);
			if (!s[*start])
				return (1);
		}
	}
	return (0);
}

static int	starts(char const *s, char c, int next, int point, char** env)
{
	int	start;

	start = next;
	if (point == 0)
	{
		while (s[start] && s[start] == c)
			start++;
	}
	else
	{
		while (s[start] && s[start] != c)
		{
			if (s[start] == 34)
			{
				if (split_double_quotes(s, &start, env))
					return (-1);
			}
			if (s[start] == 39)
			{
				if (split_single_quote(s, &start))
					return (-1);
			}
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

char	**split_token(char const *s, char c, char **env)
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
		start = starts(s, c, end, 0, env);
		if (start < 0)
			return (NULL);
		end = starts(s, c, start, 1, env);
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
