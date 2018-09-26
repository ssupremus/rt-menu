/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 11:59:53 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:14:23 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_vek	get_norm_cone(t_figur *sf, t_tracer *tr, t_vek o, t_vek d)
{
	double	m;
	t_vek	n;
	t_vek	oc;

	oc = vek_sub(o, sf->centr);
	m = vek_skal(d, sf->dir) * tr->t_max + vek_skal(oc, sf->dir);
	n = vek_sub(vek_sub(tr->p, sf->centr), vek_num(sf->dir, (1 + sf->r_r) * m));
	n = vek_num(n, 1 / vek_len(n));
	return (n);
}

t_vek	get_norm_parabol(t_figur *sf, t_tracer *tr, t_vek o, t_vek d)
{
	double	m;
	t_vek	n;
	t_vek	oc;

	oc = vek_sub(o, sf->centr);
	m = vek_skal(d, sf->dir) * tr->t_max + vek_skal(oc, sf->dir);
	n = vek_sub(vek_sub(tr->p, sf->centr), vek_num(sf->dir, (m + sf->rad)));
	n = vek_num(n, 1 / vek_len(n));
	return (n);
}

t_vek	get_norm_mebius(t_figur *sf, t_vek p)
{
	t_vek	n;

	n = (t_vek){2.0 * p.x * p.y - 2.0 * sf->rad * p.z - 4.0 * p.x * p.z,
			-sf->rad * sf->rad + p.x * p.x + 3.0 * p.y * p.y - 4.0 * p.y
			* p.z + p.z * p.z, -2.0 * sf->rad * p.x - 2.0 * p.x * p.x - 2.0
			* p.y * p.y + 2.0 * p.y * p.z};
	n = vek_num(n, 1 / vek_len(n));
	return (n);
}

t_vek	get_norm_torus(t_figur *sf, t_vek p)
{
	t_vek	n;
	t_vek	a;
	double	k;
	double	m;

	k = vek_skal(vek_sub(p, sf->centr), sf->dir);
	a = vek_sub(p, vek_num(sf->dir, k));
	m = sqrt(sf->rad * sf->rad - k * k);
	n = vek_sub(vek_sub(p, a), vek_num(vek_sub(sf->centr, a),
		(m / (sf->rad1 + m))));
	n = vek_num(n, 1 / vek_len(n));
	return (n);
}

t_vek	get_normal(t_tracer *tr, t_draw *dr, t_vek d)
{
	if (dr->sf->name == SPHERE)
		return (get_norm_sphere(dr->sf, tr->p));
	else if (dr->sf->name == PLANE)
		return (get_norm_plane(dr->sf));
	else if (dr->sf->name == CYLINDER)
		return (get_norm_cylinder(dr->sf, tr, dr->o, d));
	else if (dr->sf->name == CONE)
		return (get_norm_cone(dr->sf, tr, dr->o, d));
	else if (dr->sf->name == PARABOL)
		return (get_norm_parabol(dr->sf, tr, dr->o, d));
	else if (dr->sf->name == MEBIUS)
		return (get_norm_mebius(dr->sf, tr->p));
	else if (dr->sf->name == TORUS)
		return (get_norm_torus(dr->sf, tr->p));
	return ((t_vek){0, 0, 0});
}
