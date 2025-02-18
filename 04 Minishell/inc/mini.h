/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:55 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/18 13:52:34 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
#define MINI_H

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include <termios.h>

typedef struct	s_pipe
{
	char	*command;
	char	**flag;
	char	**arg;
}				t_pipe;

typedef struct	s_env
{
	t_pipe	*pipe;
	int		num_pipes;
	char	file;
}				t_env;

int		ccount(char *read_line, char c);
t_pipe	*lexer_init(char *readline, t_env *env);

#endif
