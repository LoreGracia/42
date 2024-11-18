# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 12:21:03 by lgracia-          #+#    #+#              #
#    Updated: 2024/11/18 18:29:51 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror # -fsanitize=address 

NAME = fractol

SRC = main.c Mandelbrot.c formulas_m.c julia.c M_formula.c Palette.c hooks.c panda.c line.c

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

LIBs =  ./Printf/libftprintf.a ./Libft/libft.a ./build/libmlx42.a -ldl -lglfw -pthread -lm

INC = -I ./MLX/include

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	@$(MAKE) -C ./Printf
	@$(MAKE) -C ./Libft
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
	@$(MAKE) -C ./Printf fclean
	@$(MAKE) -C ./Libft fclean
	@rm $(NAME)
	@echo "Full cleaned"

re: fclean all

.PHONY: all clean fclean re
