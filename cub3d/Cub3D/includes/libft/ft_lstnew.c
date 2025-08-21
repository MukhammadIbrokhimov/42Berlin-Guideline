/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:52:43 by gansari           #+#    #+#             */
/*   Updated: 2024/11/19 18:52:45 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
	char *data = "Hello, world!";

	t_list *new_node = ft_lstnew((void *)data);

	if (new_node == NULL)
	{
		printf("Failed to create new node\n");
		return (1);
	}
	printf("Node content: %s\n", (char *)new_node->content);
	free(new_node);

	return (0);
}
*/