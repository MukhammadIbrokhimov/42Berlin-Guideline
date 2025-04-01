/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communicate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:18:03 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/27 14:48:16 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

// with 2 pipe
int main(int argc, char **argv){
	int fd[2];
	int fd1[2];

	if (pipe(fd) == -1) { return -1; }
	if (pipe(fd1) == -1) { return -1; }

	int pid = fork();
	if (pid < 0) { return -1; }
	if (pid == 0){
		//todo
		int x;
		if (read(fd[0], &x, sizeof(int)) < 0) { return -1; }
		printf("----------------------------------------\nI am child:)");
		printf("Received: %d\n", x);
		close(fd[0]);
		close(fd[1]);
		sleep(5);
		x *= 10;
		if (write(fd1[1], &x, sizeof(int)) < 0) { return -1; }
		printf("----------------------------------------\nI am child:)");
		printf("send: %d\n", x);
		close(fd1[1]);
		close(fd1[0]);
	}
	else{
		// todo
		int x = rand() % 10;
		if (write(fd[1], &x, sizeof(int)) < 0) { return -1; }
		printf("----------------------------------------\nI am parent:)");
		printf("Send: %d\n", x);
		close(fd[0]);
		close(fd[1]);
		//wait(NULL);
		int y;
		if (read(fd1[0], &y, sizeof(int)) < 0) { return -1; }
		printf("----------------------------------------\nI am parent:)");
		printf("received: %d\n", y);
		close(fd1[0]);
		close(fd1[1]);
	}
}

// with 1 pipe

/*
int main(int argc, char **argv){
	int fd[2];

	if (pipe(fd) == -1) { return -1; }

	int pid = fork();
	if (pid < 0) { return -1; }
	if (pid == 0){
		//todo
		int x;
		if (read(fd[0], &x, sizeof(int)) < 0) { return -1; }
		printf("----------------------------------------\nI am child:)");
		printf("Received: %d\n", x);
		close(fd[0]);
		//close(fd[1]);

		x *= 10;
		if (write(fd[1], &x, sizeof(int)) < 0) { return -1; }
		printf("----------------------------------------\nI am child:)");
		printf("send: %d\n", x);
		close(fd[1]);
	}
	else{
		// todo
		int x = rand() % 10;
		if (write(fd[1], &x, sizeof(int)) < 0) { return -1; }
		printf("----------------------------------------\nI am parent:)");
		printf("Send: %d\n", x);
		//close(fd[0]);
		close(fd[1]);
		wait(NULL);
		int y;
		if (read(fd[0], &y, sizeof(int)) < 0) { return -1; }
		printf("----------------------------------------\nI am parent:)");
		printf("received: %d\n", y);
		close(fd[0]);
	}
}
*/