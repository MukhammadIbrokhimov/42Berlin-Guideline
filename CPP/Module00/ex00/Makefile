# Makefile for megaphone (ex00)

# Compiler and flags
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# Colors
GREEN       = \033[1;32m
RED         = \033[1;31m
RESET       = \033[0m

# Program name
NAME        = megaphone

# Source files
SRC         = megaphone.cpp

# Object files directory
OBJ_DIR     = obj

# Object files
OBJ         = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Default target (build executable)
all: $(NAME)

# Link object files to create executable
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $^ -o $@

# Compile source files to object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Creating object: $<$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove object files and directory
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Cleaned object files$(RESET)"

# Remove executable and object files
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed executable$(RESET)"

# Rebuild everything
re: fclean all

# Phony targets (not actual files)
.PHONY: all clean fclean re
