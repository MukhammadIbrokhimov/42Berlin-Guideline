# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 21:32:40 by mukibrok          #+#    #+#              #
#    Updated: 2025/01/06 18:16:59 by mukibrok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -I$(INCLUDE)/minilibx-linux

# Directories
INCLUDE = include
SRC_DIR = src

# Libraries
LIBFT = $(INCLUDE)/libft
GNL = $(INCLUDE)/get_nextline
MLX = $(INCLUDE)/minilibx-linux
FT_PRINTF = $(INCLUDE)/ft_printf

LIBFT_A = $(LIBFT)/libft.a
FT_PRINTF_A = $(FT_PRINTF)/libftprintf.a
GNL_SRCS = $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c
MLX_A = $(MLX)/libmlx.a

# Executable
NAME = fdf

# Graphics flags for Linux
GRAPHICS_FLAGS = -L/usr/lib -lGL -lGLU -lX11 -lXext

# Sources and object files $(SRC_DIR)/other_file.c 
SRCS = $(SRC_DIR)/fdf.c $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

# Color codes
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

# Targets
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(FT_PRINTF_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf -L$(MLX) -lmlx $(GRAPHICS_FLAGS) -lm -o $(NAME)
	@echo "$(GREEN)Linked into executable $(NAME).$(RESET)"

# Compile libft
$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "$(GREEN)Compiled $(LIBFT_A).$(RESET)"

# Compile ft_printf
$(FT_PRINTF_A):
	@$(MAKE) -s -C $(FT_PRINTF)
	@echo "$(GREEN)Compiled $(FT_PRINTF_A).$(RESET)"

# Compile mlx
$(MLX_A):
	@$(MAKE) -s -C $(MLX)
	@echo "$(GREEN)Compiled $(MLX_A).$(RESET)"

# Compile object files from source files
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling $<...$(RESET)"

# Clean object files
clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -s -C $(LIBFT)
	@$(MAKE) clean -s -C $(FT_PRINTF)
	@$(MAKE) clean -s -C $(MLX)
	@echo "$(RED)Cleaned up object files and libraries.$(RESET)"

# Full clean (removes object files and executable)
fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT)
	@$(MAKE) fclean -s -C $(FT_PRINTF)
	@$(MAKE) clean -s -C $(MLX)
	@rm -f $(NAME)
	@echo "$(RED)Full clean completed, removed $(NAME).$(RESET)"

# Rebuild everything
re: fclean all
	@echo "$(GREEN)Rebuild completed successfully.$(RESET)"
