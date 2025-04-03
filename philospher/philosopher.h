/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:46:29 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/18 19:49:32 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILOSOPHER_H_
# define _PHILOSOPHER_H_

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <stdbool.h>

#define RESET   "\033[0m"      // Reset color
#define RED     "\033[31m"     // Red text
#define GREEN   "\033[32m"     // Green text
#define YELLOW  "\033[33m"     // Yellow text
#define BLUE    "\033[34m"     // Blue text
#define CYAN    "\033[36m"     // Cyan text
#define BOLD    "\033[1m"      // Bold text
#define BROWN   "\033[33m"  // Brown (approximated as dark yellow)
#define UNDERLINE "\033[4m"    // Underlined text

typedef unsigned int uint;

pthread_mutex_t	

typedef struct s_data
{
	unsigned long	philo_number;
	unsigned long	timeto_die;
	unsigned long	timeto_eat;
	unsigned long	timeto_sleep;
	unsigned long	dinner_number;
}	t_data;

typedef struct s_fork
{
	int	right;
	int	left;
}	t_fork;

typedef struct s_philo
{
	t_data	data;
	t_fork	fork;
}	t_philo;

// utils function
bool	init_data(int argc, char **argv, t_data *philo);
void	print_usage_instructions();
unsigned long	ft_atol(const char *s, int *error);

#endif