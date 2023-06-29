# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danielga <danielga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 13:52:08 by danielga          #+#    #+#              #
#    Updated: 2023/01/12 15:56:44 by danielga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program that the library will have.
NAME = libft.a

# The flags with which we will compile the functions.
CFLAGS = -Wall -Wextra -Werror

# The command compile the functions.
CC = gcc

# All the files of the functions it will host.
SOURCE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		 ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		 ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
	 
# To make the library, convert functions (*.c) to objects (*.o) with the -c flag.
OBJS = $(SOURCE:.c=.o)

# To make the library, convert the bonus functions (*.c) to objects (*.o).
OBJSBONUS = $(SRCBONUS:.c=.o)

# Indicates the header of the library.
HEADER = libft.h

# When you enter "make" or "make all" it will carry out these instructions.
all:	$(NAME)

#It will compile the functions and create the library with ar.
#(c create, r replace, s make #index).
$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

#Deletes all *.o files created in the process.
clean:
	rm -rf $(OBJS)
	rm -rf $(OBJSBONUS)

#It will first delete the *.o and then delete the program.
fclean:	clean
	rm -f $(NAME)

#It will delete the program and the .o and run the process again.
re:	fclean all

#It will compile the bonus functions and create the library with ar.
bonus: $(OBJSBONUS)
	ar -crs $(NAME) $(OBJSBONUS)

#This is to indicate to make that these commands have been given specific instructions.
.PHONY: all clean fclean re bonus