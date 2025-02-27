/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hta-rezi1 <hta-rezi1@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 03:30:30 by hta-rezi1         #+#    #+#             */
/*   Updated: 2025/02/27 04:02:08 by hta-rezi1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 4096

char *strsub(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1);  // +1 for null terminator
    if (!result) return NULL;

    strcpy(result, s1);    // Copy first string into result
    strcat(result, s2);    // Append second string to result

    return result;
}

char *readfile(int fd, char *stack){
    char buffer[BUFFER_SIZE];
    int bytesread;

    while (1){
        bytesread = read(fd, buffer, BUFFER_SIZE);
        if (bytesread < 0) return NULL;
        if (bytesread == 0) break ;
        if (!stack){
            stack = strdup("");
        }
        char *tmp = stack;
        stack = strsub(tmp, buffer);
        free(tmp);
        if (strchr(buffer, '\n')){
            break ;
        }
    }
    return (stack);
}

char *getnext_line(int fd){
    static char *stack;
    char        *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0){
        return (NULL);
    }
    stack = readfile(fd, stack);
    line = extract_line(stack, line);
    if (!line) return (free(stack), NULL);
    return (stack) ?  stack : NULL;
}

int main(int argc, char **argv){
    if (argc != 2){
        return (-1);
    }
    int fd = open(argv[1], O_RDONLY);
    char *s = getnext_line(fd);
    printf("%s", s);
    free(s);
    return (0);
}