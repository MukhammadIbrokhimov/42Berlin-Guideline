/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:42:37 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/08 15:50:15 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void	*makeCoffee(void *data){
	printf("barista is making coffee\n");
	sleep(3);
	printf("coffee is ready\n");
	return NULL;
}

int main(void){
	pthread_t	barista_1;
	pthread_t	barista_2;

	pthread_create(&barista_1, NULL, makeCoffee, NULL);
	pthread_create(&barista_2, NULL, makeCoffee, NULL);

	pthread_join(barista_1, NULL);
	pthread_join(barista_2, NULL);
}

//int main(void){
//	pid_t pid;

//	printf("forks starts here\n");

//	pid = fork();
//	if (pid < 0){
//		return (-1);
//	}
//	printf("forked succesfully here\n");
//	if (pid == 0){
//		printf("I am child and my pid is %d\n", pid);
//		printf("i am child and I am done now\n");
//	}
//	else{
//		printf("I am parent my childs pid number is %d\n", pid);
//		printf("Parent : done\n");
//		while (1){
//			sleep(1);
//		}
//	}
//}