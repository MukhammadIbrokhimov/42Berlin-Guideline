/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:51:25 by gansari           #+#    #+#             */
/*   Updated: 2025/05/23 18:34:01 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_atof_data
{
	double	result;
	double	fraction;
	double	sign;
	double	power;
	double	exponent;
	double	exponent_sign;
	double	exponent_factor;
	int		decimal_found;
}	t_atof_data;

typedef struct s_snprintf_data
{
	char	*buffer;
	size_t	bufsize;
	size_t	written;
	size_t	pos;
}	t_snprintf_data;

typedef struct s_printf
{
	int		fd;
	int		width;
	int		precision;
	int		flags;
}	t_printf;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	*ft_itoa(int n);
double	ft_atof(const char *str);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strndup(const char *s, size_t n);
size_t	ft_strcspn(const char *s, const char *reject);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

int		ft_printf(const char *str, ...);
void	ft_putchar_printf(char c, size_t *i);
void	ft_putstr_printf(char *s, size_t *i);
void	ft_putnbr_printf(int nb, size_t *i);
void	ft_putnbr_base_printf(unsigned int nbr, char *base, size_t *i);
void	ft_putunsignednbr_printf(unsigned int nb, size_t *i);
void	ft_putptr_printf(void *ptr, size_t *i);

char	*get_next_line(int fd);

void	ft_error(char *str);
void	ft_perror(char *str);

int		ft_snprintf(char *str, size_t size, const char *format, ...);
void	ft_typecheck_snprintf(va_list args, char *str, t_snprintf_data *data);
void	ft_null_terminate(t_snprintf_data *data);
void	ft_putchar_snprintf(char c, t_snprintf_data *data);
void	ft_putstr_snprintf(char *s, t_snprintf_data *data);
void	ft_putnbr_snprintf(int nb, t_snprintf_data *data);
void	ft_putunsignednbr_snprintf(unsigned int nb, t_snprintf_data *data);
void	ft_putnbr_base_snprintf(unsigned int nbr, char *base,
			t_snprintf_data *data);
void	ft_putnbr_base_ptr_snprintf(unsigned long nbr, char *base,
			t_snprintf_data *data);
void	ft_putptr_snprintf(void *ptr, t_snprintf_data *data);

int		ft_fprintf(int fd, const char *format, ...);
int		write_char_fd(char c, int fd);
int		write_str_fd(char *s, int fd);
int		write_nbr_fd(int n, int fd);
int		print_char(t_printf *data, int c);
int		print_string(t_printf *data, char *str);
int		print_number(t_printf *data, int num);
int		write_ptr_fd(void *ptr, int fd);
int		print_pointer(t_printf *data, void *ptr);
int		print_hex(t_printf *data, unsigned int num, int uppercase);
int		write_hex_fd(unsigned long n, int uppercase, int fd);
int		write_hex_digit(int digit, int uppercase, int fd);

#endif
