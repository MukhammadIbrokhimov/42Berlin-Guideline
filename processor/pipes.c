/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:19:34 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/25 17:26:31 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void){
	int fd[2];

	if (pipe(fd) == -1) return (printf("error\n"), 1);
	int pid = fork();
	if (pid == 0){
		int x;
		printf("Give me an integer: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[0]);
		close(fd[1]);
	}
	else{
		int y;
		read(fd[0], &y, sizeof(int));
		printf("What i received from child: %d\n", y);
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}