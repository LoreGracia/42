# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:35:38 by lgracia-          #+#    #+#              #
#    Updated: 2025/03/22 19:02:28 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini

CFLAGS = -Wall -Wextra -Werror  -g# -fsanitize=address 

INCS = inc/

SRCS = main.c lexer.c split_token.c split_token_utils.c expander.c 

DSRCS = $(addprefix src/, $(SRCS))

OBJS = $(DSRCS:.c=.o)

DEPS = $(DSRCS:.c=.d)

LIBS =  ./libft/libft.a -ltermcap -lreadline

CC = cc

all: $(NAME)

$(NAME): $(OBJS) 
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o:%.c Makefile
	$(CC) $(CFLAGS) -I$(INCS) -MMD -o $@ -c $<

clean:
	@$(MAKE) -C ./libft fclean
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
