/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_efects2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:33:55 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 21:37:50 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_color	gray(t_color c)
{
	t_color	c1;

	c1 = c;
	c.r = debug(0.3 * c1.r + 0.787 * c1.g + 0.08 * c1.b);
	c.g = debug(0.3 * c1.r + 0.787 * c1.g + 0.08 * c1.b);
	c.b = debug(0.3 * c1.r + 0.787 * c1.g + 0.08 * c1.b);
	return (c);
}

t_color	gray1(t_color c)
{
	t_color	c1;

	c1 = c;
	c.r = debug((c1.r + c1.g + c1.b) / 1.8);
	c.g = debug((c1.r + c1.g + c1.b) / 1.8);
	c.b = debug((c1.r + c1.g + c1.b) / 1.8);
	return (c);
}

t_color	negativ(t_color c)
{
	c.r = debug(256.0 - c.r);
	c.g = debug(256.0 - c.g);
	c.b = debug(256.0 - c.b);
	return (c);
}

t_color	sepiya(t_color c)
{
	c.r = debug(0.3 * c.r + 0.587 * c.g + 0.12 * c.b);
	c.g = debug(0.3 * c.r + 0.587 * c.g + 0.12 * c.b);
	c.b = debug(0.3 * c.r + 0.587 * c.g + 0.12 * c.b);
	return (c);
}

t_color	col_efekt(t_color c, t_r *rtv)
{
	if (rtv->col_efekt == NON)
		return (c);
	else if (rtv->col_efekt == MULT1)
		c = mult1(c);
	else if (rtv->col_efekt == MULT)
		c = mult(c);
	else if (rtv->col_efekt == ABSTRAKT)
		c = abstrakt(c);
	else if (rtv->col_efekt == B_W)
		c = b_w_color(c);
	else if (rtv->col_efekt == GRAY1)
		c = gray1(c);
	else if (rtv->col_efekt == GRAY)
		c = gray(c);
	else if (rtv->col_efekt == NEG)
		c = negativ(c);
	else if (rtv->col_efekt == SEP)
		c = sepiya(c);
	return (c);
}
