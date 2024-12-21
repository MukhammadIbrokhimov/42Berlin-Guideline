/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:43:45 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/06 16:23:10 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(src);
	if (size == 0)
		return (length);
	while (*src && i < size - 1)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (length);
}
