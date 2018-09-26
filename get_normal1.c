/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 22:10:55 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 22:11:43 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_vek	get_norm_sphere(t_figur *sf, t_vek p)
{
	t_vek	n;

	n = vek_sub(p, sf->centr);
	n = vek_num(n, 1 / vek_len(n));
	return (n);
}

t_vek	get_norm_cylinder(t_figur *sf, t_tracer *tr, t_vek o, t_vek d)
{
	double	m;
	t_vek	n;
	t_vek	oc;

	oc = vek_sub(o, sf->centr);
	m = vek_skal(d, sf->dir) * tr->t_max + vek_skal(oc, sf->dir);
	n = vek_sub(vek_sub(tr->p, sf->centr), vek_num(sf->dir, m));
	n = vek_num(n, 1 / vek_len(n));
	return (n);
}

t_vek	get_norm_plane(t_figur *sf)
{
	return (sf->dir);
}
