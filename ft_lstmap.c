/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 17:18:07 by anes-sal          #+#    #+#             */
/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	**tail;
	void	*content;

	if (!f || !del)
		return (NULL);
	head = NULL;
	tail = &head;
	while (lst)
	{
		content = f(lst->content);
		*tail = ft_lstnew(content);
		if (!*tail)
		{
			del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		tail = &(*tail)->next;
		lst = lst->next;
	}
	return (head);
}
