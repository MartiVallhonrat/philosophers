/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:59:17 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/14 17:37:54 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t nb)
{
	size_t			i;
	unsigned char	*uns;

	i = 0;
	uns = (unsigned char *)str;
	while (i < nb)
	{
		uns[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	arr[] = "aaabbb";
	ft_memset(arr, '$', 3);
	printf("%s\n", arr);
	return (0);
}*/
