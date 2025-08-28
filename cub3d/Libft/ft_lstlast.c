/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:27:18 by gansari           #+#    #+#             */
/*   Updated: 2024/11/20 12:27:22 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	len;

	if (!lst)
		return (NULL);
	len = ft_lstsize(lst);
	while (len - 1)
	{
		lst = lst->next;
		len--;
	}
	return (lst);
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
	printf("The last node content: %s\n", (char *)(ft_lstlast(head))->content);

	while (head)
	{
		t_list *tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}
*/