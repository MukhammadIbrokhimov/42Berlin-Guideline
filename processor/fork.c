/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:46:35 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/25 16:39:26 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int	main(void){
	int pid = fork();
	int n;
	if (pid == 0){
		n = 1;
	}
	else{
		n = 6;
	}
	if (pid != 0){
		wait(NULL);
	}
	for (int i = n; i < 10; i++){
		printf("%d ", i);
	}
	printf("processor id:%d\n", getpid());
	return (0);
}