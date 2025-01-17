# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:35:38 by lgracia-          #+#    #+#              #
#    Updated: 2025/01/17 19:31:29 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

SRC = main.c philo.c death.c utils.c routine_task.c

DSRC = $(addprefix src/, $(SRC))

OBJ = $(DSRC:.c=.o)

DEP = $(DSRC:.c=.d)

NAME = philo

all: $(NAME)

$(NAME): $(OBJ) 
	cc $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.c Makefile
	cc $(FLAGS) -MMD -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
