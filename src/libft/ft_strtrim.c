/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:29:29 by anhloba           #+#    #+#             */
/*   Updated: 2018/04/01 23:42:28 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	size_t	st;
	size_t	en;
	size_t	i;

	i = 0;
	st = 0;
	if (s == NULL)
		return (NULL);
	en = ft_strlen(s) - 1;
	while ((s[en] == '\t' || s[en] == '\n' || s[en] == ' ') && en != 0)
		en--;
	while (s[st] == '\t' || s[st] == '\n' || s[st] == ' ')
		st++;
	if (s[st] == '\0')
		st = 1;
	s1 = (char *)malloc(sizeof(*s1) * (en - st + 2));
	if (s1 == 0)
		return (NULL);
	while (st < en + 1)
		s1[i++] = s[st++];
	s1[i] = '\0';
	return (s1);
}
