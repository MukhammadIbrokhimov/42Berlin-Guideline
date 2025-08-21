# Program name
NAME			= cub3D

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -O3

# Directories
SRC_DIR			= src
OBJ_DIR			= obj
INCLUDES_DIR	= includes
LIBFT_DIR		= Libft

# Platform detection
OS				= $(shell uname)
MAKE			= make -C
MKDIR			= mkdir -p
RM				= rm -rf

# Source files (updated to match your original structure)
MAIN_FILES		= main.c \
				  memory_management.c \
				  initialize_game_struct.c \
				  validations.c \
				  destroy_mlx_memory.c \
				  free_memory.c \

PARSING_FILES	= parsing/parse_main.c \
				  parsing/parse_utils.c \
				  parsing/parse_rgb_texture.c \
				  parsing/parse_rgb_helper.c \
				  parsing/map_statistics.c \
				  parsing/wall_validation.c \
				  parsing/extract_map_statistics.c

GAME_FILES		= game/game_init.c \
				  game/input_handling.c \
				  game/player_movement.c \
				  game/game_init_bonus.c

RAYCAST_FILES	= raycasting/raycasting.c \
				  raycasting/raycasting_utils.c \
				  raycasting/rendering.c \
				  raycasting/drawing.c \
				  raycasting/drawing_utils.c \

# Bonus files (minimap is bonus feature)
BONUS_FILES		= raycasting/minimap.c

# All source files
SRCS			= $(addprefix $(SRC_DIR)/, $(MAIN_FILES) $(PARSING_FILES) $(GAME_FILES) $(RAYCAST_FILES))

# Add bonus files when bonus flag is set
ifdef BONUS
	SRCS		+= $(addprefix $(SRC_DIR)/, $(BONUS_FILES))
	CFLAGS		+= -DBONUS
endif

# Object files
OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Library files
LIBFT			= $(LIBFT_DIR)/libft.a

# Include flags
INCLUDES		= -I$(INCLUDES_DIR) -I$(LIBFT_DIR)

# Math library
MATH_LIB		= -lm

# Platform-specific MLX configuration
ifeq ($(OS), Linux)
	# Check if system MLX is available by looking for libmlx files
	# Try multiple common locations for system-installed MLX
	ifneq ($(shell find /usr/lib* /usr/local/lib* -name "libmlx*" 2>/dev/null | head -1), )
		# System MLX found
		MLX_LIB		= # No local MLX library needed
		INCLUDES	+= -I/usr/include -I/usr/local/include
		MLX_FLAGS	= -lmlx -lXext -lX11 
	else ifneq ($(shell ldconfig -p 2>/dev/null | grep libmlx), )
		# System MLX found via ldconfig
		MLX_LIB		= # No local MLX library needed
		INCLUDES	+= -I/usr/include -I/usr/local/include
		MLX_FLAGS	= -lmlx -lXext -lX11 
	else ifeq ($(shell test -d mlx_linux && echo "yes"), yes)
		# No system MLX, but mlx_linux folder exists
		MLX_DIR		= mlx_linux
		MLX_LIB		= $(MLX_DIR)/libmlx.a
		INCLUDES	+= -I$(MLX_DIR)
		MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 
	else
		# No MLX found anywhere - will try system MLX and let linker handle it
		MLX_LIB		= # No local MLX library needed
		INCLUDES	+= -I/usr/include -I/usr/local/include
		MLX_FLAGS	= -lmlx -lXext -lX11 
	endif
else ifeq ($(OS), Darwin)
	# macOS - use local mlx_macos
	MLX_DIR			= mlx_macos
	MLX_LIB			= $(MLX_DIR)/libmlx.a
	INCLUDES		+= -I$(MLX_DIR)
	MLX_FLAGS		= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# Colors for pretty output
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
WHITE			= \033[0;37m
RESET			= \033[0m

# Emojis
SUCCESS			= ✅
BUILD			= 🔨
CLEAN			= 🧹

# ================================== RULES =================================== #

# Default target
all: check_build_type $(LIBFT) $(MLX_LIB) $(OBJ_DIR) $(NAME)

# Check if we need to rebuild due to build type change
check_build_type:
	@if [ -f .bonus_flag ] && [ ! "$(BONUS)" = "1" ]; then \
		echo "$(YELLOW)⚠️  Previous build was bonus, cleaning for regular build...$(RESET)"; \
		$(RM) $(OBJ_DIR) $(NAME) .bonus_flag; \
	elif [ ! -f .bonus_flag ] && [ "$(BONUS)" = "1" ]; then \
		echo "$(YELLOW)⚠️  Previous build was regular, cleaning for bonus build...$(RESET)"; \
		$(RM) $(OBJ_DIR) $(NAME); \
	fi

# Create object directory
$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

# Build libft
$(LIBFT):
	@echo "$(BUILD) $(CYAN)Making libft...$(RESET)"
	@$(MAKE) $(LIBFT_DIR) --no-print-directory
	@echo "$(SUCCESS) $(YELLOW)Made libft!$(RESET)"

# Build MinilibX (only if MLX_DIR is defined - local MLX)
ifdef MLX_DIR
$(MLX_LIB):
	@echo "$(BUILD) $(CYAN)Making MinilibX ($(MLX_DIR))...$(RESET)"
	@$(MAKE) $(MLX_DIR) --no-print-directory
	@echo "$(SUCCESS) $(YELLOW)Made MinilibX!$(RESET)"
endif

# Create the main executable
$(NAME): $(OBJS) Makefile
	@echo "$(BUILD) $(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) $(MATH_LIB) -o $(NAME)
ifdef BONUS
	@touch .bonus_flag
endif
	@echo "$(SUCCESS) $(YELLOW)Compiling $(NAME) FINISHED$(RESET)"

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) .bonus_flag
	@$(MAKE) $(LIBFT_DIR) clean --no-print-directory
ifdef MLX_DIR
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) $(MLX_DIR) clean --no-print-directory; fi
endif
	@echo "$(CLEAN) $(RED)Cleaned!$(RESET)"

# Clean everything
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) $(LIBFT_DIR) fclean --no-print-directory
ifdef MLX_DIR
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) $(MLX_DIR) fclean --no-print-directory 2>/dev/null || true; fi
endif
	@echo "$(CLEAN) $(RED)Full Cleaned!$(RESET)"

# Rebuild everything
re: fclean all

# Bonus target (with additional features) - smart rebuild
bonus: 
	@if [ -f .bonus_flag ] && [ -f $(NAME) ] && [ "$(shell find $(SRC_DIR) -name '*.c' -newer .bonus_flag 2>/dev/null)" = "" ]; then \
		echo "$(MAGENTA)$(SUCCESS) Bonus version already up to date!$(RESET)"; \
	else \
		echo "$(BUILD) $(MAGENTA)Building bonus version...$(RESET)"; \
		$(MAKE) . BONUS=1 --no-print-directory; \
		echo "$(MAGENTA)$(SUCCESS) Bonus features enabled!$(RESET)"; \
	fi

# Help target
help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Build the project"
	@echo "  $(GREEN)clean$(RESET)   - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)      - Rebuild the project"
	@echo "  $(GREEN)bonus$(RESET)   - Build with bonus features"
	@echo "  $(GREEN)help$(RESET)    - Show this help message"
	@echo "  $(GREEN)info$(RESET)    - Show project information"

# Check for coding style (if norminette is available)
norm:
	@if command -v norminette >/dev/null 2>&1; then \
		echo "$(BLUE)Checking coding style...$(RESET)"; \
		norminette $(SRC_DIR) $(INCLUDES_DIR); \
	else \
		echo "$(YELLOW)⚠️  norminette not found, skipping style check$(RESET)"; \
	fi

# Test the program with a sample map
test: $(NAME)
	@echo "$(CYAN)Testing with sample map...$(RESET)"
	@if [ -f maps/sample.cub ]; then \
		./$(NAME) maps/sample.cub; \
	else \
		echo "$(RED)❌ No test map found at maps/sample.cub$(RESET)"; \
	fi

# Install dependencies
install-deps:
	@echo "$(BLUE)Installing dependencies...$(RESET)"
ifeq ($(OS), Linux)
	@if command -v apt >/dev/null 2>&1; then \
		sudo apt update && sudo apt install -y build-essential libx11-dev libxext-dev; \
		echo "$(GREEN)✅ Dependencies installed for Ubuntu/Debian$(RESET)"; \
	elif command -v yum >/dev/null 2>&1; then \
		sudo yum groupinstall -y "Development Tools" && sudo yum install -y libX11-devel libXext-devel; \
		echo "$(GREEN)✅ Dependencies installed for RHEL/CentOS$(RESET)"; \
	elif command -v pacman >/dev/null 2>&1; then \
		sudo pacman -S base-devel libx11 libxext; \
		echo "$(GREEN)✅ Dependencies installed for Arch Linux$(RESET)"; \
	else \
		echo "$(YELLOW)⚠️  Package manager not detected. Please install X11 and Xext development libraries manually.$(RESET)"; \
	fi
else ifeq ($(OS), Darwin)
	@echo "$(GREEN)On macOS, using local MinilibX from $(MLX_DIR)$(RESET)"
endif

# Show project info
info:
	@echo "$(CYAN)Project Information:$(RESET)"
	@echo "  Name: $(GREEN)$(NAME)$(RESET)"
	@echo "  Compiler: $(GREEN)$(CC)$(RESET)"
	@echo "  Flags: $(GREEN)$(CFLAGS)$(RESET)"
	@echo "  Platform: $(GREEN)$(OS)$(RESET)"
	@echo "  Source files: $(GREEN)$(words $(SRCS))$(RESET)"
	@echo "  Object files: $(GREEN)$(words $(OBJS))$(RESET)"
ifdef MLX_DIR
	@echo "  MLX: $(GREEN)Local ($(MLX_DIR))$(RESET)"
else
	@echo "  MLX: $(GREEN)System-installed$(RESET)"
endif
	@echo "  MLX Flags: $(GREEN)$(MLX_FLAGS)$(RESET)"

# Declare phony targets
.PHONY: all clean fclean re bonus help norm test install-deps info check_build_type