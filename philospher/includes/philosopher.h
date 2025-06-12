/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:46:29 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/12 17:51:01 by mukibrok         ###   ########.fr       */
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
# include <sys/time.h>
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

typedef struct s_philosopher {
	int id;                    // Philosopher number (1 to n)
	int meals_eaten;           // Count of meals eaten
	long last_meal_time;       // Timestamp of last meal
	pthread_t thread;          // Philosopher's thread
	pthread_mutex_t *left_fork;    // Left fork mutex
	pthread_mutex_t *right_fork;   // Right fork mutex
	struct s_data *data;       // Pointer to shared data
} t_philosopher;

typedef struct s_data {
	int num_philosophers;      // Number of philosophers
	long time_to_die;         // Time before starvation (ms)
	long time_to_eat;         // Time to eat (ms)
	long time_to_sleep;       // Time to sleep (ms)
	int must_eat_count;       // Optional: meals required
	long start_time;          // Simulation start time
	int simulation_ended;     // Flag to stop simulation
	pthread_mutex_t *forks;   // Array of fork mutexes
	pthread_mutex_t print_mutex;  // Mutex for printing
	pthread_mutex_t death_mutex;  // Mutex for death checking
	t_philosopher *philosophers;  // Array of philosophers
} t_data;

// parse and validate
int		parse_data(int argc, char **argv, t_data *data);
int		validate_data(t_data *data);

// init
int		init_philo(t_data *data);
int		init_data(t_data *data);

// precise timing
long	get_current_time(void);
void	precise_sleep(long milliseconds);

//philosopher actions
void	*philosopher_routine(void *arg);
void	eat(t_philosopher *philo);
void	sleeep(t_philosopher *philo);
void	think(t_philosopher *philo);

// check conditions
int		check_meals_eaten(t_philosopher *philo);
int		check_meal_completion(t_philosopher *philo);

// simulation control
void	*death_monitor(void *arg);
int		is_philosopher_dead(t_philosopher *philo);
int		all_philosophers_satisfied(t_data *data);

// usage
void	cleanup(t_data *data);
int		simulation_ended(t_data *data);
void	print_status(t_philosopher *philo, const char *status);
void	print_usage_instructions();
void	print_philo_data(t_philosopher *philo);
unsigned long	ft_atol(const char *s, int *error);

#endif