/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:56:55 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/10 20:05:43 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list *next;
	void	*data;
}				t_list;


int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while(begin_list != NULL)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

#include <stdio.h>

int main(void)
{
    t_list node3 = { NULL, "Data3" };
    t_list node2 = { &node3, "Data2" };
    t_list node1 = { &node2, "Data1" };

    printf("List size: %d\n", ft_list_size(&node1)); // Output: List size: 3
    return 0;
}

