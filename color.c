/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:35:58 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:27:45 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

int		debug(int color)
{
	if (color > 255)
		return (255);
	else if (color < 0)
		return (0);
	return (color);
}

t_color	color(t_color c, double coef)
{
	t_color col;

	col.r = debug((c.r & 255) * coef);
	col.g = debug((c.g & 255) * coef);
	col.b = debug((c.b & 255) * coef);
	if (c.a == 255)
		col.a = 255;
	return (col);
}

t_color	color_sum(t_color v1, t_color v2)
{
	t_color	sum;

	sum.r = debug(v1.r + v2.r);
	sum.g = debug(v1.g + v2.g);
	sum.b = debug(v1.b + v2.b);
	return (sum);
}
