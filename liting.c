/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:44:50 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/26 15:41:36 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	liting1(double *inten, double intence, double mat, t_vek *n_v_l)
{
	double	n_dot_l;
	double	r_dot_v;
	t_vek	r;

	n_dot_l = vek_skal(n_v_l[0], n_v_l[2]);
	if (n_dot_l > 0)
		*inten += intence * n_dot_l / (vek_len(n_v_l[0]) *
				vek_len(n_v_l[2]));
	if (mat >= 0)
	{
		r = vek_sub(vek_num(vek_num(n_v_l[0],
			vek_skal(n_v_l[0], n_v_l[2])), 2), n_v_l[2]);
		r_dot_v = vek_skal(r, n_v_l[1]);
		if (r_dot_v > 0)
			*inten += intence * pow(r_dot_v /
				(vek_len(r) * vek_len(n_v_l[1])), mat);
	}
}

int		liting3(t_r *rtv, t_liting *li, t_tracer *tr, t_lit *lit)
{
	double	fi;
	t_vek	cam;

	fi = vek_skal(vek_norm(tr->cam_dir), vek_norm(lit->direct));
	cam = vek_sub(lit->pos, rtv->pos);
	li->theta = vek_skal(vek_norm(cam), vek_num(lit->direct, -1));
	if (fi < 0 && li->theta > lit->radiance)
	{
		li->inten = -100;
		return (0);
	}
	li->theta = vek_skal(vek_norm(li->n_v_l[2]), vek_num(lit->direct, -1));
	if (li->theta > lit->radiance)
	{
		if ((li->sf = closest_sd(rtv, tr->p, &li->n_v_l[2], li->min_max_sd)) &&
			li->sf->trans < 1)
			return (1);
		else
			liting1(&li->inten, lit->intence, li->mat, li->n_v_l);
	}
	return (0);
}

int		liting2(t_r *rtv, t_liting *li, t_tracer *tr, t_lit *lit)
{
	if (lit->type == PNT || lit->type == DIR)
		li->n_v_l[2] = vek_sub(lit->pos, tr->p);
	else if (lit->type == PAR)
		li->n_v_l[2] = lit->direct;
	if (lit->type != DIR)
	{
		if ((li->sf = closest_sd(rtv, tr->p, &li->n_v_l[2], li->min_max_sd)) &&
			li->sf->trans < 1)
			return (1);
		else
			liting1(&li->inten, lit->intence, li->mat, li->n_v_l);
	}
	else if (lit->type == DIR)
		return (liting3(rtv, li, tr, lit));
	return (0);
}

double	liting(t_r *rtv, t_tracer *tr, double mat, t_vek d)
{
	int			i;
	t_liting	li;

	i = -1;
	li.inten = 0.0;
	li.mat = mat;
	li.sf = NULL;
	li.min_max_sd = (t_t){rtv->min_sd, rtv->max_sd};
	li.n_v_l[0] = tr->n_v[0];
	li.n_v_l[1] = tr->n_v[1];
	tr->cam_dir = d;
	while (++i < NUM_LIT)
	{
		if (rtv->lit[i].type == AMB)
			li.inten += rtv->lit[i].intence;
		else if (rtv->lit[i].type == PNT || rtv->lit[i].type == DIR ||
				rtv->lit[i].type == PAR)
			if (liting2(rtv, &li, tr, &rtv->lit[i]) == 1)
				continue ;
	}
	return (li.inten);
}
