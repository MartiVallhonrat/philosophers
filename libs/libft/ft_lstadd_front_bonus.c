/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:36 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/12 18:30:41 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int	main(void)
{
	int	zero = 0;
	int	one = 1;
	int	two = 2;
	t_list	*lst;
	t_list	*first_node;
	t_list	*second_node;
	t_list	*new_first_node;

	first_node = ft_lstnew(&one);
	second_node = ft_lstnew(&two);
	first_node->next = second_node;
	lst = first_node;
	//while (lst)
	//{
	//	printf("content: %d\n", *(int *)lst->content);
	//	lst = lst->next;
	//}
	new_first_node = ft_lstnew(&zero);
	ft_lstadd_front(&lst, new_first_node);
	while (lst)
	{
		printf("content: %d\n", *(int *)lst->content);
		lst = lst->next;
	}
	return (0);
}*/
