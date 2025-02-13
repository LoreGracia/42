# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:35:38 by lgracia-          #+#    #+#              #
#    Updated: 2025/02/12 16:46:32 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -g  -fsanitize=address 

SRC = main.c

DSRC = $(addprefix src/, $(SRC))

OBJ = $(DSRC:.c=.o)

DEP = $(DSRC:.c=.d)

NAME = mini

all: $(NAME)

$(NAME): $(OBJ) 
	cc $(FLAGS) $(OBJ) -ltermcap -lreadline -o $(NAME)

%.o:%.c Makefile
	cc $(FLAGS) -MMD -o $@ -c $<

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
