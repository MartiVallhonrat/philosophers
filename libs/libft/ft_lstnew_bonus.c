/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:02:29 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/09 14:02:53 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dest;

	dest = (t_list *) malloc(sizeof (t_list));
	if (!dest)
		return (NULL);
	dest->content = content;
	dest->next = NULL;
	return (dest);
}

/*int	main(void)
{
	t_list	*res;
	res = ft_lstnew("Hello World!");
	printf("content: %s\n", res->content);
	printf("next: %s\n", res->next);
	return (0);
}*/
