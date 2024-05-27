/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:03:28 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/12 16:24:45 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static long int	calc_len(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_litoa(long int nb, int *pos, char *dest)
{
	if (nb < 0)
	{
		dest[*pos] = '-';
		(*pos)++;
		if (nb == -2147483648)
		{
			dest[*pos] = '2';
			(*pos)++;
			nb = 147483648;
		}
		else
			nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_litoa((nb / 10), pos, dest);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		dest[*pos] = (nb + 48);
		(*pos)++;
	}
}

char	*ft_litoa(long int n)
{
	char	*dest;
	int		len;
	int		pos;

	len = calc_len(n);
	dest = (char *) malloc(len + 1);
	if (!dest)
		return (NULL);
	pos = 0;
	ft_putnbr_litoa(n, &pos, dest);
	dest[len] = '\0';
	return (dest);
}
