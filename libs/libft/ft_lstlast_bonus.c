/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:00:26 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/12 19:16:00 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*int	main(void)
{
	int	one = 1;
	int	two = 2;
	t_list	*lst;
	t_list	*first_node;
	t_list	*second_node;
	t_list	*result;

	first_node = ft_lstnew(&one);
	second_node = ft_lstnew(&two);
	first_node->next = second_node;
	lst = first_node;
	result = ft_lstlast(second_node);
	
	printf("last node content: %d\n", *(int *)result->content);
	printf("last node next: %s\n", (char *)result->next);
	return (0);
}*/
