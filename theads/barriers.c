/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barriers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:41:03 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/18 14:17:13 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_barrier_t barrier;

void *smth(void *nth) {
    printf("Waiting .....\n");

    // Corrected: Pass the address of the barrier
    pthread_barrier_wait(&barrier);

    printf("Pass .....\n");
    return NULL;
}

int main(void) {
    pthread_t t[12];

    // Initialize the barrier with a count of 3
    pthread_barrier_init(&barrier, NULL, 4);

    // Create 10 threads
    for (int i = 0; i < 12; i++) {
		sleep(1);

        //sleep(1); // Sleep for 1 second between thread creation
        pthread_create(&t[i], NULL, smth, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 12; i++) {
        pthread_join(t[i], NULL);
    }

    // Destroy the barrier
    pthread_barrier_destroy(&barrier);

    return 0;
}