/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:13:45 by anhloba           #+#    #+#             */
/*   Updated: 2018/04/01 23:45:26 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src,
					size_t dstsize)
{
	size_t	nd;
	size_t	ns;

	nd = ft_strlen(dst);
	ns = ft_strlen(src);
	if (nd + 1 > dstsize)
		return (ns + dstsize);
	else
		ft_strncat(dst, src, dstsize - nd - 1);
	return (nd + ns);
}
