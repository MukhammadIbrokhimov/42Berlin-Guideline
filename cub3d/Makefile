# Program name
NAME			= cub3D

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -O3

# Directories
SRC_MANDATORY	= src_mandatory
SRC_BONUS		= src_bonus
OBJ_MANDATORY	= obj_mandatory
OBJ_BONUS		= obj_bonus
INCLUDES_MANDATORY = includes_mandatory
INCLUDES_BONUS	= includes_bonus
LIBFT_DIR		= Libft

# Platform detection
OS				= $(shell uname)
MAKE			= make -C
MKDIR			= mkdir -p
RM				= rm -rf

# Source files for mandatory version
MANDATORY_MAIN_FILES = main.c \
					  memory_management.c \
					  initialize_game_struct.c \
					  validations.c \
					  destroy_mlx_memory.c \
					  free_memory.c

MANDATORY_PARSING_FILES = parsing/parse_main.c \
						 parsing/parse_utils.c \
						 parsing/parse_rgb_texture.c \
						 parsing/parse_rgb_helper.c \
						 parsing/extract_map_statistics.c \
						 parsing/map_statistics.c \
						 parsing/wall_validation.c \
						 parsing/flood_fill.c

MANDATORY_GAME_FILES = game/game_init.c \
					  game/input_handling.c \
					  game/handle_keyboard_input.c \
					  game/player_movement.c

MANDATORY_RAYCAST_FILES = raycasting/raycasting.c \
						 raycasting/raycasting_utils.c \
						 raycasting/rendering.c \
						 raycasting/drawing.c \
						 raycasting/drawing_utils.c

# Source files for bonus version
BONUS_MAIN_FILES = main.c \
				  memory_management.c \
				  initialize_game_struct.c \
				  validations.c \
				  destroy_mlx_memory.c \
				  free_memory.c

BONUS_PARSING_FILES = parsing/parse_main.c \
					 parsing/parse_utils.c \
					 parsing/parse_rgb_texture.c \
					 parsing/parse_rgb_helper.c \
					 parsing/extract_map_statistics.c \
					 parsing/map_statistics.c \
					 parsing/wall_validation.c \
					 parsing/flood_fill.c

BONUS_GAME_FILES = game/game_init.c \
				  game/input_handling.c \
				  game/handle_keyboard_input.c \
				  game/player_movement.c \
				  game/game_init_bonus.c

BONUS_RAYCAST_FILES = raycasting/raycasting.c \
					 raycasting/raycasting_utils.c \
					 raycasting/rendering.c \
					 raycasting/drawing.c \
					 raycasting/drawing_utils.c \
					 raycasting/minimap.c \
					 raycasting/minimap_utils.c \
					 raycasting/rays_on_minimap.c

# All source files
MANDATORY_SRCS = $(addprefix $(SRC_MANDATORY)/, $(MANDATORY_MAIN_FILES) $(MANDATORY_PARSING_FILES) $(MANDATORY_GAME_FILES) $(MANDATORY_RAYCAST_FILES))
BONUS_SRCS = $(addprefix $(SRC_BONUS)/, $(BONUS_MAIN_FILES) $(BONUS_PARSING_FILES) $(BONUS_GAME_FILES) $(BONUS_RAYCAST_FILES))

# Object files
MANDATORY_OBJS = $(MANDATORY_SRCS:$(SRC_MANDATORY)/%.c=$(OBJ_MANDATORY)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(SRC_BONUS)/%.c=$(OBJ_BONUS)/%.o)

# Library files
LIBFT			= $(LIBFT_DIR)/libft.a

# Math library
MATH_LIB		= -lm

# Platform-specific MLX configuration
ifeq ($(OS), Linux)
	# Check if system MLX is available by looking for libmlx files
	# Try multiple common locations for system-installed MLX
	ifneq ($(shell find /usr/lib* /usr/local/lib* -name "libmlx*" 2>/dev/null | head -1), )
		# System MLX found
		MLX_LIB		= # No local MLX library needed
		INCLUDES_MLX = -I/usr/include -I/usr/local/include
		MLX_FLAGS	= -lmlx -lXext -lX11 
	else ifneq ($(shell ldconfig -p 2>/dev/null | grep libmlx), )
		# System MLX found via ldconfig
		MLX_LIB		= # No local MLX library needed
		INCLUDES_MLX = -I/usr/include -I/usr/local/include
		MLX_FLAGS	= -lmlx -lXext -lX11 
	else ifeq ($(shell test -d mlx_linux && echo "yes"), yes)
		# No system MLX, but mlx_linux folder exists
		MLX_DIR		= mlx_linux
		MLX_LIB		= $(MLX_DIR)/libmlx.a
		INCLUDES_MLX = -I$(MLX_DIR)
		MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 
	else
		# No MLX found anywhere - will try system MLX and let linker handle it
		MLX_LIB		= # No local MLX library needed
		INCLUDES_MLX = -I/usr/include -I/usr/local/include
		MLX_FLAGS	= -lmlx -lXext -lX11 
	endif
else ifeq ($(OS), Darwin)
	# macOS - use local mlx_macos
	MLX_DIR			= mlx_macos
	MLX_LIB			= $(MLX_DIR)/libmlx.a
	INCLUDES_MLX	= -I$(MLX_DIR)
	MLX_FLAGS		= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# Include flags
MANDATORY_INCLUDES = -I$(INCLUDES_MANDATORY) -I$(LIBFT_DIR) $(INCLUDES_MLX)
BONUS_INCLUDES = -I$(INCLUDES_BONUS) -I$(LIBFT_DIR) $(INCLUDES_MLX)

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

# Default target (mandatory version)
all: $(LIBFT) $(MLX_LIB) $(OBJ_MANDATORY) mandatory

# Mandatory version
mandatory: $(MANDATORY_OBJS) Makefile
	@echo "$(BUILD) $(GREEN)Compiling mandatory $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(MANDATORY_OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) $(MATH_LIB) -o $(NAME)
	@echo "$(SUCCESS) $(YELLOW)Mandatory $(NAME) FINISHED$(RESET)"

# Bonus version
bonus: $(LIBFT) $(MLX_LIB) $(OBJ_BONUS) bonus_build

bonus_build: $(BONUS_OBJS) Makefile
	@echo "$(BUILD) $(MAGENTA)Compiling bonus $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) $(MATH_LIB) -o $(NAME)
	@echo "$(MAGENTA)$(SUCCESS) Bonus $(NAME) FINISHED with all features enabled!$(RESET)"

# Create object directories
$(OBJ_MANDATORY):
	@$(MKDIR) $(OBJ_MANDATORY)

$(OBJ_BONUS):
	@$(MKDIR) $(OBJ_BONUS)

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

# Compile mandatory object files
$(OBJ_MANDATORY)/%.o: $(SRC_MANDATORY)/%.c
	@$(MKDIR) $(dir $@)
	@echo "$(YELLOW)Compiling mandatory $<...$(RESET)"
	@$(CC) $(CFLAGS) $(MANDATORY_INCLUDES) -c $< -o $@

# Compile bonus object files
$(OBJ_BONUS)/%.o: $(SRC_BONUS)/%.c
	@$(MKDIR) $(dir $@)
	@echo "$(YELLOW)Compiling bonus $<...$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

# Clean object files
clean:
	@$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)
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

# Re-bonus
re_bonus: fclean bonus

# Help target
help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)      - Build the mandatory version (default)"
	@echo "  $(GREEN)mandatory$(RESET) - Build the mandatory version explicitly"
	@echo "  $(GREEN)bonus$(RESET)    - Build the bonus version with all features"
	@echo "  $(GREEN)clean$(RESET)    - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)   - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)       - Rebuild the mandatory version"
	@echo "  $(GREEN)re_bonus$(RESET) - Rebuild the bonus version"
	@echo "  $(GREEN)help$(RESET)     - Show this help message"
	@echo "  $(GREEN)info$(RESET)     - Show project information"

# Check for coding style (if norminette is available)
norm:
	@if command -v norminette >/dev/null 2>&1; then \
		echo "$(BLUE)Checking coding style for mandatory...$(RESET)"; \
		norminette $(SRC_MANDATORY) $(INCLUDES_MANDATORY); \
		echo "$(BLUE)Checking coding style for bonus...$(RESET)"; \
		norminette $(SRC_BONUS) $(INCLUDES_BONUS); \
	else \
		echo "$(YELLOW)⚠️  norminette not found, skipping style check$(RESET)"; \
	fi

# Test the program with a sample map
test: $(NAME)
	@echo "$(CYAN)Testing with sample map...$(RESET)"
	@if [ -f maps/simple.cub ]; then \
		./$(NAME) maps/simple.cub; \
	else \
		echo "$(RED)❌ No test map found at maps/simple.cub$(RESET)"; \
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
	@echo "  Mandatory source files: $(GREEN)$(words $(MANDATORY_SRCS))$(RESET)"
	@echo "  Bonus source files: $(GREEN)$(words $(BONUS_SRCS))$(RESET)"
ifdef MLX_DIR
	@echo "  MLX: $(GREEN)Local ($(MLX_DIR))$(RESET)"
else
	@echo "  MLX: $(GREEN)System-installed$(RESET)"
endif
	@echo "  MLX Flags: $(GREEN)$(MLX_FLAGS)$(RESET)"

# Declare phony targets
.PHONY: all mandatory bonus bonus_build clean fclean re re_bonus help norm test install-deps info