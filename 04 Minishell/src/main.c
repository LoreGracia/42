/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:36 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/26 17:49:38 by lgracia-         ###   ########.fr       */
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
	if (one < 0)
		printf("missing\n");
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
	if (one < 0)
		printf("missing\n");
	return (count);
}

int	main(int ac, char **av, char **pc_env)
{
	(void)ac;
	(void)av;
	(void)pc_env;
	char *read_line;
	t_env	env;

	while ("O.O")
	{
		read_line = readline("\e[32m(^v^) \e[0m");
		if (!strcmp((const char *)&read_line, "exit"))
			break ;
		env.num_pipes = ccount(read_line, '|');
		env.pipe = lexer_init(read_line, env.num_pipes);
		if (!env.pipe)
			return (printf("\e[31m-1\e[0m"),-1);
		if (!strcmp(av[1], "print_arg"))
			print_token(env.pipe, env.num_pipes);
		if (read_line && *read_line)
			add_history(read_line);
		free(read_line);
	}
	rl_clear_history();
}
