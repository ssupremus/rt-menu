/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 19:27:25 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/22 16:50:25 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	dvig_left(t_r *rtv, int s)
{
	if (s == 1)
		rtv->a -= 0.1;
	else
		rtv->pos.x -= 1;
	draw(rtv);
}

void	dvig_right(t_r *rtv, int s)
{
	if (s == 1)
		rtv->a += 0.1;
	else
		rtv->pos.x += 1;
	draw(rtv);
}

void	dvig_up(t_r *rtv, int s)
{
	if (s == 1)
		rtv->b -= 0.1;
	else
		rtv->pos.y -= 1;
	draw(rtv);
}

void	dvig_down(t_r *rtv, int s)
{
	if (s == 1)
		rtv->b += 0.1;
	else
		rtv->pos.y += 1;
	draw(rtv);
}
