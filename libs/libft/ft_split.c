/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:00 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/07 19:05:25 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	count_words(const char *str, char c)
{
	size_t	i;
	int		trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

size_t	next_word(char const *str, size_t *i, char c)
{
	size_t	size;

	while (str[*i] && str[*i] == c)
		*i += 1;
	size = 0;
	while (str[*i + size] && str[*i + size] != c)
		size++;
	return (size);
}

static void	free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	words;
	size_t	words_count;
	size_t	word_size;
	size_t	i;

	words = count_words(s, c);
	strs = ft_calloc(sizeof (char *), words + 1);
	if (!strs)
		return (NULL);
	i = 0;
	words_count = 0;
	while (words_count < words)
	{
		word_size = next_word(s, &i, c);
		strs[words_count] = ft_calloc(sizeof (char), word_size + 1);
		if (!strs[words_count])
		{
			free_all(strs);
			return (NULL);
		}
		ft_strlcpy(strs[words_count++], &s[i], word_size + 1);
		i += word_size;
	}
	return (strs);
}

/*int	main(void)
{
	int		i = 0;
	char	**res;

	res = ft_split("Hello World !", ' ');
	while (i < 3)
	{
		printf("string %d: %s\n", i, res[i]);
		i++;
	}
	return (0);
}*/
