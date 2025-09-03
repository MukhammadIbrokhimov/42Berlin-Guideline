/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:16:03 by gansari           #+#    #+#             */
/*   Updated: 2024/11/20 12:16:05 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst)
	{
		num++;
		lst = lst->next;
	}
	return (num);
}
/*
#include <stdio.h>

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)(lst->content));
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list	*head = NULL;
	t_list	*new_node1 = ft_lstnew((void *)"!");
	t_list	*new_node2 = ft_lstnew((void *)"World");
	t_list	*new_node3 = ft_lstnew((void *)"Hello");

	ft_lstadd_front(&head, new_node1);
	ft_lstadd_front(&head, new_node2);
	ft_lstadd_front(&head, new_node3);
	printf("List after adding elements to the front:\n");
	print_list(head);
	printf("Number of nodes: %d\n", ft_lstsize(head));

	while (head)
	{
		t_list *tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}
*/