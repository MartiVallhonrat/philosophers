/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:13 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/10 11:18:39 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return (big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && big[i + j] == little[j]
			&& (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return (&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("result: %s\n", ft_strnstr("Foo Bar Baz", "Baz", 20));
	return (0);
}*/
