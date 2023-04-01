# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 20:23:15 by nelallao          #+#    #+#              #
#    Updated: 2023/04/01 01:25:04 by nelallao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = 	mandatory/client.c \
			mandatory/minitalk_utils.c \

CLIENT_BONUS = bonus/client_bonus.c \
				bonus/minitalk_utils.c \

SERVER = mandatory/server.c

SERVER_BONUS = bonus/server_bonus.c


NAME = client
NAME_BONUS = client_bonus

NAME_2 = server
NAME_BONUS_2 = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = printf/libftprintf.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all : $(LIB) $(NAME) $(NAME_2)

$(NAME) : $(CLIENT)

	@$(CC) $(CFLAGS) $(LIB) $(CLIENT) -o $(NAME)
	@echo "$(COLOUR_GREEN)███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗"
	@echo "████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝ "
	@echo "██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝"
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗ "
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ "
	@echo "$(COLOUR_GREEN)\
█▀ █░█ █▀▀ █▀▀ █▀▀ █▀ █▀ █▀▀ █░█ █░░ █░░ █▄█   █▀▀ █▀█ █▀▄▀█ █▀█ █ █░░ █▀▀ █▀▄\n\
▄█ █▄█ █▄▄ █▄▄ ██▄ ▄█ ▄█ █▀░ █▄█ █▄▄ █▄▄ ░█░   █▄▄ █▄█ █░▀░█ █▀▀ █ █▄▄ ██▄ █▄▀$(COLOUR_END)"

$(NAME_2) : $(SERVER)
	@$(CC) $(CFLAGS) $(LIB) $(SERVER) -o $(NAME_2)

$(LIB):
	@make -C printf

bonus : $(LIB) $(NAME_BONUS) $(NAME_BONUS_2)

$(NAME_BONUS) : $(CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(LIB) $(CLIENT_BONUS) -o $(NAME_BONUS)

$(NAME_BONUS_2) : $(SERVER_BONUS)
	@$(CC) $(CFLAGS) $(LIB) $(SERVER_BONUS)  -o $(NAME_BONUS_2)
	@echo "$(COLOUR_BLUE)██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗"
	@echo "██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝"
	@echo "██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗"
	@echo "██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║"
	@echo "██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║"
	@echo "╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝"
	@echo "$(COLOUR_BLUE)\
█▀ █░█ █▀▀ █▀▀ █▀▀ █▀ █▀ █▀▀ █░█ █░░ █░░ █▄█   █▀▀ █▀█ █▀▄▀█ █▀█ █ █░░ █▀▀ █▀▄\n\
▄█ █▄█ █▄▄ █▄▄ ██▄ ▄█ ▄█ █▀░ █▄█ █▄▄ █▄▄ ░█░   █▄▄ █▄█ █░▀░█ █▀▀ █ █▄▄ ██▄ █▄▀$(COLOUR_END)"

clean :
	@make clean -C printf
	@rm -rf $(NAME)
fclean :
	@make fclean -C printf
	@rm -dfr ./client_bonus
	@rm -dfr ./client
	@rm -dfr ./server_bonus
	@rm -dfr ./server
re : fclean all
