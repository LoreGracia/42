/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:36 by lgracia-          #+#    #+#             */
/*   Updated: 2025/03/31 16:52:39 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ccount(char *read_line, char c)
{
	int	i;
	int	count;
	int	one;

	i = 0;
	count = 0;
	one = 1;
	while (read_line[i] == ' ')
		i++;
	while (read_line[i])
	{
		//if (read_line[i] == 34 || read_line[i] == 39)
		//	one *= -1;
		if (one > 0 && read_line[i] == c)
		{
			if (c == '|' && read_line[i + 1] == c)
				return (-2);
			count++;
		}
		i++;
	}
	while (read_line[--i] == ' ')
	{
		if (read_line[i] == '|')
			return (-1);
		count--;
	}
	if (read_line[i] == '|')
		return (-1);
	return (count);
}

char	*parse_end(int count, int *npipes, char *read_line)
{
	char *next_line;

	*npipes = ccount(read_line, '|');
	if (*npipes >= 0)
		return (read_line);
	else if (*npipes == -2)
		return (free(read_line), NULL);
	else
	{
		next_line = ft_strjoin(read_line, readline(">"));
		free(read_line);
		return (parse_end(count, npipes, next_line));
	}
}

char	*input_parse(char *read_line, t_env *env)
{
	char	*next_line;

	read_line = parse_end(ccount(read_line, '|'), &env->num_pipes, read_line);
	if (!read_line)
		return (NULL);
	env->pipe = lexer_init(read_line, *env);
	if (!env->pipe)
	{
		next_line = ft_strjoin(read_line, readline(">"));
		free(read_line);
		return (input_parse(next_line, env));
	}
	return (read_line);
}

int	main(int ac, char **av, char **pc_env)
{
	(void)ac;
	(void)av;
	char *read_line;
	t_env	env;

	env.env = pc_env;
	while ("O.O")
	{
		read_line = readline("\e[32m(^v^) \e[0m");
		if (read_line && read_line[0])
		{
			read_line = input_parse(read_line, &env);
			if (!read_line)
				printf("0.0: syntax error near unexpected token\n");;
			if (read_line && *read_line)
				add_history(read_line);
			if (av[1] && !strcmp(av[1], "print_arg"))
				print_token(env.pipe, env.num_pipes);
			free(read_line);
		}
	}
	rl_clear_history();
}
