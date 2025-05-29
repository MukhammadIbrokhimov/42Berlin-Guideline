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
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRC_DIR   = src
OBJ_DIR   = obj
SRC       = $(shell find $(SRC_DIR) -name '*.c')
OBJ       = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
EXEC      = philo

# Default rule
all: $(EXEC)

# Compile the program
$(EXEC): $(OBJ)
	@echo "$(CYAN)🔨  Compiling...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)✅  Compilation successful!$(RESET)"

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)📂  Creating object file: $@$(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	@echo "$(RED)🧹  Deleting object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✅  Cleaned up object files!$(RESET)"

# Clean up everything
fclean: clean
	@echo "$(RED)🗑️   Deleting executable...$(RESET)"
	@rm -f $(EXEC)
	@echo "$(GREEN)✅  Executable deleted!$(RESET)"

# Rebuild
re: fclean all
	@echo "$(CYAN)🔄  Rebuilding everything...$(RESET)"

.PHONY: all clean fclean re