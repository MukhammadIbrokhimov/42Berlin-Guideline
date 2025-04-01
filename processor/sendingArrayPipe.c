/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendingArrayPipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:05:22 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/27 15:24:22 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int fd[2];
	if (pipe(fd) == -1) { return -1; }
	int pid = fork();
	if (pid == -1) { return -1; }
	if (pid > 0){
		//todo
		int arr[10];
		int sum = 0;
		for (int i = 0; i < 10; i++){
			if (read(fd[0], &arr[i], sizeof(int)) == -1){
				return (printf("Error during read\n"), 1);
			}
			sum += arr[i];
		}
		close(fd[0]);
		close(fd[1]);
		printf("---------------------\nI am Parent\n");
		for (int i = 0; i < 10; i++){
			printf("%d", arr[i]);
			if (i != 9) printf(" ");
			else printf("\n");
		}
		printf("Sum of all numbers: %d\n", sum);
		int sigStatus;
		wait(&sigStatus);
		if (WIFEXITED(sigStatus)){
			int sStatus = WEXITSTATUS(sigStatus);
			if (sStatus != 0) {
				return (printf("Failure\n"), 1);
			}
		}
		printf("---------------------\nI am Parent\n");
		printf("Success\n");
		return (0);
	} else {
		//todo
		printf("---------------------\nI am child\n");
		for (int i = 0; i < 10; i++){
			int x = rand() % 10;
			if (write(fd[1], &x, sizeof(int)) < 0) { return -1; }
			printf("%d", x);
			if (i != 9) printf(" ");
			else printf("\n");
		}
		close(fd[1]);
		close(fd[0]);
		return (0);
	}
}