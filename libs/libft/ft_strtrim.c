/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:54:27 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/12 15:10:48 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	mem_counter(char const *s1, char const *set)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s1[i] != '\0' && in(s1[i], set) == 1)
		i++;
	while (s1[i] != '\0')
	{
		i++;
		counter++;
	}
	if (counter != 0)
		i--;
	while (s1[i] != '\0' && i > 0 && in(s1[i], set) == 1)
	{
		i--;
		counter--;
	}
	return (counter + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*dest;
	int		dest_len;

	i = 0;
	j = 0;
	dest_len = mem_counter(s1, set);
	dest = (char *) malloc(dest_len);
	if (!dest)
		return (NULL);
	while (s1[i] != '\0' && in(s1[i], set) == 1)
		i++;
	while (j < (dest_len - 1))
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	dest[dest_len - 1] = '\0';
	return (dest);
}

/*int	main(void)
{
	printf("result: %s.\n", ft_strtrim("eded123eed", "ed"));
	return (0);
}*/
