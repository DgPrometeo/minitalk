# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 16:31:25 by danielga          #+#    #+#              #
#    Updated: 2023/07/15 19:59:09 by danielga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server
CLIENT	= client

NAME	= minitalk.a

SERVER_SRC	= server.c
CLIENT_SRC	= client.c

OBJS_SERVER	= ${SERVER_SRC:.c=.o}
OBJS_CLIENT	= ${CLIENT_SRC:.c=.o}

SRC_LIBFT	= ./libft
LIBFT = ./libft/libft.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	@make -C $(SRC_LIBFT)

$(SERVER): $(OBJS_SERVER)
	$(CC) -g $(CFLAGS) $(LIBFT) $(OBJS_SERVER) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_CLIENT) -o $(CLIENT)

clean: 
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)
	make clean -C ./libft
	
fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	make fclean -C ./libft

re: fclean all

.PHONY: all, clean, fclean, re
	