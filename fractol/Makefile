# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 12:21:03 by lgracia-          #+#    #+#              #
#    Updated: 2024/11/30 17:56:40 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror  -fsanitize=address 

NAME = fractol

SRC = main.c mandelbrot.c formulas_m.c m_formula.c palette.c hooks.c utils.c panda.c line.c

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

LIBs =  ./printf/libftprintf.a ./libft/libft.a ./build/libmlx42.a -ldl -lglfw -pthread -lm

INC = -I ./MLX/include

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	@$(MAKE) -C ./printf
	@$(MAKE) -C ./libft
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
	@$(MAKE) -C ./libft fclean
	@rm $(NAME)
	@echo "Full cleaned"

re: fclean all

.PHONY: all clean fclean re
