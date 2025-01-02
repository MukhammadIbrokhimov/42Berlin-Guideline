/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:29:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/12 19:41:57 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n)
	{
		if (*(unsigned char *) s1 != *(unsigned char *) s2)
			return (*(unsigned char *) s1 - *(unsigned char *) s2);
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
