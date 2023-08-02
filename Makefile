# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 16:31:25 by danielga          #+#    #+#              #
#    Updated: 2023/08/02 16:57:53 by danielga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	= server
CLIENT	= client

NAME	= minitalk.a

SERVER_SRC	= server.c
CLIENT_SRC	= client.c

OBJS_SERVER	= ${SERVER_SRC:.c=.o}
OBJS_CLIENT	= ${CLIENT_SRC:.c=.o}

SERVER_SRC_BONUS	= server_bonus.c
CLIENT_SRC_BONUS	= client_bonus.c

OBJS_SERVER_BONUS = ${SERVER_SRC_BONUS:.c=.o}
OBJS_CLIENT_BONUS = ${CLIENT_SRC_BONUS:.c=.o}

SRC_LIBFT	= ./libft
LIBFT = ./libft/libft.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

all: $(NAME)

$(NAME):  $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	@make -C $(SRC_LIBFT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_SERVER) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_CLIENT) -o $(CLIENT)

clean: 
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)
	make clean -C ./libft
	$(RM) $(OBJS_SERVER_BONUS)
	$(RM) $(OBJS_CLIENT_BONUS)
	
fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	make fclean -C ./libft

re: fclean all

bonus: $(LIBFT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_CLIENT_BONUS) -o $(CLIENT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS_SERVER_BONUS) -o $(SERVER)

.PHONY: all, clean, fclean, re, bonus
	