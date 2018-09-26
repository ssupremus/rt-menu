/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:00:29 by anhloba           #+#    #+#             */
/*   Updated: 2018/04/02 01:21:00 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	a;

	i = 1;
	j = 10;
	a = n;
	if (n < 0)
	{
		a = -a;
		i++;
	}
	while (a / j > 0 && ++i)
		j = j * 10;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
		s[i++] = '-';
	while ((j /= 10) > 0)
		s[i++] = (a / j) % 10 + 48;
	s[i] = '\0';
	return (s);
}
