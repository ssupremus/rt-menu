/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 18:40:14 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 20:25:05 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_color	color_blur(t_color c, double coef)
{
	t_color col;

	col.r = debug(c.r * coef);
	col.g = debug(c.g * coef);
	col.b = debug(c.b * coef);
	col.a = 255;
	return (col);
}

t_color	color_sum_blur(t_color v1, t_color v2)
{
	t_color	sum;

	sum.r = v1.r + v2.r;
	sum.g = v1.g + v2.g;
	sum.b = v1.b + v2.b;
	sum.a = 255;
	return (sum);
}

void	blur(t_color *c, int w, int h, int r)
{
	int		x_y_kx_ky[4];
	t_color	total;
	t_color	pix;

	x_y_kx_ky[0] = r - 1;
	while (++x_y_kx_ky[0] < w - r && (x_y_kx_ky[1] = r - 1))
		while (++x_y_kx_ky[1] < h - r && (x_y_kx_ky[3] = -r - 1))
		{
			total = (t_color){0, 0, 0, 254};
			while (++x_y_kx_ky[3] <= r && (x_y_kx_ky[2] = -r - 1))
				while (++x_y_kx_ky[2] <= r)
				{
					pix = c[(x_y_kx_ky[0] + x_y_kx_ky[2]) * w
						+ x_y_kx_ky[1] + x_y_kx_ky[3]];
					total = color_sum_blur(total, pix);
				}
			if (total.a != 254)
			{
				total = color_blur(total, 1.0 / ((r * 2 + 1) * (r * 2 + 1)));
				c[x_y_kx_ky[0] * w + x_y_kx_ky[1]] = total;
			}
		}
}
