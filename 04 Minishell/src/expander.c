/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:11:25 by lgracia-          #+#    #+#             */
/*   Updated: 2025/03/27 13:02:28 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_strnncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (ss1[i] == ss2[i] && i != n && ss1[i] && ss2[i])
		i++;
	if (!ss1[i] && ss2[i] == '=')
		return (0);
	return (ss1[i] - ss2[i]);
}

char	*find_venv(char *s, int *start, int *len)
{
	char	*tmp;

	while ((s[*start + *len] && s[*start + *len] != ' ')
		&& s[*start + *len] != '\"')
		(*len)++;
	tmp = ft_calloc(1, *len + 2);
	if (!tmp || !ft_strlcpy(tmp, &s[*start + 1], *len))
		tmp = ft_strdup("");
	return (tmp);
}

void	cp_venv(char **env, char **tmp, int len)
{
	int	i;

	i = 0;
	while (env[i] && ft_strnncmp(*tmp, env[i], len) != 0)
		i++;
	if (!env[i])
		*tmp = ft_strdup("");
	else
		*tmp = ft_strdup(ft_strchr(env[i], '=') + 1);
}

char	*replacesubstr(char *s, int *start, char *tmp, int len)
{
	int		i;
	char	*new;

	i = ft_strlen(s) - len + ft_strlen(tmp);
	new = ft_calloc(1, i + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s, *start + 1);
	if (ft_strlen(tmp))
		new = ft_strjoin(new, tmp);
	new = ft_strjoin(new, &s[*start + len]);
	if (ft_strlen(tmp))
		*start += ft_strlen(tmp);
	free(s);
	return (new);
}

char	*expand(char *s, int *start, char **env)
{
	char	*tmp;
	int		len;

	if (s[*start] == 36 && s[*start + 1] && s[*start + 1] != ' ')
	{
		len = 0;
		if (s[*start + 1] && s[*start + 1] == 36)
		{
			len = 2;
			tmp = ft_strdup("\0");
		}
		else
		{
			tmp = find_venv(s, start, &len);
			if (tmp)
				cp_venv(env, &tmp, len);
		}
		return (replacesubstr(s, start, tmp, len));
	}
	return (s);
}
