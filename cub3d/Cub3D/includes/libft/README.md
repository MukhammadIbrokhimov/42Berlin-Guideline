# Libft - A Custom Standard C Library Implementation

Welcome to **Libft**, a custom implementation of essential functions from the C standard library, along with additional utilities for handling strings, memory, file descriptors, and linked lists. This library is designed to enhance your understanding of C programming and serve as a foundation for future projects.

---

## Table of Contents

1. [Introduction](#introduction)
2. [How to Use](#how-to-use)
3. [Functions Overview](#functions-overview)
   - [Character Checks and Conversions](#character-checks-and-conversions)
   - [String Manipulation](#string-manipulation)
   - [Memory Management](#memory-management)
   - [File Descriptor Utilities](#file-descriptor-utilities)
   - [Linked List Utilities](#linked-list-utilities)
4. [Installation](#installation)
5. [Contributing](#contributing)
6. [License](#license)

---

## Introduction

The **Libft** library replicates commonly used functions from `<ctype.h>`, `<string.h>`, `<stdlib.h>`, and `<unistd.h>`, while extending functionality with advanced utilities for linked lists and custom data handling. This project is a cornerstone of C programming in projects at **42 School**.

---

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/libft.git


This generates the `libft.a` static library file, which can be included in your projects. Add `libft.h` to your source files and link the library during compilation:

```c
#include "libft.h"
```

Compile your project with the library:

```bash
gcc -Wall -Werror -Wextra your_program.c -L. -lft -o your_program
```

To clean up compiled files:

```bash
make clean     # Removes object files
make fclean    # Removes object files and the compiled library
make re        # Cleans and recompiles the library
```

---

## Function Overview

### Character Checks and Conversions

- `int ft_isalpha(int c)`  
  Checks if a character is alphabetic.

- `int ft_isdigit(int c)`  
  Checks if a character is a digit.

- `int ft_isalnum(int c)`  
  Checks if a character is alphanumeric.

- `int ft_isascii(int c)`  
  Checks if a character is in the ASCII set.

- `int ft_isprint(int c)`  
  Checks if a character is printable.

- `int ft_toupper(int c)`  
  Converts a character to uppercase.

- `int ft_tolower(int c)`  
  Converts a character to lowercase.

### String Manipulation

- `size_t ft_strlen(const char *str)`  
  Returns the length of a string.

- `int ft_strncmp(const char *s1, const char *s2, size_t n)`  
  Compares two strings up to `n` characters.

- `char *ft_strchr(const char *s, int c)`  
  Finds the first occurrence of a character in a string.

- `char *ft_strrchr(const char *s, int c)`  
  Finds the last occurrence of a character in a string.

- `size_t ft_strlcpy(char *dst, const char *src, size_t size)`  
  Copies a string to a destination buffer.

- `size_t ft_strlcat(char *dst, const char *src, size_t size)`  
  Concatenates a string to a destination buffer.

- `char *ft_strdup(char *s)`  
  Duplicates a string.

- `char *ft_strjoin(const char *s1, const char *s2)`  
  Joins two strings into a new string.

- `char *ft_substr(const char *s, unsigned int start, size_t len)`  
  Extracts a substring from a string.

- `char *ft_strtrim(const char *s1, const char *set)`  
  Trims specified characters from a string.

- `char **ft_split(const char *s, char c)`  
  Splits a string by a delimiter.

- `char *ft_strmapi(const char *s, char (*f)(unsigned int, char))`  
  Applies a function to each character of a string.

### Memory Management

- `void *ft_memset(void *s, int c, size_t n)`  
  Fills memory with a constant byte.

- `void ft_bzero(void *s, size_t n)`  
  Sets memory to zero.

- `void *ft_memcpy(void *dest, const void *src, size_t n)`  
  Copies memory area.

- `void *ft_memmove(void *dest, const void *src, size_t n)`  
  Moves memory safely.

- `void *ft_memchr(const void *s, int c, size_t n)`  
  Locates a byte in memory.

- `int ft_memcmp(const void *s1, const void *s2, size_t n)`  
  Compares memory areas.

- `void *ft_calloc(size_t amount, size_t size)`  
  Allocates memory and initializes to zero.

### File Descriptor Operations

- `void ft_putchar_fd(char c, int fd)`  
  Outputs a character to a file descriptor.

- `void ft_putstr_fd(char *s, int fd)`  
  Outputs a string to a file descriptor.

- `void ft_putendl_fd(char *s, int fd)`  
  Outputs a string followed by a newline to a file descriptor.

- `void ft_putnbr_fd(int n, int fd)`  
  Outputs an integer to a file descriptor.

- `void ft_striteri(char *s, void (*f)(unsigned int, char *))`  
  Iterates over a string and applies a function to each character.

### Linked List Utilities

- `t_list *ft_lstnew(void *content)`  
  Creates a new list node.

- `void ft_lstadd_front(t_list **lst, t_list *new)`  
  Adds a node at the beginning of the list.

- `void ft_lstadd_back(t_list **lst, t_list *new)`  
  Adds a node at the end of the list.

- `int ft_lstsize(t_list *lst)`  
  Counts the nodes in a list.

- `t_list *ft_lstlast(t_list *lst)`  
  Returns the last node of a list.

- `void ft_lstdelone(t_list *lst, void (*del)(void *))`  
  Deletes a node and frees its content.

- `void ft_lstclear(t_list **lst, void (*del)(void *))`  
  Deletes all nodes of a list.

- `void ft_lstiter(t_list *lst, void (*f)(void *))`  
  Iterates over a list and applies a function.

- `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`  
  Creates a new list by applying a function to each node.

---

## Example Usage

Here’s an example of how to use some functions from the Libft library:

**Sample Program (`example.c`)**:

```c
#include "libft.h"
#include <stdio.h>

int main(void) {
    const char *str = "Hello, Libft!";
    size_t len = ft_strlen(str);
    char upper = ft_toupper('h');

    printf("String length: %zu\n", len);
    printf("Uppercase: %c\n", upper);

    return 0;
}
```

**Compile and Run**:

```bash
gcc -Wall -Werror -Wextra example.c -L. -lft -o example
./example
```

**Output**:

```bash
String length: 13
Uppercase: H
```

---

## License

Feel Free to use for your personal projects.

