/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:53:01 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/09 11:53:02 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (s + i);
	return (NULL);
}

/*int	main(void)
{
	printf("result: %s\n", ft_strchr("abcd", 'c'));
	return (0);
}*/
