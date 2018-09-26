/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_efects1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:31:34 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:28:35 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_color	mult(t_color c)
{
	t_color	c1;

	c1 = c;
	c.r = debug(abs(c1.g - c1.b + c1.g + c1.r) * c1.r / 256.0);
	c.g = debug(abs(c1.b - c1.g + c1.b + c1.r) * c1.r / 256.0);
	c.b = debug(abs(c1.b - c1.g + c1.b + c1.r) * c1.g / 256.0);
	return (c);
}

t_color	mult1(t_color c)
{
	c.r = debug(c.r * 128.0 / (c.g + c.b + 1.0));
	c.g = debug(c.g * 128.0 / (c.r + c.b + 1.0));
	c.b = debug(c.b * 128.0 / (c.g + c.r + 1.0));
	return (c);
}

t_color	abstrakt(t_color c)
{
	t_color	c1;

	c1 = c;
	c.r = abs(c1.g - c1.b + c1.g + c1.r) * c1.r / 256.0;
	c.g = abs(c1.b - c1.g + c1.b + c1.r) * c1.r / 256.0;
	c.b = abs(c1.b - c1.g + c1.b + c1.r) * c1.g / 256.0;
	return (c);
}

t_color	b_w_color(t_color c)
{
	double	b_w;
	t_color	c1;

	c1 = c;
	b_w = (c1.r + c1.g + c1.b) / 2.0;
	if (b_w > 100)
		c = (t_color){255, 255, 255, 255};
	else
		c = color(c, 0.0);
	c.a = 255;
	return (c);
}
