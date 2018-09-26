/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:58:49 by anhloba           #+#    #+#             */
/*   Updated: 2018/03/31 18:16:15 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*s1;

	i = 0;
	if (s == NULL)
		return (NULL);
	s1 = (char *)malloc(sizeof(*s1) * (ft_strlen(s) + 1));
	if (s1 == 0)
		return (0);
	while (s[i])
	{
		s1[i] = f(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
