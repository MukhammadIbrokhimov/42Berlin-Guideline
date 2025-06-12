# Color definitions
RESET      = \033[0m
RED        = \033[31m
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
CYAN       = \033[36m
BOLD       = \033[1m
UNDERLINE  = \033[4m

# Variables
CC        = cc
CFLAGS    = -Wall -Wextra -Werror -Iincludes -g
SRC_DIR   = ./src
OBJ_DIR   = obj

SRC       = $(SRC_DIR)/philo/main.c
SRC      += $(SRC_DIR)/philo/philosopher.c \
			$(SRC_DIR)/utils/init.c \
			$(SRC_DIR)/utils/utils.c \
			$(SRC_DIR)/utils/monitor.c \
			$(SRC_DIR)/utils/ft_atol.c \
			$(SRC_DIR)/utils/cleanup.c \

OBJ       = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
EXEC      = philo


# Default rule
all: $(EXEC)

# Compile the program
$(EXEC): $(OBJ)
	@echo "$(CYAN)🔨  Compiling...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)
	@echo "$(GREEN)✅  Compilation successful!$(RESET)"

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)📂  Creating object file: $@$(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/philo
	@mkdir -p $(OBJ_DIR)/utils

# Clean up object files
clean:
	@echo "$(RED)🧹  Deleting object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✅  Cleaned up object files!$(RESET)"



# Clean up all generated files
fclean: clean
	@echo "$(RED)🗑️   Deleting executable...$(RESET)"
	@rm -f $(EXEC)
	@echo "$(GREEN)✅  Executable deleted!$(RESET)"

# Rebuild
re: fclean all
	@echo "$(CYAN)🔄  Rebuilding everything...$(RESET)"

.PHONY: all clean fclean re