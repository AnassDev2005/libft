/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:18:07 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/24 18:02:56 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	current = lst;
	content = f(current->content);
	head = ft_lstnew(content);
	if (!head)
	{
		del(content);
		return (NULL);
	}
	current = current->next;
	while (current)
	{
		content = f(current->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		current = current->next;
	}
	return (head);
}
