/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:55:06 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/14 16:52:50 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (str1 == str2)
		return (str1);
	if (str1 < str2)
		return (ft_memcpy(str1, str2, n));
	dest = (unsigned char *)str1;
	src = (unsigned char *)str2;
	while (n > 0)
	{
		dest[n - 1] = src[n - 1];
		n--;
	}
	return (str1);
}

/*int	main(void)
{
	int	i = 0;
	char arr[] = "Perro!";
	char result[] = "Eiiiiiiii";
	memmove(result, arr, 3);
	while (i < 3)
	{
		printf("mem_space: %c\n", arr[i]);
		i++;
	}
	printf("%s\n", result);
	return (0);
}*/
