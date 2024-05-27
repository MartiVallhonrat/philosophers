/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:59:45 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/05 19:13:03 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

int	ft_strlcat(char *dst, char *src, size_t sz)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	i = 0;
	while (src[i] != '\0' && (i + dst_len + 1) < sz)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (sz > dst_len)
		return (dst_len + src_len);
	else
		return (src_len + sz);
}

/*int	main(void)
{
	char	dest[30] = "abds";
	char	src[30] = "lorem";
	printf("return: %d\n", ft_strlcat(dest, src, 30));
	printf("dst: %s\n", dest);
	return (0);
}*/
