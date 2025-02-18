/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:36 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/18 13:32:35 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ccount(char *read_line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (read_line[i])
	{
		if (read_line[i] == c)
			count++;
		i++;
	}
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
		printf("\e[33m૮₍ ˃ ⤙ ˂ ₎ა\n");
		read_line = readline("./づ\e[0mᡕᠵ᠆ᠵ_⸝᠊᠆ᡁ᠊᠊\e[31m~~~~ \e[0m");
		env.num_pipes = ccount(read_line, '|');
		env.pipe = lexer_init(read_line, &env);
		free(read_line);
		if (!strcmp((const char *)&read_line, "exit"))
		{
			free(read_line);
			rl_clear_history();
			exit(0);
		}
		else if (!strcmp((const char *)read_line, "u ugly"))
			printf("(ಥ_ಥ)");
		else if (!strcmp((const char *)read_line, "what u looking"))
			printf("┻┳|―-∩\n┳┻|   ヽ\n┻┳| ●  |\n┳┻|▼)_ノ\n┻┳|￣ )\n┳ﾐ(￣／\n┻┳T￣|\n");
		else if (!strcmp((const char *)read_line, "f u"))
			printf("凸( •̀_•́ )凸");
		else if (!strcmp((const char *)read_line, "u mad?"))
			printf("ᕕ(˵•̀෴•́˵)ᕗ");
		else if (!strcmp((const char *)read_line, "beware the cat"))
			printf("ก₍⸍⸌̣ʷ̣̫⸍̣⸌₎ค");
		if (read_line && *read_line)
			add_history(read_line);
		printf("\n");
		free(read_line);
		rl_clear_history();

	}
//	for(int i = 0; env[i]; i++)
	//	printf("%s\n", env[i]);

//	printf("%s\n", "");
}
