/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:38:51 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/23 16:28:41 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

double	my_carg(t_t a)
{
	if (a.t1 > 0)
		return (atan(a.t2 / a.t1));
	else if (a.t1 < 0 && a.t2 >= 0)
		return (atan(a.t2 / a.t1) + M_PI);
	else if (a.t1 < 0 && a.t2 < 0)
		return (atan(a.t2 / a.t1) - M_PI);
	else if (a.t1 == 0 && a.t2 > 0)
		return (M_PI / 2);
	else if (a.t1 == 0 && a.t2 < 0)
		return (-M_PI / 2);
	else
		return (0);
}

t_t		my_csqrt(t_t a)
{
	return ((t_t){sqrt(hypot(a.t1, a.t2)) * cos(my_carg(a) / 2),
		sqrt(hypot(a.t1, a.t2)) * sin(my_carg(a) / 2)});
}

void	torus_helper(t_torus *t, t_figur *fgr)
{
	t->o1 = vek_skal(t->oc, t->oc);
	t->q = vek_skal(t->oc, fgr->dir);
	t->a[0] = (4.0 * t->m * t->n) / (t->m * t->m);
	t->a[1] = (4.0 * t->n * t->n + 2.0 * t->m * (t->o1 - fgr->r_r - fgr->r1_r1)
		+ 4.0 * fgr->r1_r1 * t->p * t->p) / (t->m * t->m);
	t->a[2] = (4.0 * t->n * (t->o1 - fgr->r_r - fgr->r1_r1) + 8.0 * fgr->r1_r1
		* t->p * t->q) / (t->m * t->m);
	t->a[3] = (pow(t->o1 - fgr->r_r - fgr->r1_r1, 2.0) + 4.0 * fgr->r1_r1 * t->q
		* t->q - 4.0 * fgr->r1_r1 * fgr->r_r) / (t->m * t->m);
}

t_t		tracer_torus(t_vek o, t_vek d, t_figur *fgr)
{
	t_figur	sp;
	t_t		sp_t;
	t_torus	t;

	sp = *fgr;
	sp.rad = fgr->rad + fgr->rad1;
	sp.r_r = pow(sp.rad, 2);
	sp_t = tracer_sphere(o, d, &sp);
	if (sp_t.t1 == -1.0 && sp_t.t2 == -1.0)
		return (sp_t);
	t.oc = vek_sub(o, fgr->centr);
	t.m = vek_skal(d, d);
	t.n = vek_skal(t.oc, d);
	t.p = vek_skal(d, fgr->dir);
	torus_helper(&t, fgr);
	t.n_roots = quadric(t.roots, t.a);
	if ((t.root = 0.0) && !t.n_roots)
		return ((t_t){-1, -1});
	t.i = -1;
	while (++t.i < t.n_roots)
	{
		!t.i ? t.root = t.roots[t.i] : 0;
		t.roots[t.i] < t.root ? t.root = t.roots[t.i] : 0;
	}
	return ((t_t){t.root, -1});
}
