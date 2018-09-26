/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_init1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:39:49 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 21:44:44 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	dop_init_trans(double *r)
{
	if (*r > 1)
		*r = 1.0;
	else if (*r < 1)
		*r = 0.0;
}

void	dop_init_reflect(double *r)
{
	if (*r > 1)
		*r = 1.0;
	else if (*r < 0)
		*r = 0.0;
}

void	dop_init_cone(double *r)
{
	if (*r > 1)
		*r = 1.0;
	else if (*r < -1)
		*r = -1.0;
}

void	dop_init_parabol(double *r)
{
	if (*r > 3)
		*r = 3.0;
	else if (*r < 0)
		*r = 0.0;
}

void	dop_init(t_r *rtv)
{
	int		i;

	i = -1;
	while (++i < NUM_FIG)
	{
		rtv->fgr[i].r_r = pow(rtv->fgr[i].rad, 2);
		rtv->fgr[i].r1_r1 = pow(rtv->fgr[i].rad1, 2);
		rtv->fgr[i].dir = vek_norm(rtv->fgr[i].direct);
		if (rtv->fgr[i].name == PLANE)
			if (vek_skal(vek_sub(rtv->pos, rtv->fgr[i].centr),
				rtv->fgr[i].dir) < 0)
				rtv->fgr[i].dir = vek_num(rtv->fgr[i].dir, -1);
		rtv->fgr[i].cut_f[0] = vek_norm(rtv->fgr[i].cut_f[0]);
		rtv->fgr[i].cut_f[1] = vek_norm(rtv->fgr[i].cut_f[1]);
		rtv->fgr[i].cut_f[2] = vek_norm(rtv->fgr[i].cut_f[2]);
		rtv->fgr[i].cut_real = vek_norm(rtv->fgr[i].cut_real);
		dop_init_trans(&(rtv->fgr[i].trans));
		dop_init_reflect(&(rtv->fgr[i].reflect));
		intence_cut(rtv);
	}
}
