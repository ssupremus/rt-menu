/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fig_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:35:11 by ylesik            #+#    #+#             */
/*   Updated: 2018/09/24 15:38:41 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

int		pars_fig_close(t_r *rtv, int i, char *str, char *str_end)
{
	int	count;

	count = 0;
	while (ft_strstr(rtv->list[i++], str_end) == 0 && rtv->list[i] != NULL)
	{
		if (ft_strstr(rtv->list[i], str) != 0)
			return (0);
		if (count > 0 && ft_strstr(rtv->list[i], str_end) != 0)
			return (1);
		count++;
	}
	return (0);
}
