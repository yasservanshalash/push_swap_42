/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:58:46 by yasser            #+#    #+#             */
/*   Updated: 2023/11/01 18:43:56 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_new_list(t_list *new_list, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = new_list;
	while (current)
	{
		next = current->next;
		if (del)
			del(current->content);
		free(current);
		current = next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	void	*new_content;
	t_list	*new_node;

	new_list = NULL;
	current = lst;
	while (current)
	{
		new_content = f(current->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			free_new_list(new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		current = current->next;
	}
	return (new_list);
}
