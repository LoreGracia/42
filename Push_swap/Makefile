# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 16:01:28 by lgracia-          #+#    #+#              #
#    Updated: 2024/10/21 12:04:17 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -fsanitize=address

NAME = push_swap

SRC = main.c ft_check.c ft_move.c ft_sort_small_stack.c ft_double_moves.c ft_sort_big_stack_r.c 

OBJ = $(SRC:.c=.o)

DEP = $(SRC:.c=.d)

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ) Makefile
	@$(MAKE) -C ./libft
	@cc $(FLAGS) -g -MMD $(OBJ) ./libft/libft.a -o $(NAME)
	@echo "Compiled"
%.o: %.c
	cc $(FLAGS) -g -MMD -c $< -o $@

clean:
	@$(MAKE) -C ./libft fclean
	@rm $(OBJ) $(DEP)
	@echo "Cleaned"

fclean: clean
	@rm $(NAME)
	@echo "Full cleaned"

re: fclean all

.PHONY: all clean fclean re
