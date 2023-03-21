# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 20:23:15 by nelallao          #+#    #+#              #
#    Updated: 2023/03/21 21:41:46 by nelallao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.c

SERVER = server.c 

SRC = minitalk_utils.c

NAME = client

NAME_2 = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME) $(NAME_2)

$(NAME) :
	$(CC) $(CFLAGS) $(CLIENT) $(UTILS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : 
	rm -fr $(NAME)

re : fclean all