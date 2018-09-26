/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:39:29 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/25 14:46:47 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_figur	*closest(t_r *rtv, t_draw *dr, t_vek *d, double *t_max)
{
	t_figur	*sf1;
	t_t		t;
	int		i;

	i = -1;
	sf1 = NULL;
	*t_max = dr->min_max.t2;
	while (++i < NUM_FIG)
		if (rtv->fgr[i].name != 0)
		{
			t = tracer_obj(dr->o, d[0], &rtv->fgr[i]);
			if (t.t1 > dr->min_max.t1 && t.t1 < *t_max)
			{
				*t_max = t.t1;
				sf1 = &rtv->fgr[i];
			}
			if (t.t2 > dr->min_max.t1 && t.t2 < *t_max)
			{
				*t_max = t.t2;
				sf1 = &rtv->fgr[i];
			}
		}
	return (sf1);
}

t_figur	*closest_sd(t_r *rtv, t_vek o, t_vek *d, t_t min_max)
{
	t_figur	*sf1;
	t_t		t;
	int		i;
	double	t_max;

	i = -1;
	sf1 = NULL;
	t_max = min_max.t2;
	while (++i < NUM_FIG)
		if (rtv->fgr[i].trans < 1 && rtv->fgr[i].name != 0)
		{
			t = tracer_obj(o, d[0], &rtv->fgr[i]);
			if (t.t1 > min_max.t1 && t.t1 < t_max)
			{
				t_max = t.t1;
				sf1 = &rtv->fgr[i];
			}
			if (t.t2 > min_max.t1 && t.t2 < t_max)
			{
				t_max = t.t2;
				sf1 = &rtv->fgr[i];
			}
		}
	return (sf1);
}
