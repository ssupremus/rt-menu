/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_obj1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 22:59:10 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:59:14 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_t		tracer_helper(t_vek d, t_figur *fgr, t_vek oc, t_t t)
{
	double	m;

	m = vek_skal(d, fgr->cut_f[0]) * t.t1 + vek_skal(oc, fgr->cut_f[0]);
	if (m < fgr->min_fgr[0] || m > fgr->max_fgr[0])
		t.t1 = -1;
	m = vek_skal(d, fgr->cut_real) * t.t1 + vek_skal(oc, fgr->cut_real);
	if (m < fgr->min_real || m > fgr->max_real)
		t.t1 = -1;
	m = vek_skal(d, fgr->cut_f[0]) * t.t2 + vek_skal(oc, fgr->cut_f[0]);
	if (m < fgr->min_fgr[0] || m > fgr->max_fgr[0])
		t.t2 = -1;
	m = vek_skal(d, fgr->cut_real) * t.t2 + vek_skal(oc, fgr->cut_real);
	if (m < fgr->min_real || m > fgr->max_real)
		t.t2 = -1;
	return (t);
}

t_t		tracer_sphere(t_vek o, t_vek d, t_figur *fgr)
{
	t_t		t;
	t_vek	k;
	t_vek	oc;
	double	dis;

	oc = vek_sub(o, fgr->centr);
	k.x = vek_skal(d, d);
	k.y = 2 * vek_skal(oc, d);
	k.z = vek_skal(oc, oc) - fgr->r_r;
	dis = k.y * k.y - 4 * k.x * k.z;
	if (dis < 0)
		return ((t_t){-1, -1});
	t.t1 = (-k.y + sqrt(dis)) / (2 * k.x);
	t.t2 = (-k.y - sqrt(dis)) / (2 * k.x);
	t = tracer_helper(d, fgr, oc, t);
	return (t);
}
