# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 18:31:20 by mukibrok          #+#    #+#              #
#    Updated: 2024/11/16 09:40:37 by mukibrok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
RANLIB = ranlib

# executable name
NAME = libft.a

# files
SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strdup.c ft_strchr.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_strlen.c ft_strncmp.c ft_substr.c \
		ft_tolower.c ft_toupper.c ft_itoa.c ft_striteri.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c \
			ft_lstiter.c

# Object files
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# rules
all: $(NAME)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target for creating the static library (libft.a)
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

# Target for the bonus part, includes both normal and bonus object files
bonus: $(NAME) $(BONUS_OBJ)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
	$(RANLIB) $(NAME)

# Clean object files and bonus object files
clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

# Clean everything (object files and library)
fclean: clean
	$(RM) $(NAME)

# Rebuild everything (fclean + all)
re: fclean all

.PHONY: all clean fclean re bonus
