# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 16:31:25 by danielga          #+#    #+#              #
#    Updated: 2023/06/29 17:23:18 by danielga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server
NAME2	= client

HEADER	= minitalk.h

SERVER	= server.c
CLIENT	= client.c

OBJS_SERVER	= ${SERVER:.c=.o}
OBJS_CLIENT	= ${CLIENT:.c=.o}

LIBFT	= ./libft
LIBPRINTF	= ./ft_printf

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

all: $(LIBFT) $(LIBPRINTF) $(NAME) $(NAME2)

$(LIBFT):
	make -C ./libft

$(LIBPRINTF):
	make -C ./ft_printf

$(NAME): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME)

$(NAME2): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME2)

clean: 
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)
	make clean -C ./libft
	make clean -C ./ft_printf
	
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)
	make fclean -C ./libft
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all, clean, fclean, re
	