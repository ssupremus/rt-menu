/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 11:43:39 by anhloba           #+#    #+#             */
/*   Updated: 2018/06/28 11:34:46 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	find_word(char const *s, char c, size_t *lens, size_t *lenw)
{
	while (s[(*lens)] && s[(*lens)] == c)
		*lens = *lens + 1;
	*lenw = *lens;
	while (s[(*lenw)] && s[(*lenw)] != c)
		*lenw = *lenw + 1;
}

static	char	**notation(char **str, char const *s, char c, size_t nw)
{
	size_t	nwb;
	size_t	lens;
	size_t	lenw;
	size_t	i;

	nwb = 0;
	lens = 0;
	lenw = 0;
	while (nwb < nw)
	{
		find_word(s, c, &lens, &lenw);
		str[nwb] = (char *)malloc(sizeof(char) * (lenw - lens + 1));
		if (str[nwb] == 0)
			return (ft_free(str, &str, nwb));
		i = 0;
		while (lens < lenw)
			str[nwb][i++] = s[lens++];
		str[nwb][i] = '\0';
		nwb++;
	}
	str[nwb] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	nw;
	char	**str;

	i = 0;
	nw = 0;
	if (!s)
		return (NULL);
	if (s[i] && s[i] != c)
		nw++;
	while (s[i++])
		if (s[i] && s[i] != c && s[i - 1] == c)
			nw++;
	str = (char **)malloc(sizeof(char *) * (nw + 1));
	if (str == 0)
		return (NULL);
	notation(str, s, c, nw);
	return (str);
}
