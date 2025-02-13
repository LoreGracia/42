/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:36 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/13 16:25:04 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	char *cosa;

	while ("O.O")
	{
		cosa = readline("\e[33m૮₍ ˃ ⤙ ˂ ₎ა\n./づ\e[0mᡕᠵ᠆ᠵ_⸝᠊᠆ᡁ᠊᠊\e[31m~~~~ \e[0m");
		if (!strcmp(cosa, "u ugly"))
			printf("(ಥ_ಥ)");
		if (!strcmp(cosa, "what u looking"))
			printf("┻┳|―-∩\n┳┻|   ヽ\n┻┳| ●  |\n┳┻|▼)_ノ\n┻┳|￣ )\n┳ﾐ(￣／\n┻┳T￣|\n");
		if (!strcmp(cosa, "f u"))
			printf("凸( •̀_•́ )凸");
		if (!strcmp(cosa, "u mad?"))
			printf("ᕕ(˵•̀෴•́˵)ᕗ");
		if (!strcmp(cosa, "beware the cat"))
			printf("ก₍⸍⸌̣ʷ̣̫⸍̣⸌₎ค");
		printf("\n");
		free(cosa);
	}
//	for(int i = 0; env[i]; i++)
	//	printf("%s\n", env[i]);

//	printf("%s\n", "");
}
