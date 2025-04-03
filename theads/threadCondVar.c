/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadCondVar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:49 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/14 20:43:25 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

int	fuel = 0;
pthread_mutex_t fuelMutex;
pthread_cond_t	fuelCond;

void	*fuelFiller(void *value){

	for (int i = fuel; i < 20; i ++){
		pthread_mutex_lock(&fuelMutex);
		fuel += 10;
		printf("filling %d...\n", fuel);
		pthread_cond_broadcast(&fuelCond);
		pthread_mutex_unlock(&fuelMutex);
		sleep(1);
	}

	return (NULL);
}

void	*fuelCar(void *value){
	pthread_mutex_lock(&fuelMutex);
	while (fuel < 40){
		printf("No enough fuel...\n");
		pthread_cond_wait(&fuelCond, &fuelMutex);
	}
	pthread_mutex_unlock(&fuelMutex);
	fuel -= 40;
	printf("Left in station %d\n", fuel);
	return (NULL);
}

int main(void){
	pthread_t	t[10];
	pthread_mutex_init(&fuelMutex, NULL);
	pthread_cond_init(&fuelCond, NULL);

	for (int i = 0; i < 10; i++){
		if (i < 7){
			pthread_create(&t[i], NULL, fuelCar, NULL);
		}
		else{
			pthread_create(&t[i], NULL, fuelFiller, NULL);
		}
	}

	for(int i = 0; i < 10; i++){
		pthread_join(t[i], NULL);
	}
	pthread_mutex_destroy(&fuelMutex);
	pthread_cond_destroy(&fuelCond);
	return (0);
}