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

# Valgrind configuration
VALGRIND_FLAGS = --tool=helgrind --log-file=helgrind.log --verbose
# Default test arguments for philosophers (adjust as needed)
TEST_ARGS = 5 800 200 200 3

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

# Run valgrind helgrind
valgrind: $(EXEC)
	@echo "$(BLUE)🔍  Running Valgrind Helgrind...$(RESET)"
	@echo "$(YELLOW)📋  Test arguments: $(TEST_ARGS)$(RESET)"
	@valgrind $(VALGRIND_FLAGS) ./$(EXEC) $(TEST_ARGS)
	@echo "$(GREEN)✅  Valgrind analysis complete! Check helgrind.log for details.$(RESET)"
	@echo "$(CYAN)💡  To view the log: cat helgrind.log$(RESET)"

# Run valgrind with custom arguments
valgrind-custom: $(EXEC)
	@echo "$(BLUE)🔍  Running Valgrind Helgrind with custom arguments...$(RESET)"
	@echo "$(YELLOW)Usage: make valgrind-custom ARGS=\"your arguments here\"$(RESET)"
	@valgrind $(VALGRIND_FLAGS) ./$(EXEC) $(ARGS)
	@echo "$(GREEN)✅  Valgrind analysis complete! Check helgrind.log for details.$(RESET)"

# Clean up object files
clean:
	@echo "$(RED)🧹  Deleting object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✅  Cleaned up object files!$(RESET)"

# Clean up all generated files
fclean: clean
	@echo "$(RED)🗑️   Deleting executable...$(RESET)"
	@rm -f $(EXEC)
	@echo "$(RED)🗑️   Deleting valgrind logs...$(RESET)"
	@rm -f helgrind.log
	@echo "$(GREEN)✅  All files cleaned!$(RESET)"

# Rebuild
re: fclean all
	@echo "$(CYAN)🔄  Rebuilding everything...$(RESET)"

.PHONY: all clean fclean re valgrind valgrind-custom
