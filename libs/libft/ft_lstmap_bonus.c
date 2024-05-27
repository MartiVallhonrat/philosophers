/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:01:42 by mvallhon          #+#    #+#             */
/*   Updated: 2024/01/16 17:06:48 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*void	*get_half(void *n)
{
	int *result = (int *)n;
	*result = *result / 2;
	printf("content now: %d\n", *result);
	return (result);
}

void	delete_f(void *lst)
{
	printf("Delete!");
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_new_lst;
	t_list	*new_lst;
	void	*data;

	if (!lst || !f || !del)
		return (NULL);
	first_new_lst = NULL;
	while (lst)
	{
		data = f(lst->content);
		new_lst = ft_lstnew((data));
		if (!new_lst)
		{
			ft_lstclear(&first_new_lst, del);
			del(data);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&first_new_lst, new_lst);
	}
	return (first_new_lst);
}

/*int	main(void)
{
	int	two = 2;
	int	four = 4;
	int	six = 6;
	t_list	*lst;
	t_list	*first_node;
	t_list	*second_node;
	t_list	*new_last_node;

	first_node = ft_lstnew(&two);
	second_node = ft_lstnew(&four);
	first_node->next = second_node;
	lst = first_node;
	new_last_node = ft_lstnew(&six);
	ft_lstadd_back(&lst, new_last_node);
	while (lst)
	{
		printf("lst before func: %d\n", *(int *)lst->content);
		lst = lst->next;
	}
	t_list	*new_lst;
	lst = first_node;
	new_lst = ft_lstmap(lst, get_half, delete_f);
	while (new_lst)
	{
		printf("lst after func: %d\n", *(int *)new_lst->content);
		new_lst = new_lst->next;
	}
	printf("test: %p\n", new_lst);
	return (0);
}*/
