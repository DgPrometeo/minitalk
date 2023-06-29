# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 19:45:27 by danielga          #+#    #+#              #
#    Updated: 2023/01/20 18:24:00 by danielga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program that the library will have.
NAME = libftprintf.a

# The flags with which we will compile the functions.
CFLAGS = -Wall -Wextra -Werror

# The command compile the functions.
CC = gcc

# All the files of the functions it will host.
SOURCE = ft_printf.c ft_printchar.c ft_printstr.c ft_printnbr.c ft_print_unsig_nbr.c ft_printhex.c
	 
# To make the library, convert functions (*.c) to objects (*.o) with the -c flag.
OBJS = $(SOURCE:.c=.o)

# Indicates the header of the library.
HEADER = ft_printf.h

# When you enter "make" or "make all" it will carry out these instructions.
all:	$(NAME)

#It will compile the functions and create the library with ar.
#(c create, r replace, s make #index).
$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

#Deletes all *.o files created in the process.
clean:
	rm -rf $(OBJS)

#It will first delete the *.o and then delete the program.
fclean:	clean
	rm -f $(NAME)

#It will delete the program and the .o and run the process again.
re:	fclean all

#This is to indicate to make that these commands have been given specific instructions.
.PHONY: all clean fclean re bonus