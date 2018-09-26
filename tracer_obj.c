/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:56:29 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 23:00:09 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_t		tracer_plane(t_vek o, t_vek d, t_figur *fgr)
{
	t_t		t;
	t_vek	oc;
	double	m1;
	double	m2;
	double	m3;

	oc = vek_sub(o, fgr->centr);
	t.t1 = -1;
	if (fgr->direct.x != 0 || fgr->direct.y != 0 || fgr->direct.z != 0)
		t.t1 = vek_skal(vek_num(oc, -1), fgr->dir) / vek_skal(d, fgr->dir);
	m1 = vek_skal(d, fgr->cut_f[0]) * t.t1 + vek_skal(oc, fgr->cut_f[0]);
	m2 = vek_skal(d, fgr->cut_f[1]) * t.t1 + vek_skal(oc, fgr->cut_f[1]);
	m3 = vek_skal(d, fgr->cut_f[2]) * t.t1 + vek_skal(oc, fgr->cut_f[2]);
	if ((m1 < fgr->min_fgr[0] || m1 > fgr->max_fgr[0]) ||
		(m2 < fgr->min_fgr[1] || m2 > fgr->max_fgr[1]) ||
		(m3 < fgr->min_fgr[2] || m3 > fgr->max_fgr[2]))
		t.t1 = -1;
	m1 = vek_skal(d, fgr->cut_real) * t.t1 + vek_skal(oc, fgr->cut_real);
	if (m1 < fgr->min_real || m1 > fgr->max_real)
		t.t1 = -1;
	return ((t_t){t.t1, -1});
}

t_t		tracer_cylinder(t_vek o, t_vek d, t_figur *fgr)
{
	t_vek	k;
	t_t		t;
	double	dis;
	t_vek	oc;

	oc = vek_sub(o, fgr->centr);
	k.x = vek_skal(d, d) - pow(vek_skal(d, fgr->dir), 2);
	k.y = 2 * (vek_skal(d, oc) - vek_skal(d, fgr->dir) *
		vek_skal(oc, fgr->dir));
	k.z = vek_skal(oc, oc) - pow(vek_skal(oc, fgr->dir), 2) - fgr->r_r;
	dis = k.y * k.y - 4 * k.x * k.z;
	if (dis < 0)
		return ((t_t){-1, -1});
	t.t1 = (-k.y + sqrt(dis)) / (2 * k.x);
	t.t2 = (-k.y - sqrt(dis)) / (2 * k.x);
	t = tracer_helper(d, fgr, oc, t);
	return (t);
}

t_t		tracer_cone(t_vek o, t_vek d, t_figur *fgr)
{
	t_t		t;
	double	dis;
	t_vek	k;
	t_vek	oc;

	oc = vek_sub(o, fgr->centr);
	k.x = vek_skal(d, d) - (1 + fgr->r_r) * pow(vek_skal(d, fgr->dir), 2);
	k.y = 2 * (vek_skal(d, oc) - (1 + fgr->r_r) *
		vek_skal(d, fgr->dir) * vek_skal(oc, fgr->dir));
	k.z = vek_skal(oc, oc) - (1 + fgr->r_r) *
			pow(vek_skal(oc, fgr->dir), 2);
	dis = k.y * k.y - 4 * k.x * k.z;
	if (dis < 0)
		return ((t_t){-1, -1});
	t.t1 = (-k.y + sqrt(dis)) / (2 * k.x);
	t.t2 = (-k.y - sqrt(dis)) / (2 * k.x);
	t = tracer_helper(d, fgr, oc, t);
	return (t);
}

t_t		tracer_parabol(t_vek o, t_vek d, t_figur *fgr)
{
	t_vek	k;
	t_t		t;
	double	dis;
	t_vek	oc;

	oc = vek_sub(o, fgr->centr);
	k.x = vek_skal(d, d) - pow(vek_skal(d, fgr->dir), 2);
	k.y = 2 * (vek_skal(d, oc) - vek_skal(d, fgr->dir)
		* (vek_skal(oc, fgr->dir) + 2 * fgr->rad));
	k.z = vek_skal(oc, oc) - vek_skal(oc, fgr->dir)
		* (vek_skal(oc, fgr->dir) + 4 * fgr->rad);
	dis = k.y * k.y - 4 * k.x * k.z;
	if (dis < 0)
		return ((t_t){-1, -1});
	t.t1 = (-k.y + sqrt(dis)) / (2 * k.x);
	t.t2 = (-k.y - sqrt(dis)) / (2 * k.x);
	t = tracer_helper(d, fgr, oc, t);
	return (t);
}

t_t		tracer_obj(t_vek o, t_vek d, t_figur *fgr)
{
	if (fgr->name == SPHERE)
		return (tracer_sphere(o, d, fgr));
	else if (fgr->name == PLANE)
		return (tracer_plane(o, d, fgr));
	else if (fgr->name == CYLINDER)
		return (tracer_cylinder(o, d, fgr));
	else if (fgr->name == CONE)
		return (tracer_cone(o, d, fgr));
	else if (fgr->name == PARABOL)
		return (tracer_parabol(o, d, fgr));
	else if (fgr->name == MEBIUS)
		return (tracer_mebius(vek_sub(o, fgr->dir), d, fgr));
	else if (fgr->name == TORUS)
		return (tracer_torus(o, d, fgr));
	return ((t_t){-1, -1});
}
