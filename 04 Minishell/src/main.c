/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:36 by lgracia-          #+#    #+#             */
/*   Updated: 2025/03/11 15:18:46 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	chrccount(char *read_line, char c)
{
	int	i;
	int	count;
	int	one;

	i = 0;
	count = 0;
	one = 1;
	printf("a\n");
	while (one > 0 && read_line[i] != c)
	{
		if (!read_line[i])
			break ;
		printf("missing\n");
		if (read_line[i] == 34 || read_line[i] == 39)
			one *= -1;
		count++;
		i++;
	}
	return (count);
}

int	ccount(char *read_line, char c)
{
	int	i;
	int	count;
	int	one;

	i = 0;
	count = 0;
	one = 1;
	while (read_line[i])
	{
		if (read_line[i] == 34 || read_line[i] == 39)
			one *= -1;
		if (one > 0 && read_line[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	input_parse(char *read_line, t_env *env)
{
	char	*next_line;
	int		i;

	env->num_pipes = ccount(read_line, '|');
	env->pipe = lexer_init(read_line, *env);
	i = -1;
	if (!env->pipe)
	{
		i++;
		next_line = readline(">");
		input_parse(ft_strjoin(read_line, next_line), env);
	}
	return (0);
}

int	main(int ac, char **av, char **pc_env)
{
	(void)ac;
	(void)av;
	(void)pc_env;
	char *read_line;
	t_env	env;

	env.env = pc_env;
	while ("O.O")
	{
		read_line = readline("\e[32m(^v^) \e[0m");
		if (read_line[0])
		{
			input_parse(read_line, &env);
			if (av[1] && !strcmp(av[1], "print_arg"))
				print_token(env.pipe, env.num_pipes);
			if (read_line && *read_line)
				add_history(read_line);
			free(read_line);
		}
	}
	rl_clear_history();
}
