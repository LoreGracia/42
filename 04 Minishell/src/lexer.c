/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:48:42 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/18 14:36:56 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

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

char	*lexer(char **read_line, t_pipe pipe, char *line)
{
	int	i;

	pipe.command = ft_strtrim(*read_line, " ");
	printf("%s\n", pipe.command);
	line = ft_strchr(*read_line, ' ');
	free(*read_line);
	i = -1;
	while (line[0] == '-')
	{
		pipe.flag[++i] = ft_strtrim(line, " ");
		printf("%s\n", pipe.flag[i]);
		*read_line = ft_strchr(line, ' ');
		free(line);
		line = ft_strdup(*read_line);
		free(*read_line);
	}
	i = -1;
	while (line[0] != '|' && line[++i])
	{
		pipe.arg[i] = ft_strtrim(line, " ");
		printf("%s\n", pipe.flag[i]);
		*read_line = ft_strchr(line, ' ');
		free(line);

		line = ft_strdup(*read_line);
		free(*read_line);

	}
	if (line[0])
		return (line);
	return (0);
}

char **ft_strarray(char *read_line, int len)
{
	char	**line;
	int		k;
	int		i;
	int		j;

	k = 0;
	i = 0;
	j = -1;
	line = (char **)calloc(sizeof(char *), len);
	while (read_line[k])
	{
		if (read_line[k] == ' ')
			i++;
		else
			line[i][++j] = read_line[k];
		printf("%c\n", line[i][j]);
		printf("1\n");
		k++;
	}
	return (line);
}

t_pipe	*lexer_init(char *read_line, t_env *env)
{
	char	**line;
	//t_pipe	*pipe;
	(void)env;
	int		i;

	i = -1;

	line = ft_strarray(read_line, ccount(read_line, ' '));
	printf("1\n");
	printf("%s\n", line[0]);
	free(line);
	/*while (read_line[0])
	{
		line = lexer(read_line, pipe[++i], line);
		*read_line = ft_strtrim(*read_line, " ");
		free(line);
	}
	return (pipe);*/
	return (0);
}

