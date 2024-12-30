# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhammadqodirmaxmudov <muhammadqodirmax    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 23:42:43 by muxammad          #+#    #+#              #
#    Updated: 2024/11/26 00:45:19 by muhammadqod      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
RANLIB = ranlib

# executable name
NAME = libftprintf.a

# files
SRC = ft_printf.c print_nbr.c print_str.c

# Object files
OBJ = $(SRC:.c=.o)

# rules
all: $(NAME)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target for creating the static library (libftprintf.a)
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

clean:
	$(RM) $(OBJ)

# Clean everything (object files and library)
fclean: clean
	$(RM) $(NAME)

# Rebuild everything (fclean + all)
re: fclean all

.PHONY: all clean fclean re