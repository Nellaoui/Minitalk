# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 20:23:15 by nelallao          #+#    #+#              #
#    Updated: 2023/03/22 00:09:52 by nelallao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.c

SERVER = server.c 

# SRC = minitalk_utils.c

NAME = client

NAME_2 = server

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = printf/libftprintf.a

# all : $(NAME) $(NAME_2)
all : $(LIB) $(NAME) $(NAME_2)

$(NAME) :
	$(CC) $(CFLAGS) $(LIB) $(CLIENT) $(UTILS) -o $(NAME)

$(NAME_2) :
	$(CC) $(CFLAGS) $(LIB) $(SERVER) $(UTILS) -o $(NAME_2)

$(LIB):
	make -C printf
clean :
	rm -rf $(NAME)

fclean : 
	rm -fr $(NAME)

re : fclean all