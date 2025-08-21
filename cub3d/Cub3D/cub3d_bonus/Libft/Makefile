SRC_DIR = src/
SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
       ft_isprint.c ft_isspace.c ft_toupper.c ft_tolower.c \
       ft_atoi.c ft_itoa.c ft_atol.c ft_atof.c\
       get_next_line_bonus.c \
       ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstmap.c \
       ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
       ft_lstiter.c \
       ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c \
       ft_memchr.c ft_memcmp.c ft_calloc.c \
       ft_printf.c ft_putchar_printf.c ft_putstr_printf.c ft_putnbr_printf.c \
       ft_putnbr_base_printf.c ft_putunsignednbr_printf.c ft_putptr_printf.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c \
       ft_strchr.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_striteri.c \
       ft_strmapi.c ft_split.c ft_error.c ft_perror.c \
       ft_strcmp.c ft_strndup.c ft_strcspn.c\
       ft_snprintf.c ft_snprintf_utils.c\
       ft_fprintf.c ft_fprintf_utils.c ft_fprintf_utils2.c ft_fprintf_utils3.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${INC}
	@${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
