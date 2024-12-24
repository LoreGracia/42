# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 17:50:56 by lgracia-          #+#    #+#              #
#    Updated: 2024/12/24 12:42:14 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror #-g

ACLIENT = client.c

ASERVER = server.c

ASRC = $(ASERVER) $(ACLIENT)

FSRC = src/

SSRC = $(addprefix $(FSRC),$(ASERVER))

CSRC = $(addprefix $(FSRC),$(ACLIENT))

SOBJ = $(SSRC:.c=.o)

COBJ = $(CSRC:.c=.o)

DEP = $(addprefix $(FSRC),$(ASRC:.c=.d))

SERVER = server 

CLIENT = client

LIBS = libft/libft.a printf/libftprintf.a

all: $(SERVER) $(CLIENT)

-include $(DEP)

$(SERVER): $(SOBJ)
	$(CC) $(CFLAGS) $(SOBJ) $(LIBS) -o $(SERVER)

$(CLIENT): $(COBJ)
	$(CC) $(CFLAGS) $(COBJ) $(LIBS) -o $(CLIENT)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

clean:
	rm -rf $(DEP) $(SOBJ) $(COBJ)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all


.PHONY: all clean fclean re
