/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bikvadrat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 22:45:13 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:45:46 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

int		helper1_bik(double *x, double x1, double x2)
{
	double	s_x1;
	double	s_x2;

	s_x1 = sqrt(x1);
	s_x2 = sqrt(x2);
	x[0] = -s_x1;
	x[1] = s_x1;
	x[2] = -s_x2;
	x[3] = s_x2;
	return (4);
}

int		helper2_bik(double *x, double x1, double x2)
{
	double	s_x1;
	double	s_x2;

	s_x1 = sqrt(-x1);
	s_x2 = sqrt(-x2);
	x[0] = 0.0;
	x[1] = s_x1;
	x[2] = 0.0;
	x[3] = s_x2;
	return (0);
}

int		helper3_bik(double *x, double x1, double x2)
{
	double	s_x1;
	double	s_x2;

	s_x1 = sqrt(x1);
	s_x2 = sqrt(-x2);
	x[0] = -s_x1;
	x[1] = s_x1;
	x[2] = 0.0;
	x[3] = s_x2;
	return (2);
}

int		helper4_bik(double *x, double b, double dis)
{
	t_t		res;

	dis = 0.5 * sqrt(-dis);
	res = my_csqrt((t_t){-0.5 * b, dis});
	x[0] = res.t1;
	x[1] = res.t2;
	res = my_csqrt((t_t){-0.5 * b, -dis});
	x[2] = res.t1;
	x[3] = res.t2;
	return (0);
}

int		bikvadrat(double *x, double b, double d)
{
	double	dis;
	double	x1;
	double	x2;

	dis = b * b - 4.0 * d;
	if (dis >= 0.0)
	{
		dis = sqrt(dis);
		x1 = (-b + dis) / 2.0;
		x2 = (-b - dis) / 2.0;
		if (x2 >= 0.0)
			return (helper1_bik(x, x1, x2));
		if (x1 < 0.0)
			return (helper2_bik(x, x1, x2));
		return (helper3_bik(x, x1, x2));
	}
	else
		return (helper3_bik(x, b, dis));
}
