/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:17:59 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/14 14:43:53 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*new(int fd, char *nextline)
{
	char	*tmp;
	ssize_t	byte;

	byte = 0;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == 0)
		return (0);
	tmp[0] = '\0';
	while (!ft_strchr(nextline, '\n'))
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte < 0)
			return (free(tmp), free(nextline), NULL);
		if (byte == 0)
			break ;
		tmp[byte] = '\0';
		nextline = ft_strjoin(nextline, tmp);
		if (nextline == 0)
			break ;
	}
	return (free(tmp), nextline);
}

char	*cut_line(char *nextline)
{
	int		j;
	char	*next;

	j = 0;
	while (nextline[j] != '\n' && nextline[j] != '\0')
		j++;
	next = ft_substr(nextline, 0, j + 1);
	return (next);
}

char	*next(char *nextline)
{
	int		start;
	int		end;
	char	*new;

	start = 0;
	while (nextline[start] != '\n' && nextline[start] != '\0')
		start++;
	end = start;
	if (nextline[start] == '\n')
		start++;
	while (nextline[end] != '\0')
		end++;
	if (start == end)
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (free(nextline), new);
	}
	new = ft_substr(nextline, start, end);
	free(nextline);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*nextline[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4095)
		return (0);
	nextline[fd] = new(fd, nextline[fd]);
	if (nextline[fd] == 0)
		return (0);
	line = cut_line(nextline[fd]);
	if (!line)
		return (free(nextline[fd]), nextline[fd] = NULL, NULL);
	nextline[fd] = next(nextline[fd]);
	if (!nextline[fd])
		return (free(line), NULL);
	if (!*nextline[fd])
	{
		free(nextline[fd]);
		nextline[fd] = NULL;
	}
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int    fd1;
    int    fd2;
    int    fd3;
    int    i;
    char *line;

    argc = argc + 0;
	get_next_line(500000);
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    fd3 = open(argv[3], O_RDONLY);
    if (fd2 < 0 || fd3 < 0)
        return (-1);
    i = 0;
    while (i++ < 20)
    {
        line = get_next_line(fd1);
        printf("|%s", line);
        free(line);
        line = get_next_line(fd2);
        printf("|%s", line);
        free(line);
        line = get_next_line(fd3);
        printf("|%s", line);
        free(line);
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}*/
