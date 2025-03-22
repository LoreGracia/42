/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:55 by lgracia-          #+#    #+#             */
/*   Updated: 2025/03/22 19:19:34 by lgracia-         ###   ########.fr       */
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
	char	**token;
	int		fd;
	int		*num_flags;
	int		*num_arg;
	void	*next;
}				t_pipe;

typedef struct	s_env
{
	t_pipe	*pipe;
	int		num_pipes;
	char	**env;
	int		file;
}				t_env;

int		ccount(char *read_line, char c);
int		chrccount(char *read_line, char c);
char	*expand(char *s, int *start, char **env);
t_pipe	*lexer_init(char *readline, t_env env);
void	words(char *, char c, int *old);
char	**remallocstr(char **str, int count);
void	*full_free(char **str, int words);
char	**split_token(char *s, char c, char **env);
void	print_token(t_pipe *pipe, int num_pipes);

#endif
