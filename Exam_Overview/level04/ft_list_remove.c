/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:53:25 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/11 18:59:18 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_list
{
	struct s_list *next;
	void			*data;
}				t_list;

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*current;

	if (!*begin_list || !begin_list)
		return ;
	while (*begin_list && (cmp((*begin_list)->data), data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	current = *begin_list;
	while (current && current->next)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			tmp = current->next;
			current->next = current->next->next;
			free(tmp);
		}
		else
			current = current->next;
	}

}


// Comparator function
int cmp(void *data1, void *data2)
{
    return strcmp((char *)data1, (char *)data2);
}

// Helper function to create a new node
t_list *create_node(void *data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Helper function to add a node to the list
void add_node(t_list **head, void *data)
{
    t_list *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Helper function to print the list
void print_list(t_list *head)
{
    while (head)
    {
        printf("%s -> ", (char *)head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main test
int main(void)
{
    t_list *list = NULL;

    // Add nodes to the list
    add_node(&list, "42");
    add_node(&list, "World");
    add_node(&list, "42");
    add_node(&list, "Hello");

    printf("Original list:\n");
    print_list(list);

    // Remove nodes with data "42"
    ft_list_remove_if(&list, "42", cmp);

    printf("Modified list:\n");
    print_list(list);

    // Free remaining nodes
    while (list)
    {
        t_list *temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
