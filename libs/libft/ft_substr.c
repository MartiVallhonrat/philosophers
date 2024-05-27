/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:55:31 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/16 19:07:27 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	s_len;
	size_t	res_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = (size_t)ft_strlen(s);
	if (s_len < start)
		res_len = 0;
	else if (s_len - start <= len)
		res_len = s_len - start;
	else
		res_len = len;
	res = (char *) malloc(res_len + 1);
	if (!res)
		return (NULL);
	while (i < res_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*int	main(void)
{
	printf("result: %s\n", ft_substr("", 1, 1));
	return (0);
}*/
