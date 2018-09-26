/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 11:33:15 by anhloba           #+#    #+#             */
/*   Updated: 2018/06/28 11:40:10 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **str, char ***str1, size_t nwb)
{
	while (nwb)
		free(str[--nwb]);
	free(str);
	*str1 = NULL;
	return (NULL);
}
