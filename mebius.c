/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mebius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:47:03 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/25 16:58:38 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

int		proverka(double x)
{
	if (x < -0.0000003F)
		return (-1);
	return (x > 0.0000003F);
}

int		in_meb(t_vek p, t_figur *fgr)
{
	double	t;
	double	s;
	t_t		sinus;
	t_t		cosin;

	t = atan2(p.y, p.x);
	s = t;
	sinus = (t_t){sin(t), sin(t / 2.0F)};
	cosin = (t_t){cos(t), cos(t / 2.0F)};
	if (sinus.t2)
		s = p.z / sinus.t2;
	else if (cosin.t1 && cosin.t2)
		s = (p.x / cosin.t1 - fgr->rad) / cosin.t2;
	else if (sinus.t1 && cosin.t2)
		s = (p.y / sinus.t1 - fgr->rad) / cosin.t2;
	p.x -= (fgr->rad + s * cosin.t2) * cosin.t1;
	p.y -= (fgr->rad + s * cosin.t2) * sinus.t1;
	p.z -= s * sinus.t2;
	if (proverka(vek_skal(p, p)))
		return (0);
	return (s >= -fgr->rad1 && s <= fgr->rad1);
}

void	mebius_helper(t_mebius *m, t_figur *fgr, t_vek d)
{
	m->a1 = pow(m->oc.x, 2) * m->oc.y + pow(m->oc.y, 3) - 2.0 * pow(m->oc.x, 2)
		* m->oc.z - 2.0 * pow(m->oc.y, 2) * m->oc.z + m->oc.y * pow(m->oc.z, 2)
		- 2.0 * m->oc.x * m->oc.z * fgr->rad - m->oc.y * fgr->r_r;
	m->a2 = d.y * pow(m->oc.x, 2) - 2.0 * d.z * pow(m->oc.x, 2) + 2.0 * d.x
		* m->oc.x * m->oc.y + 3.0 * d.y * pow(m->oc.y, 2) - 2.0 * d.z
		* pow(m->oc.y, 2) - 4.0 * d.x * m->oc.x * m->oc.z - 4.0 * d.y
		* m->oc.y * m->oc.z + 2.0 * d.z * m->oc.y * m->oc.z + d.y
		* pow(m->oc.z, 2) - 2.0 * d.z * m->oc.x * fgr->rad - 2.0 * d.x
		* m->oc.z * fgr->rad - d.y * fgr->r_r;
	m->a3 = 2.0 * d.x * d.y * m->oc.x - 4.0 * d.x * d.z * m->oc.x + pow(d.x, 2)
		* m->oc.y + 3.0 * pow(d.y, 2) * m->oc.y - 4.0 * d.y * d.z * m->oc.y
		+ pow(d.z, 2) * m->oc.y - 2.0 * pow(d.x, 2) * m->oc.z - 2.0
		* pow(d.y, 2) * m->oc.z + 2.0 * d.y * d.z * m->oc.z - 2.0 * d.x
		* d.z * fgr->rad;
	m->a4 = pow(d.x, 2) * d.y + pow(d.y, 3) - 2.0 * pow(d.x, 2) * d.z - 2.0
		* pow(d.y, 2) * d.z + d.y * pow(d.z, 2);
	m->a3 /= m->a4;
	m->a2 /= m->a4;
	m->a1 /= m->a4;
}

t_t		tracer_mebius(t_vek o, t_vek d, t_figur *fgr)
{
	t_mebius	m;
	t_figur		sp;
	t_t			sp_t;

	sp = *fgr;
	sp.rad = fgr->rad + fgr->rad1;
	sp.r_r = pow(sp.rad, 2);
	sp_t = tracer_sphere(o, d, &sp);
	if (sp_t.t1 == -1.0 && sp_t.t2 == -1.0)
		return (sp_t);
	m.oc = vek_sub(o, fgr->centr);
	m.n_roots = 0;
	mebius_helper(&m, fgr, d);
	m.n_roots = resolventa(m.roots, m.a3, m.a2, m.a1);
	m.res = INFINITY;
	m.i = -1;
	while (++m.i < m.n_roots)
		if (m.roots[m.i] > 1.0 && m.roots[m.i] < m.res &&
			in_meb(vek_sum(o, vek_num(d, m.roots[m.i])), fgr))
			m.res = m.roots[m.i];
	return ((t_t){m.res, INFINITY});
}
