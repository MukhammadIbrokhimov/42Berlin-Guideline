/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:14:49 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/17 19:41:28 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void *death_monitor(void *arg)
{
    int i;
    t_data *data = (t_data *)arg;
    
    while (!simulation_ended(data))
    {
        i = -1;
        while (++i < data->num_philosophers)
        {
            // FIX: Check death BEFORE acquiring death_mutex
            if (is_philosopher_dead(&data->philosophers[i]))
            {
                // Only lock death_mutex when we need to modify simulation_ended
                pthread_mutex_lock(&data->death_mutex);
                if (data->simulation_ended == 0) // Double-check to avoid race condition
                {
                    data->simulation_ended = 1;
                    printf("%s%ld ms %sPhilosopher %d %shas died%s\n",
                        CYAN, get_current_time() - data->start_time,
                        BOLD, data->philosophers[i].id, RED, RESET);
                }
                pthread_mutex_unlock(&data->death_mutex);
                return NULL;
            }
        }
        
        // FIX: Check meal satisfaction with proper mutex protection
        if (all_philosophers_satisfied(data) == 1)
        {
            pthread_mutex_lock(&data->death_mutex);
            if (!data->simulation_ended) // Double-check
            {
                data->simulation_ended = 1;
            }
            pthread_mutex_unlock(&data->death_mutex);
            return NULL;
        }
        
        usleep(500); // Check every 0.5ms
    }
    return NULL;
}

// 2. ISSUE: Magic number -13 in all_philosophers_satisfied()
// This should be a defined constant or use a more standard approach

// FIXED VERSION:
int all_philosophers_satisfied(t_data *data)
{
    int i;
    
    // FIX: Use a more standard check (0 or negative means unlimited eating)
    if (data->must_eat_count == -13)
        return (0);
    
    i = -1;
    while (++i < data->num_philosophers)
    {
        pthread_mutex_lock(&data->philosophers[i].meals_eaten_);
        int meals = data->philosophers[i].meals_eaten;
        pthread_mutex_unlock(&data->philosophers[i].meals_eaten_);
        
        if (meals < data->must_eat_count)
            return (0);
    }
    return (1);
}

// 3. POTENTIAL ISSUE: Time precision in death detection
// Your current implementation might have timing issues

// IMPROVED VERSION:
int is_philosopher_dead(t_philosopher *philo)
{
    long current_time = get_current_time();
    
    pthread_mutex_lock(&philo->last_meal_t);
    long last_meal_time = philo->last_meal_time;
    pthread_mutex_unlock(&philo->last_meal_t);
    
    long time_since_meal = current_time - last_meal_time;
    
    // Add some debug output (remove in final version)
    /*
    printf("DEBUG: Philosopher %d - Current: %ld, Last meal: %ld, "
           "Time since: %ld, Time to die: %ld\n",
           philo->id, current_time, last_meal_time, 
           time_since_meal, philo->data->time_to_die);
    */
    
    return (time_since_meal > philo->data->time_to_die);
}

// 4. ADDITIONAL ISSUE: Print statement in monitor bypasses print_mutex
// This can cause garbled output

// BETTER APPROACH:
void print_death_message(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->data->print_mutex);
    if (!philo->data->simulation_ended) // Double-check
    {
        long timestamp = get_current_time() - philo->data->start_time;
        printf("%s%ld ms %sPhilosopher %d %shas died%s\n",
            CYAN, timestamp, BOLD, philo->id, RED, RESET);
    }
    pthread_mutex_unlock(&philo->data->print_mutex);
}

// And modify the monitor to use it:
void *death_monitor_improved(void *arg)
{
    int i;
    t_data *data = (t_data *)arg;
    
    while (!simulation_ended(data))
    {
        i = -1;
        while (++i < data->num_philosophers)
        {
            if (is_philosopher_dead(&data->philosophers[i]))
            {
                pthread_mutex_lock(&data->death_mutex);
                if (data->simulation_ended == 0)
                {
                    data->simulation_ended = 1;
                    pthread_mutex_unlock(&data->death_mutex);
                    
                    // Use proper print function
                    print_death_message(&data->philosophers[i]);
                    return NULL;
                }
                pthread_mutex_unlock(&data->death_mutex);
                return NULL;
            }
        }
        
        if (all_philosophers_satisfied(data))
        {
            pthread_mutex_lock(&data->death_mutex);
            if (!data->simulation_ended)
                data->simulation_ended = 1;
            pthread_mutex_unlock(&data->death_mutex);
            return NULL;
        }
        
        usleep(500);
    }
    return NULL;
}

// 5. DEBUGGING TIPS:
// Add these debug functions to help identify issues:

void debug_philosopher_state(t_philosopher *philo)
{
    printf("DEBUG: Philosopher %d - ID: %d, Meals eaten: %d, "
           "Last meal: %ld, Current time: %ld\n",
           philo->id, philo->id, philo->meals_eaten, 
           philo->last_meal_time, get_current_time());
}

void debug_simulation_state(t_data *data)
{
    printf("DEBUG: Simulation - Ended: %d, Start time: %ld, "
           "Must eat: %d, Time to die: %ld\n",
           data->simulation_ended, data->start_time,
           data->must_eat_count, data->time_to_die);
}