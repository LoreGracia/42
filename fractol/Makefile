# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 12:21:03 by lgracia-          #+#    #+#              #
#    Updated: 2024/10/29 12:25:04 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = fractol

SRC = main.c  

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

LIBs =  ./printf/libftprintf.a ./build/libmlx42.a -ldl -lglfw -pthread -lm

INC = -I ./MLX/include

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	@$(MAKE) -C ./printf
	@cmake -B build ./MLX
	@cmake --build build -j4
	@cc -lm -g $(FLAGS) $(OBJ) $(LIBs) $(INC) -o $(NAME)
	@echo "Compiled"

%.o: %.c Makefile
	@cc $(FLAGS) -MMD -o $@ -c  $< $(INC)

clean:
	@rm $(OBJ) $(DEP)
	@echo "Cleaned"

fclean: clean
	@rm -r ./build
	@$(MAKE) -C ./printf fclean
	@rm $(NAME)
	@echo "Full cleaned"

re: fclean all

.PHONY: all clean fclean re
