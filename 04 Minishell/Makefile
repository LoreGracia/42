# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:35:38 by lgracia-          #+#    #+#              #
#    Updated: 2025/02/18 14:39:27 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini

CFLAGS = -Wall -Wextra -Werror # -fsanitize=address 

INCS = inc/

SRCS = main.c lexer.c lexer_utils.c 

DSRCS = $(addprefix src/, $(SRCS))

OBJS = $(DSRCS:.c=.o)

DEPS = $(DSRCS:.c=.d)

LIBS =  ./libft/libft.a -ltermcap -lreadline

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
