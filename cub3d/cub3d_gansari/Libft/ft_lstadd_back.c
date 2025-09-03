/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:10:26 by gansari           #+#    #+#             */
/*   Updated: 2024/11/20 13:10:28 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
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
	t_list	*new_node1 = ft_lstnew((void *)"Hello");
	t_list	*new_node2 = ft_lstnew((void *)"World");
	t_list	*new_node3 = ft_lstnew((void *)"!");

	ft_lstadd_back(&head, new_node1);
	ft_lstadd_back(&head, new_node2);
	ft_lstadd_back(&head, new_node3);
	printf("List after adding elements to the back:\n");
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