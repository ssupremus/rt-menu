/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:44:48 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/06 20:22:41 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

int		p_atoi(const char *str)
{
	int		n;
	int		res;

	n = 1;
	res = 0;
	while ((*str < '0' || *str > '9') && *str != '-')
		str++;
	if (*str == '-')
	{
		n = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (n == -1 ? -res : res);
}

double	p_atof(const char *str)
{
	while ((*str < '0' || *str > '9') && *str != '-')
		str++;
	return (atof(str));
}
