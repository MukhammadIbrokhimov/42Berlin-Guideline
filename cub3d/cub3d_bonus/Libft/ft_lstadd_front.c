/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:27:17 by gansari           #+#    #+#             */
/*   Updated: 2024/11/20 11:27:19 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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

int	main()
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

	while (head)
	{
		t_list *tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}
*/