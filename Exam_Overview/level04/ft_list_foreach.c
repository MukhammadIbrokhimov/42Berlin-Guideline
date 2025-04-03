/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:05:12 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/11 16:42:00 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		(*f)(begin_list->data);
		begin_list = tmp;
	}
}

t_list *create_node(void *data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
t_list *add_node(t_list *head, void *data)
{
    t_list *new_node = create_node(data);
    if (!new_node)
        return head;

    if (!head)
        return new_node;

    t_list *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;

    return head;
}

// Function to free the list
t_list *free_list(t_list *head)
{
    t_list *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

// Function to print a string (example for testing)
void print_data(void *data)
{
    printf("%s\n", (char *)data);
}

int main(void)
{
    // Create a sample list
    t_list *list = NULL;
    list = add_node(list, "Hello");
    list = add_node(list, "42");
    list = add_node(list, "World");

    // Apply ft_list_foreach to print each element
    printf("List contents:\n");
    ft_list_foreach(list, &print_data);

    // Free the list
    list = free_list(list);

    return 0;
}

