/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:48:42 by lgracia-          #+#    #+#             */
/*   Updated: 2025/03/11 18:32:08 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	print_token(t_pipe *pipe, int num_pipes)
{
	int	i;
	int	j;
	
	i = -1;
	if (!pipe->token[0])
		printf("\n");
	else while (num_pipes >= ++i)
		{
			j = -1;
			while (pipe[i].token[++j])
				printf("\e[35mToken[%d][%d] \e[93m%s\n\e[0m", i, j, pipe[i].token[j]);
		}
}

t_pipe	*lexer_init(char *read_line, t_env env)
{
	char	**line;
	t_pipe	*pipe;
	int		i;

	pipe = malloc(sizeof(t_pipe) * (env.num_pipes + 1));
	line = malloc(sizeof(char *) * (env.num_pipes + 1));
	line = split_token(read_line, '|', env.env);
	if (!line || !read_line)
		return (NULL);
	else
	{
		i = -1;
		while (++i <= env.num_pipes)
		{
			pipe[i].token = malloc(sizeof(char *) * (ccount(line[i], ' ') + 1));
			pipe[i].token = split_token(line[i], ' ', env.env);
		}
	}
	return (pipe);
}
