# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Debugger flags
DEBUG_FLAGS = -fsanitize=address -g

# Executables
PUSH_SWAP = push_swap
# CHECKER = checker

# Directories
INCLUDE_DIR = include
LIBFT_DIR = $(INCLUDE_DIR)/libft
FT_PRINTF_DIR = $(INCLUDE_DIR)/ft_printf

LIBFT_LIB = $(LIBFT_DIR)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# Sources
PUSH_SWAP_SRC = push_swap.c utils.c utils2.c sorting.c steps.c findMedian.c
# CHECKER_SRC = checker.c operations.c utils.c

# Object files
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
# CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

# Rules
all: $(LIBFT_LIB) $(FT_PRINTF_LIB) $(PUSH_SWAP) $(CHECKER)

# Build the push_swap executable
$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB) -o $(PUSH_SWAP)
	@echo "\033[0;32mpush_swap compiled successfully!\033[0m"

# Debug build for push_swap
debug: CFLAGS += $(DEBUG_FLAGS)
debug: re
	@echo "\033[0;36mDebug build with AddressSanitizer enabled!\033[0m"

# Build the checker executable
# $(CHECKER): $(CHECKER_OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB)
# 	@$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB) -o $(CHECKER)
# 	@echo "\033[0;32mchecker compiled successfully!\033[0m"

# Compile libft library
$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "\033[0;32mlibft library built successfully!\033[0m"

# Compile ft_printf library
$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "\033[0;32mft_printf library built successfully!\033[0m"

# Clean up object files in the main directory
clean:
	@$(RM) $(PUSH_SWAP_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@echo "\033[0;33mMain project object files removed!\033[0m"

# Remove all generated files
fclean: clean
	@$(RM) $(PUSH_SWAP)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@echo "\033[0;33mAll project files removed!\033[0m"

# Rebuild everything
re: fclean all

# PHONY targets
.PHONY: all clean fclean re debug
