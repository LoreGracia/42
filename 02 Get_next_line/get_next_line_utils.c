/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:56:13 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/13 19:03:16 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	if (!s)
		return (0);
	i = 0;
	str = (unsigned char *)s;
	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
	{
		return ((char *)&str[i]);
	}
	return (0);
}

char	*ft_join(char const *s1, char const *s2, size_t len1, size_t len2)
{
	size_t		i;
	char		*s;

	i = 0;
	s = malloc((len1 + len2 + 1) * sizeof(char));
	if (s == NULL)
		return (0);
	while (i < len1 && s1)
	{
		s[i] = s1[i];
		i++;
	}
	while (i - len1 < (len2) && s2)
	{
		s[i] = s2[i - len1];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*join;

	if (!s1 && !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = ft_join(s1, s2, len1, len2);
	free(s1);
	return (join);
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
