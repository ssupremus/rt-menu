/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 19:27:21 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/06 20:16:37 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	zoom_on(t_r *rtv, int s)
{
	if (s == 1)
		rtv->c += 0.05;
	else
		rtv->pos.z += 1;
	draw(rtv);
}

void	zoom_of(t_r *rtv, int s)
{
	if (s == 1)
		rtv->c -= 0.05;
	else
		rtv->pos.z -= 1;
	draw(rtv);
}
