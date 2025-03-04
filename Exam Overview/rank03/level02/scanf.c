/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:21:39 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/04 16:44:09 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>


void	skip_intput_space(void){
	int c;

	while ((c = fgetc(stdin)) != EOF){
		if (!isspace(c)){
			ungetc(c, stdin);
			break;
		}
	}
}

int scan_char(va_list ap){
	char *ptr = va_arg(ap, char *);
	skip_intput_space();
	int c = fgetc(stdin);
	if (c == EOF) return (-1);
	*ptr = (char) c;
	return (1);
}

int scan_int(va_list ap){
	int sign = 1;
	int number = 0;
	int *ptr = va_arg(ap, int *);
	skip_intput_space();
	int c = fgetc(stdin);
	if (c == EOF) return -1;
	if (c == '-'){
		sign = -1;
		c = fgetc(stdin);
	}
	if (!isdigit(c)) return -1;
	while (isdigit(c)){
		number = number * 10 + (c - 48);
		c = fgetc(stdin);
	}
	ungetc(c, stdin);
	*ptr = number * sign;
	return (1);
}

int scan_string(va_list ap){
	char *ptr = va_arg(ap, char *);
	skip_intput_space();
	int c;
	int i = 0;
	while ((c = fgetc(stdin)) != EOF && !isspace(c)){
		ptr[i] = c;
		i++;
	}
	ptr[i] = '\0';
	return (1);
}

int	checkinput(const char *format, va_list ap){
	switch (*format){
		case 'c':
			return (scan_char(ap));
		case 'd':
			return (scan_int(ap));
		case 's':
			return (scan_string(ap));
		default:
			return (-1);
	}
}


int ft_scanf(const char *format, ...){
	va_list ptr;

	va_start(ptr, format);
	int i = 0;
	int result = 0;
	while (format[i]){
		if (format[i] == '%'){
			i++;
			if ((checkinput(&(format[i]), ptr)) == -1)
				break ;
			else
				result ++;
		}
		i++;
	}
	return (result);
}


int	main(void){
	int		num;
	int		num1;
	char	c;
	char	c1;
	char	str[20];
	char	str1[20];

	printf("Provide me with letter: ");
	ft_scanf("    %c", &c);
	//scanf("    %c", &c1);
	printf("ft_scanf letter: %c\n", c);
	//printf("scanf letter: %c\n", c1);

	printf("-----------------------------");
	printf("Provide me with number: ");
	ft_scanf("     %d", &num);
	//scanf("     %d", &num1);
	printf("ft_scanf number: %d\n", num);
	//printf("scanf number: %d\n", num1);
	printf("-----------------------------");

	printf("Provide me with string: ");
	ft_scanf("%s", str);
	//scanf("%s", str1);
	printf("ft_scanf string: %s\n", str);
	//printf("scanf string: %s\n", str1);
	printf("-----------------------------");

}