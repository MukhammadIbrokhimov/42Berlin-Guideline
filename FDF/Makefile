# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 21:32:40 by mukibrok          #+#    #+#              #
#    Updated: 2024/12/30 21:37:54 by mukibrok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   fdf
LIBFT       =   libft/
GNL         =   get_nextline/
MLX         =   minilibx-linux/
LIBFT_A     =   $(addprefix $(LIBFT), libft.a)
GNL_A       =   $(addprefix $(GNL), libgnl.a)
MLX_A       =   $(addprefix $(MLX), libmlx.a)

CC          =   gcc
INCLUDE     =   includes
CFLAGS      =   -Wall -Wextra -Werror -I$(INCLUDE) -I$(MLX)
RM          =   rm -f
SRCS        =   fdf.c \

OBJS        =   $(SRCS:%.c=%.o)

# Graphics flags for Linux
GRAPHICS_FLAGS = -L/usr/lib -lGL -lGLU -lX11 -lXext

all:            $(NAME)

$(NAME):        $(OBJS) $(LIBFT_A) $(GNL_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx $(GRAPHICS_FLAGS) -lm -o $(NAME)
	@echo "Linked into executable \033[0;32mfdf\033[0m."

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "Compiled $(LIBFT_A)."

$(GNL_A):
	@$(MAKE) -s -C $(GNL)
	@echo "Compiled $(GNL_A)."

$(MLX_A):
	@$(MAKE) -s -C $(MLX)
	@echo "Compiled $(MLX_A)."

bonus:          all

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo "Compiling $<."

localclean:
	@$(RM) $(OBJS)
	@echo "Removed object files."

clean:          localclean
	@$(MAKE) clean -s -C $(LIBFT)
	@echo "Clean libft."
	@$(MAKE) clean -s -C $(GNL)
	@echo "Clean gnl."
	@$(MAKE) clean -s -C $(MLX)
	@echo "Clean mlx."

fclean:         localclean
	@$(MAKE) fclean -s -C $(LIBFT)
	@echo "Full clean libft."
	@$(MAKE) fclean -s -C $(GNL)
	@echo "Full clean gnl."
	@$(MAKE) clean -s -C $(MLX)
	@echo "Clean mlx."
	@$(RM) $(NAME)
	@echo "Removed executable."

re:             fclean all

.PHONY:         all clean fclean re localclean bonus
