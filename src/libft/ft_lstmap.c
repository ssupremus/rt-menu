/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:37:28 by anhloba           #+#    #+#             */
/*   Updated: 2018/04/02 00:01:19 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_list(void *content, size_t content_size)
{
	if (content != NULL)
	{
		free(content);
		content_size = 0;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flist;
	t_list	*nlist;
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	res = f(lst);
	if (!(nlist = ft_lstnew(res->content, res->content_size)))
		return (NULL);
	flist = nlist;
	lst = lst->next;
	while (lst)
	{
		res = f(lst);
		if (!(nlist->next = ft_lstnew(res->content, res->content_size)))
		{
			ft_lstdel(&flist, &free_list);
			return (NULL);
		}
		nlist = nlist->next;
		lst = lst->next;
	}
	return (flist);
}
