/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:55:39 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/24 16:01:51 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H

# define PHILOSOPHER_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <stdbool.h>

# define RESET   "\033[0m"      // Reset color
# define RED     "\033[31m"     // Red text
# define GREEN   "\033[32m"     // Green text
# define YELLOW  "\033[33m"     // Yellow text
# define BLUE    "\033[34m"     // Blue text
# define CYAN    "\033[36m"     // Cyan text
# define BOLD    "\033[1m"      // Bold text
# define BROWN   "\033[33m"     // Brown (approximated as dark yellow)
# define UNDERLINE "\033[4m"    // Underlined text

typedef pthread_mutex_t	t_mutex;
typedef unsigned long	t_ulong;
typedef struct s_philosopher {
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meals_eaten_;
	pthread_mutex_t	last_meal_t;
	struct s_data	*data;
}	t_philosopher;

typedef struct s_data
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
	t_philosopher	*philosophers;
}	t_data;

// parse and validate
int		parse_data(int argc, char **argv, t_data *data);
int		validate_data(t_data *data);

// init
int		init_philo(t_data *data);
int		init_data(t_data *data);
void	init_forks(t_philosopher *philo, t_data *data);

// precise timing
long	get_current_time(void);
void	precise_sleep(long milliseconds);

//philosopher actions
void	*philosopher_routine(void *arg);
int		eat(t_philosopher *philo);
int		sleeep(t_philosopher *philo);
int		think(t_philosopher *philo);

// check conditions
int		check_meals_eaten(t_philosopher *philo);
int		check_meal_completion(t_philosopher *philo);

// simulation control
void	*death_monitor(void *arg);
void	handle_death(t_data *data, int i);
void	debug_philosopher_state(t_philosopher *philo);
void	debug_simulation_state(t_data *data);
int		is_philosopher_dead(t_philosopher *philo);
int		all_philosophers_satisfied(t_data *data);

// cleanup
void	cleanup(t_data *data);
void	cleanup_forks(t_data *data, int count);
void	cleanup_partial_philosophers(t_data *data, int count);

// usage
int		simulation_ended(t_data *data);
void	print_status(t_philosopher *philo, const char *status);
void	print_usage_instructions(void);
void	print_philo_data(t_philosopher *philo);
void	print_data(t_data *data);
void	print_death_message(t_philosopher *philo);
t_ulong	ft_atol(const char *s, int *error);

#endif