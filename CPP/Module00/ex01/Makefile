# Color definitions
RESET   = \033[0m       # Reset color
RED     = \033[31m      # Red text
GREEN   = \033[32m      # Green text
YELLOW  = \033[33m      # Yellow text
BLUE    = \033[34m      # Blue text
CYAN    = \033[36m      # Cyan text
BOLD    = \033[1m       # Bold text
UNDERLINE = \033[4m     # Underlined text

# Variables
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98
SRC     = $(wildcard *.cpp)
OBJ     = $(SRC:.cpp=.o)
EXEC    = phonebook

# Default rule
all: $(EXEC)

# Compile the program
$(EXEC): $(OBJ)
	@echo "$(CYAN)🔨  Compiling...$(RESET)"
	@$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)
	@echo "$(GREEN)✅  Compilation successful!$(RESET)"

# Object files
%.o: %.cpp
	@echo "$(YELLOW)📂  Creating object file: $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	@echo "$(RED)🧹  Deleting object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(GREEN)✅  Cleaned up object files!$(RESET)"

# Clean up all generated files
fclean: clean
	@echo "$(RED)🗑️  Deleting executable...$(RESET)"
	@rm -f $(EXEC)
	@echo "$(GREEN)✅  Executable deleted!$(RESET)"

# Rebuild everything
re: fclean all
	@echo "$(CYAN)🔄  Rebuilding everything...$(RESET)"

# Phony targets
.PHONY: all clean fclean re