/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:02:32 by exam              #+#    #+#             */
/*   Updated: 2018/06/28 13:17:19 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(int value, int base)
{
	int count;

	count = 0;
	if (value == 0)
		return (1);
	if (value < 0)
	{
		count++;
		value = ft_abs(value / base);
		if (base == 10)
			count++;
	}
	while (value > 0)
	{
		value = ft_abs(value / base);
		count++;
	}
	return (count);
}

char		*ft_itoa_base(int value, int base)
{
	int		count;
	int		tmp;
	char	*result;
	char	*f;

	tmp = value;
	result = NULL;
	f = "0123456789ABCDEF";
	if (base >= 2 && base <= 16)
	{
		count = ft_count(value, base);
		result = (char*)malloc(sizeof(char) * (count + 1));
		result[count] = '\0';
		count--;
		while (count >= 0)
		{
			result[count--] = f[ft_abs(tmp % base)];
			tmp = ft_abs(tmp / base);
			if (count == 0 && value < 0 && base == 10)
				result[count--] = '-';
		}
	}
	return (result);
}
