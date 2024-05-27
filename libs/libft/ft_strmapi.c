/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:03:01 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/14 17:41:14 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	ft_toupper(unsigned int i, char c)
{
	return (c - 32);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	while (s[i] != '\0')
		i++;
	dest = (char *) malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char arr[] = "abcd";
	printf("start: %s\n", arr);
	printf("result: %s\n", ft_strmapi(arr, ft_toupper));
	return (0);
}*/
