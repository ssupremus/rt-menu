/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piveden.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 22:44:01 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:44:39 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

int		helper1_priv(double *x, double c)
{
	double	p;
	double	q;
	double	r1;

	p = sqrt(x[0]);
	q = sqrt(x[1]);
	r1 = sqrt(x[2]);
	if (c > 0.0)
	{
		x[0] = (-p - q - r1) / 2.0;
		x[1] = (-p + q + r1) / 2.0;
		x[2] = (p - q + r1) / 2.0;
		x[3] = (p + q - r1) / 2.0;
		return (4);
	}
	x[0] = (-p - q + r1) / 2.0;
	x[1] = (-p + q - r1) / 2.0;
	x[2] = (p - q - r1) / 2.0;
	x[3] = (p + q + r1) / 2.0;
	return (4);
}

int		helper2_priv(double *x, double c)
{
	double	p;
	double	q;
	double	r1;

	p = sqrt(-x[0]);
	q = sqrt(-x[1]);
	r1 = sqrt(x[2]);
	if (c > 0.0)
	{
		x[0] = -r1 / 2.0;
		x[1] = (p - q) / 2.0;
		x[2] = r1 / 2.0;
		x[3] = (-p - q) / 2.0;
		return (0);
	}
	x[0] = r1 / 2.0;
	x[1] = (-p + q) / 2.0;
	x[2] = -r1 / 2.0;
	x[3] = (p + q) / 2.0;
	return (0);
}

int		helper3_priv(double *x, double c)
{
	double	p;
	t_t		roots;

	if (x[0] < 0.0)
		x[0] = 0.0;
	p = sqrt(x[0]);
	roots = my_csqrt((t_t){x[1], x[2]});
	if (c > 0)
	{
		x[0] = -p / 2.0 - roots.t1;
		x[1] = -p / 2.0 + roots.t1;
		x[2] = p / 2.0;
		x[3] = roots.t2;
		return (2);
	}
	x[0] = p / 2.0 - roots.t1;
	x[1] = p / 2.0 + roots.t1;
	x[2] = -p / 2.0;
	x[3] = roots.t2;
	return (2);
}

int		privedennoe(double *x, double b, double c, double d)
{
	int		r;

	if (fabs(c) < 1e-14F * (fabs(b) + fabs(d)))
		return (bikvadrat(x, b, d));
	r = resolventa(x, 2.0 * b, b * b - 4.0 * d, -c * c);
	if (r > 1.0)
	{
		swap_roots(&x[0], &x[1], &x[2]);
		if (x[0] > 0.0)
			return (helper1_priv(x, c));
		return (helper2_priv(x, c));
	}
	return (helper3_priv(x, c));
}
