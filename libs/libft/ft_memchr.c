/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:51 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/14 17:39:50 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*uns;

	uns = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (uns[i] == (unsigned char)c)
			return (uns + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char arr[] = "abcd";
	char *result;

	result = ft_memchr(arr, 'b', 2);
	printf("%s\n", result);
	return (0);
}*/
