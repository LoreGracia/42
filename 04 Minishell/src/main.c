/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:36 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/15 13:02:59 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	char *read_line;

	while ("O.O")
	{
		read_line = readline("\e[33m૮₍ ˃ ⤙ ˂ ₎ა\n./づ\e[0mᡕᠵ᠆ᠵ_⸝᠊᠆ᡁ᠊᠊\e[31m~~~~ \e[0m");
		if (!strcmp(read_line, "u ugly"))
			printf("(ಥ_ಥ)");
		else if (!strcmp(read_line, "what u looking"))
			printf("┻┳|―-∩\n┳┻|   ヽ\n┻┳| ●  |\n┳┻|▼)_ノ\n┻┳|￣ )\n┳ﾐ(￣／\n┻┳T￣|\n");
		else if (!strcmp(read_line, "f u"))
			printf("凸( •̀_•́ )凸");
		else if (!strcmp(read_line, "u mad?"))
			printf("ᕕ(˵•̀෴•́˵)ᕗ");
		else if (!strcmp(read_line, "beware the cat"))
			printf("ก₍⸍⸌̣ʷ̣̫⸍̣⸌₎ค");
		else if (read_line && *read_line)
			add_history(read_line);
		printf("\n");
		free(read_line);
	}
//	for(int i = 0; env[i]; i++)
	//	printf("%s\n", env[i]);

//	printf("%s\n", "");
}
