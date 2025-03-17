Philosopher Project - 42 School

Introduction

The Philosopher project is a classic concurrency problem based on the "Dining Philosophers Problem," which was originally formulated by Edsger Dijkstra. The problem explores resource sharing and synchronization in multi-threaded programs, where philosophers (threads) must eat without causing deadlocks or resource starvation.

Objectives

Implement a simulation of the dining philosophers using multithreading.

Handle concurrent access to shared resources (forks) while preventing race conditions.

Avoid deadlocks, starvation, and data corruption.

Gain experience with mutexes, semaphores, and thread synchronization.

Project Requirements

Each philosopher follows an infinite cycle of thinking, eating, and sleeping.

Philosophers must pick up and put down forks (shared resources) correctly.

The simulation should stop if:

A philosopher dies (does not eat in a given time limit).

The number of meals per philosopher (if specified) is reached.

Use only pthreads and synchronization mechanisms like pthread_mutex_t or sem_t.

No data races or undefined behavior should occur.

Implementation Details

Threads: Each philosopher is represented by a thread.

Mutexes: Used to control access to shared resources (forks).

Timing: Accurate time tracking ensures philosophers eat before starvation.

Synchronization: Prevent deadlocks and ensure fairness in fork usage.

Compilation and Execution

Compile the project using:

make

Run the program with:

./philosophers <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]

number_of_philosophers: Total philosophers (must be >1).

time_to_die: Maximum time (in ms) a philosopher can live without eating.

time_to_eat: Time (in ms) a philosopher takes to eat.

time_to_sleep: Time (in ms) a philosopher sleeps after eating.

number_of_meals (optional): If specified, the simulation stops after each philosopher has eaten this many times.

Common Issues & Debugging

Deadlocks: Ensure correct ordering of mutex locks and unlocks.

Race Conditions: Use mutexes to protect shared variables.

Starvation: Implement a fair resource allocation strategy.

Conclusion

This project is an excellent exercise in concurrency and synchronization, reinforcing key concepts in multi-threaded programming. Proper management of resources ensures smooth execution without deadlocks or starvation.
