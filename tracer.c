/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 22:53:28 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/25 14:47:41 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	trace_helper1(t_r *rtv, t_draw *dr, t_tracer *tr, t_vek d)
{
	tr->c = get_pixel_int(surface_find(dr->sf, rtv), tr->p, rtv, dr->sf);
	tr->col = color(tr->c, liting(rtv, tr, dr->sf->mater, d));
}

void	trace_helper2(t_r *rtv, t_draw *dr, t_tracer *tr, t_vek d)
{
	if (rtv->col_efekt == DISRUP1)
		tr->col = color(color(dr->sf->color, liting(rtv, tr,
			dr->sf->mater, d)), sin(10 * (tr->p.x * tr->p.x + tr->p.y
			* tr->p.y)) * 2);
	else if (rtv->col_efekt == DISRUP2)
		tr->col = color(color(dr->sf->color, liting(rtv, tr,
			dr->sf->mater, d)), sin(5 * tr->p.x) * cos(5 * tr->p.y) * 30);
	else if (rtv->col_efekt == DISRUP3)
		tr->col = color(color(dr->sf->color, liting(rtv, tr,
			dr->sf->mater, d)), sin(tr->p.y));
	else
		tr->col = color(dr->sf->color, liting(rtv, tr,
			dr->sf->mater, d));
}

void	help_helper(t_r *rtv, t_draw *dr, t_tracer *tr, t_vek *d)
{
	tr->fac = vek_skal(vek_num(d[0], -1), tr->n_v[0]);
	tr->fres = mix(pow(1.0 - tr->fac, 3), 1.0, 0.1);
	tr->ior = 1.1;
	tr->eta = (tr->inside) ? tr->ior : 1 / tr->ior;
	tr->cosi = vek_skal(vek_num(tr->n_v[0], -1), d[0]);
	tr->k = 1 - tr->eta * tr->eta * (1 - tr->cosi * tr->cosi);
	tr->refract = vek_norm(vek_sum(vek_num(d[0], tr->eta), vek_num(tr->n_v[0],
		tr->eta * tr->cosi - sqrt(tr->k))));
	tr->refract_col = tracer(rtv, &(t_draw){vek_sub(tr->p, vek_num(tr->n_v[0],
		1e-4)), dr->sf, dr->depth - 1, dr->min_max}, &tr->refract);
	tr->color_na_ekran = color_sum(color_sum(color(tr->col, (1.0
		- dr->sf->reflect) * (1.0 - dr->sf->trans)), color(tr->ref_col,
		dr->sf->reflect)), color(tr->refract_col, (1.0 - tr->fres)
		* dr->sf->trans));
}

void	trace_helper3(t_r *rtv, t_draw *dr, t_tracer *tr, t_vek *d)
{
	dr->min_max = (t_t){rtv->min_sd, rtv->max_cl};
	tr->r = reflect(vek_num(d[0], -1.0), tr->n_v[0]);
	tr->ref_col = tracer(rtv, &(t_draw){tr->p, dr->sf, dr->depth - 1,
		dr->min_max}, &tr->r);
	if (dr->sf->trans <= 0)
		tr->color_na_ekran = color_sum(color(tr->col, 1.0 - dr->sf->reflect),
			color(tr->ref_col, dr->sf->reflect));
	if (dr->sf->trans > 0)
	{
		tr->refract_col = (t_color){0, 0, 0, 255};
		if (vek_skal(d[0], tr->n_v[0]) > 0)
		{
			tr->n_v[0] = vek_num(tr->n_v[0], -1);
			tr->inside = 1;
		}
		help_helper(rtv, dr, tr, d);
	}
}

t_color	tracer(t_r *rtv, t_draw *dr, t_vek *d)
{
	t_tracer	tr;

	tr.t_max = 0;
	tr.inside = 0;
	tr.inten = liting(rtv, &tr, 0, d[0]);
	if (tr.inten == -100)
		return ((t_color){255, 255, 255, 250});
	dr->sf = closest(rtv, dr, &d[0], &tr.t_max);
	if (dr->sf == NULL)
		return ((t_color){0, 0, 0, 254});
	if (dr->sf->name == MEBIUS)
		tr.p = vek_sum(vek_sub(dr->o, dr->sf->dir), vek_num(d[0], tr.t_max));
	else
		tr.p = vek_sum(dr->o, vek_num(d[0], tr.t_max));
	tr.n_v[0] = get_normal(&tr, dr, d[0]);
	tr.n_v[1] = vek_num(d[0], -1);
	if (dr->sf->txtr > 0)
		trace_helper1(rtv, dr, &tr, d[0]);
	else
		trace_helper2(rtv, dr, &tr, d[0]);
	if (dr->depth <= 0 || (dr->sf->reflect <= 0 && dr->sf->trans <= 0))
		return (tr.col);
	else
		trace_helper3(rtv, dr, &tr, d);
	return (tr.color_na_ekran);
}
