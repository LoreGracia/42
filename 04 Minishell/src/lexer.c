/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:48:42 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/24 17:49:31 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	print_token(t_pipe *pipe, int num_pipes)
{
	int	i;
	int	j;
	
	i = -1;
	while (num_pipes >= ++i)
	{
		j = -1;
		while (pipe[i].token[++j])
			printf("\e[35mToken[%d][%d] \e[93m%s\n\e[0m", i, j, pipe[i].token[j]);
	}
}

t_pipe	*lexer_init(char *read_line, int num_pipes)
{
	char	**line;
	t_pipe	*pipe;
	int		i;

	pipe = malloc(sizeof(t_pipe) * (num_pipes + 1));
	line = malloc(sizeof(char *) * (num_pipes + 1));
	line = split_token(read_line, '|');
	if (!line)
		return (NULL);
	i = -1;
	while (++i <= num_pipes)
	{
		pipe[i].token = malloc(sizeof(char *) * (ccount(line[i], ' ') + 1));
		pipe[i].token = split_token(line[i], ' ');
	}
	return (pipe);
}
