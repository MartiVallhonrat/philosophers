/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:54:08 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/11 16:16:48 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*uns1;
	unsigned char	*uns2;

	i = 0;
	uns1 = (unsigned char *)s1;
	uns2 = (unsigned char *)s2;
	while (i < n)
	{
		if (uns1[i] != uns2[i])
			return (uns1[i] - uns2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char arr1[] = "123\04";
	char arr2[] = "123\05";
	printf("%d\n", ft_memcmp(arr1, arr2, 5));
	return (0);
}*/
