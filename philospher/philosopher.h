/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:46:29 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/10 21:03:49 by mukibrok         ###   ########.fr       */
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

# define RESET   "\033[0m"      // Reset color
# define RED     "\033[31m"     // Red text
# define GREEN   "\033[32m"     // Green text
# define YELLOW  "\033[33m"     // Yellow text
# define BLUE    "\033[34m"     // Blue text
# define CYAN    "\033[36m"     // Cyan text
# define BOLD    "\033[1m"      // Bold text
# define BROWN   "\033[33m"  // Brown (approximated as dark yellow)
# define UNDERLINE "\033[4m"    // Underlined text

typedef unsigned int uint;

typedef struct s_shared_data
{
	int				num_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_count;
	long			start_time;
	int				simulation_ended;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*philosophers; 
}	t_shared_data;

typedef struct s_fork
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	t_fork			fork;
	struct s_shared_data	*data;
}	t_philo;

// utils function

int		init_data(int argc, char **argv, t_shared_data *philo);
int		init_philo(t_shared_data *data);
void	print_usage_instructions();
unsigned long	ft_atol(const char *s, int *error);

#endif