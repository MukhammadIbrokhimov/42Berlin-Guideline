/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:18:18 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/13 19:52:41 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	tmp;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	tmp = dst_len;
	while (i < size - dst_len - 1 && src[i])
	{
		dst[tmp] = src[i];
		i++;
		tmp++;
	}
	dst[tmp] = '\0';
	return (src_len + dst_len);
}

// void test_strlcat(void)
// {
//     char dest1[30] = "there is no stars in the sky ";
//     char dest2[30] = "there is no stars in the sky ";
//     char *src1 = "the cake is a lie !\0I'm hidden lol\r\n";
//     size_t size = strlen("there is no stars in the sky ") + 30 ;

//     // Real strlcat
//     printf("Testing strlcat:\n");
//     size_t real_len = strlcat(dest1, src1, size);
//     printf("Real strlcat: %s (Length: %zu)\n", dest1, real_len);

//     // Reset destination string and test ft_strlcat
//     printf("Testing ft_strlcat:\n");
//     size_t ft_len = ft_strlcat(dest2, src1, size);
//     printf("ft_strlcat: %s (Length: %zu)\n", dest2, ft_len);

// }

// int main(void)
// {
//     test_strlcat();
//     return 0;
// }
