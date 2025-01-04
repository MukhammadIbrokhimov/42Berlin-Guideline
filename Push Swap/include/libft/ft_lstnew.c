/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:33:39 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/04 17:44:57 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int nbr)
{
	t_list	*new_list;

	new_list = (t_list *) malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = nbr;
	new_list->index = -1;
	new_list->next = NULL;
	return (new_list);
}

// int main(void)
// {
// 	t_list	*list;
// 	t_list	*second;

// 	list = ft_lstnew("first");
// 	second = ft_lstnew("Second");
// 	ft_lstadd_front(&list, second);
// 	if (list)
// 	{
// 		printf("list: %s\n", (char *)list->content);
// 		printf("list: %p\n", list->content);
// 		printf("list: %p\n", list->next);
// 	}
// }
