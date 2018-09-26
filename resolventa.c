/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolventa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 21:16:57 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/23 12:57:26 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

double	pereschet(double x)
{
	double	s;
	double	r;
	int		i;

	s = 1.0;
	r = 1.5;
	while (x < 1.0)
	{
		x *= 8.0;
		s *= 0.5;
	}
	while (x > 8.0)
	{
		x *= 0.125;
		s *= 2.0;
	}
	i = -1;
	while (++i < 6)
		r -= 1.0 / 3.0 * (r - x / (r * r));
	return (r * s);
}

double	proverka_res(double x)
{
	if (x > 0.0)
		return (pereschet(x));
	else
	{
		if (x < 0.0)
			return (-pereschet(-x));
		else
			return (0.0);
	}
}

int		helper1_res(double *x, double a, double q, double r)
{
	double	t;

	t = r / sqrt(q * q * q);
	if (t < -1.0)
		t = -1.0;
	if (t > 1.0)
		t = 1.0;
	t = acos(t);
	a /= 3.0;
	q = -2.0 * sqrt(q);
	x[0] = q * cos(t / 3.0) - a;
	x[1] = q * cos((t + M_PI * 2) / 3.0) - a;
	x[2] = q * cos((t - M_PI * 2) / 3.0) - a;
	return (3);
}

int		helper2_res(double *x, double a, double q, double r)
{
	double aa;
	double bb;

	aa = -proverka_res(fabs(r) + sqrt(r * r - q * q * q));
	if (r < 0.0)
		aa = -aa;
	bb = aa == 0.0 ? 0.0 : q / aa;
	a /= 3.0;
	x[0] = (aa + bb) - a;
	x[1] = -0.5 * (aa + bb) - a;
	x[2] = 0.5 * sqrt(3.0) * (aa - bb);
	if (fabs(x[2]) < 1e-14F)
	{
		x[2] = x[1];
		return (2);
	}
	return (1);
}

int		resolventa(double *x, double a, double b, double c)
{
	double a2;
	double q;
	double r;

	a2 = a * a;
	q = (a2 - 3.0 * b) / 9.0;
	r = (a * (2.0 * a2 - 9.0 * b) + 27.0 * c) / 54.0;
	if (r * r <= (q * q * q + 1e-14F))
		return (helper1_res(x, a, q, r));
	else
		return (helper2_res(x, a, q, r));
}
