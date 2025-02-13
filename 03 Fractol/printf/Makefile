# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 11:24:06 by lgracia-          #+#    #+#              #
#    Updated: 2024/08/02 13:52:15 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS =  -Wall -Wextra -Werror -I ./

NAME = libftprintf.a

HEADER = ft_printf.h 

FILES = files/ft_printf.c files/format.c files/character.c files/hexlow.c files/hexup.c files/pointer.c files/unsigne.c files/decimal.c files/string.c

OBJ = $(FILES:.c=.o)

DEPS = $(FILES:.c=.d)

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ) 

%.o:%.c Makefile
	cc $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -fr $(OBJ)
	rm -fr $(DEPS)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: clean re fclean all
