/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:03:01 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/16 10:54:11 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// void print_list(t_list *list)
// {
// 	int i = 0;
// 	while (list)
// 	{
// 		printf("Node %d: %s\n", i++, (char *)list->content);
// 		list = list->next;
// 	}
// 	printf("-----\n");
// }

// void free_content(void *content)
// {
// 	if (content)
// 		free(content);
// }

// void uppercase_content(void *content)
// {
// 	char *str = (char *)content;
// 	for (int i = 0; str[i]; i++)
// 		if (str[i] >= 'a' && str[i] <= 'z')
// 			str[i] -= 32;
// }

// void *duplicate_content(void *content)
// {
// 	if (!content)
// 		return NULL;
// 	return strdup((char *)content);
// }

// int main(void)
// {
// 	printf("Testing ft_lstnew:\n");
// 	t_list *list = ft_lstnew(strdup("first"));
// 	if (!list || !list->content)
// 	{
// 		printf("Memory allocation failed in ft_lstnew.\n");
// 		return 1;
// 	}
// 	print_list(list);

// 	printf("Testing ft_lstadd_front:\n");
// 	t_list *new_node = ft_lstnew(strdup("new front"));
// 	if (!new_node || !new_node->content)
// 	{
// 		printf("Memory allocation failed in ft_lstnew for new_node.\n");
// 		ft_lstdelone(list, free_content);
// 		return 1;
// 	}
// 	ft_lstadd_front(&list, new_node);
// 	print_list(list);

// 	printf("Testing ft_lstsize:\n");
// 	int size = ft_lstsize(list);
// 	printf("List size: %d\n", size);

// 	printf("Testing ft_lstlast:\n");
// 	t_list *last_node = ft_lstlast(list);
// 	if (last_node)
// 		printf("Last node content: %s\n", (char *)last_node->content);
// 	else
// 		printf("List is empty, no last node.\n");

// 	printf("Testing ft_lstadd_back:\n");
// 	t_list *new_node1 = ft_lstnew(strdup("new back"));
// 	ft_lstadd_back(&list, new_node1);
// 	print_list(list);

// 	printf("Testing ft_lstiter (Uppercasing content):\n");
// 	ft_lstiter(list, uppercase_content);
// 	print_list(list);

// 	printf("Testing ft_lstmap (Duplicate content):\n");
// 	t_list *mapped_list = ft_lstmap(list, duplicate_content, free_content);
// 	print_list(mapped_list);

// 	printf("Testing ft_lstclear on the original list:\n");
// 	ft_lstclear(&list, free_content);
// 	if (!list)
// 		printf("Original list cleared successfully.\n");
// 	else
// 		printf("Original list was not cleared properly.\n");
// 	print_list(list);

// 	printf("Testing ft_lstclear on the mapped list:\n");
// 	ft_lstclear(&mapped_list, free_content);
// 	if (!mapped_list)
// 		printf("Mapped list cleared successfully.\n");
// 	else
// 		printf("Mapped list was not cleared properly.\n");
// 	print_list(mapped_list);

// 	return 0;
// }
