# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:35:38 by lgracia-          #+#    #+#              #
#    Updated: 2025/02/15 13:02:21 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini

CFLAGS = -Wall -Wextra -Werror -g  -fsanitize=address 

INCS = inc/

SRCS = main.c

DSRCS = $(addprefix src/, $(SRCS))

OBJS = $(DSRCS:.c=.o)

DEPS = $(DSRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -ltermcap -lreadline -o $(NAME)

%.o:%.c Makefile
	$(CC) $(CFLAGS) -I$(INCS) -MMD -o $@ -c $<

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
