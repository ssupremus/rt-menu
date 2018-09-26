/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 20:30:23 by anhloba           #+#    #+#             */
/*   Updated: 2018/04/01 23:37:27 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*nlist;

	if (!del || !alst || *alst == NULL)
		return ;
	list = *alst;
	while (list != NULL)
	{
		nlist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nlist;
	}
	*alst = NULL;
}
