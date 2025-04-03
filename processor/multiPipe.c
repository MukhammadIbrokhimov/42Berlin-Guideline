/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiPipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:24:01 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/27 16:35:57 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int fd[2];
	
	if (pipe(fd) == -1) return (1);
	int pid = fork();
	if (pid < 0) return (-1);
	if (pid == 0){
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "1", "google.com", NULL);
	}
	int pid2 = fork();
	if (pid2 == -1) return (1);
	if (pid2 == 0){
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);

	}
	else{
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}