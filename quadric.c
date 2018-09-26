/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:10:31 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:50:52 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	swap1(double *a, double *b)
{
	double	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void	swap_roots(double *a, double *b, double *c)
{
	if (a > b)
		swap1(a, b);
	if (c < b)
	{
		swap1(b, c);
		if (a > b)
			swap1(a, b);
	}
}

double	quad(double x, double *a)
{
	double	dis;
	double	x1;

	dis = ((4.0 * x + 3.0 * a[0]) * x + 2.0 * a[1]) * x + a[2];
	if (dis == 0.0)
		return (x);
	x1 = (((x + a[0]) * x + a[1]) * x + a[2]) * x + a[3];
	return (x - x1 / dis);
}

int		quadric(double *x, double *a)
{
	double	d1;
	double	c1;
	double	b1;
	int		res;
	double	a_4;

	d1 = a[3] + 0.25 * a[0] * (0.25 * a[1] * a[0] - 3.0
		/ 64.0 * pow(a[0], 3) - a[2]);
	c1 = a[2] + 0.5 * a[0] * (0.25 * a[0] * a[0] - a[1]);
	b1 = a[1] - 0.375 * a[0] * a[0];
	res = privedennoe(x, b1, c1, d1);
	a_4 = a[0] / 4.0;
	if (res > 0)
	{
		x[0] = quad(x[0] - a_4, a);
		x[1] = quad(x[1] - a_4, a);
	}
	if (res > 2)
	{
		x[2] = quad(x[2] - a_4, a);
		x[3] = quad(x[3] - a_4, a);
	}
	return (res);
}
