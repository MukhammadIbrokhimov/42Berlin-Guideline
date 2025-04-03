/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitCode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:32:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/27 13:05:21 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <sys/wait.h>

int main(void){
	int fd = fork();
	if (fd < 0) { return 1; }
	if (fd == 0) {
		// todo
		int file = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);
		if (file < 0) { return 1; }
		dup2(file, STDOUT_FILENO);
		close(file);
		fprintf(stdout, "stdout has been changed to file descriptor\n");
		fflush(stdout);
		int statusCode = execlp("ping", "ping", "-c", "1", "google.com", NULL);
		if (statusCode != 0){
			return (printf("Exec function not succeed...\n"), 1);
		}
	} else {
		// todo
		int errStatus;
		wait(&errStatus);
		if (WIFEXITED(errStatus)){
			int statusCode = WEXITSTATUS(errStatus);
			if (statusCode != 0) {
				printf("Failure\n");
			} else {
				printf("Success\n");
			}
		}
		printf("finished\n");
	}
}