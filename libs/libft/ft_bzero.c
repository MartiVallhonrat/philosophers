/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:22 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/10 10:43:36 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t				i;
	unsigned char		*uns;

	i = 0;
	uns = (unsigned char *)str;
	while (i < n)
	{
		uns[i] = 0;
		i++;
	}
}
