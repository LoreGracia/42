/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:55 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/15 12:44:55 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
#define MINI_H

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
	char	command;
	char	**flag;
	char	**arg;
}				t_pipe;

typedef struct	s_env
{
	t_pipe	*pipes;
	int		num_pipes;
	char	file;
}				t_env;

#endif
