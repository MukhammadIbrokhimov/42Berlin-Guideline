/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:33:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/21 19:14:36 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *) malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
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
