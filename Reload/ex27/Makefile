# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 14:38:15 by lgracia-          #+#    #+#              #
#    Updated: 2024/06/16 19:41:20 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

FILES = ft_display_file.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c Makefile
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror $(FILES) -o $(NAME)

clean:
	rm -r $(OBJ)

fclean: clean
	rm -r $(NAME)

re: fclean all
