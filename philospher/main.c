/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:42:37 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/28 14:31:44 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *set_activities(void *av)
{
	(void) av;
	printf("philo is generated\n");
	return (NULL);
}


void	create_philo(t_data *philo)
{
	pthread_t	*phil_number = malloc(sizeof(t_philo) * philo->philo_number);
	if (!phil_number)
		return ;
	for (uint i = 0; i < philo->philo_number; i++){
		sleep(1);;
		pthread_create(&phil_number[i], NULL, set_activities, NULL);
	}

	for (uint i = 0; i < philo->philo_number; i++){
		if (pthread_join(phil_number[i], NULL) != 0)
			printf("%s%sThread Joining was unsuccessfull%s\n", RED, BOLD, RESET);
	}
}


int main(int argc, char **argv)
{
	t_data	philo;
	if (argc != 5 && argc != 6)
	{
		printf("%sIncorrect argument was given!\n", RED);
		print_usage_instructions();
		return (1);
	}
	if (!init_data(argc, argv, &philo))
		return (print_usage_instructions(), 1);
	create_philo(&philo);
}

//int	prime[10] = { 1, 3, 5, 7, 11, 13, 17, 19, 27, 29 };

//void *getPrime(void *index){
//	int	i = *(int *)index;
//	printf("%d ", prime[i]);
//	return (NULL);
//}

//int main(void){
//	pthread_t t1[10];

//	for (int i = 0; i < 10; i++){
//		int *a = malloc(sizeof(int));
//		*a = i;
//		pthread_create(t1 + i, NULL, getPrime, a);
//	}

//	for(int j = 0; j < 10; j++){
//		pthread_join(t1[j], NULL);
//	}
//	return (0);
//}

//void	*getNum(){
//	int r = (rand() % 6) + 1;
//	int *p = malloc(sizeof(int));
//	*p = r;
//	printf("value of num in function: %d\n", *p);
//	printf("pointer in function: %p\n", p);
//	return (void *) p;
//}

//int	main(int argc, char **argv){
//	srand(time(NULL));
//	pthread_t t1;
	
//	pthread_create(&t1, NULL, getNum, NULL);
//	int *num;
//	pthread_join(t1, (void **) &num);
//	printf("value of num: %d\n", *num);
//	printf("pointer: %p\n", num);
//	free(num);
//	return (0);
//}

//void	*makeCoffee(void *data){
//	printf("barista is making coffee\n");
//	sleep(3);
//	printf("coffee is ready\n");
//	return NULL;
//}

//int main(void){
//	pthread_t	barista_1;
//	pthread_t	barista_2;

//	pthread_create(&barista_1, NULL, makeCoffee, NULL);
//	pthread_create(&barista_2, NULL, makeCoffee, NULL);

//	pthread_join(barista_1, NULL);
//	pthread_join(barista_2, NULL);
//}

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
