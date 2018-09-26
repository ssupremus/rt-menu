/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 12:59:14 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/25 21:09:53 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	pars_fig_options(t_r *rtv, int i, int count_fig, int count_light)
{
	while (rtv->list[++i] != NULL)
	{
		helper(rtv->list[i], rtv);
		if (ft_strstr(rtv->list[i], "<Sphere>") != 0)
			sph_parse(i, rtv, ++count_fig - 1);
		if (ft_strstr(rtv->list[i], "<Cylinder>") != 0)
			cyl_parse(i, rtv, ++count_fig - 1);
		if (ft_strstr(rtv->list[i], "<Cone>") != 0)
			con_parse(i, rtv, ++count_fig - 1);
		if (ft_strstr(rtv->list[i], "<Plane>") != 0)
			plane_parse(i, rtv, ++count_fig - 1);
		if (ft_strstr(rtv->list[i], "<Parabol>") != 0)
			parabol_parse(i, rtv, ++count_fig - 1);
		if (ft_strstr(rtv->list[i], "<Mebius>") != 0)
			mebius_parse(i, rtv, ++count_fig - 1);
		if (ft_strstr(rtv->list[i], "<Torus>") != 0)
			torus_parse(i, rtv, ++count_fig - 1);
		if (ft_strstr(rtv->list[i], "<Light>") != 0)
			ligth_parse(i, rtv, ++count_light - 1);
		if (ft_strstr(rtv->list[i], "<Cam>") != 0)
			cam_parse(i, rtv);
	}
}

void	pars_fig(t_r *rtv)
{
	int i;
	int count_light;
	int count_fig;

	i = -1;
	count_fig = 0;
	count_light = 0;
	pars_fig_options(rtv, i, count_fig, count_light);
}

void	init_helper1(t_figur *fgr)
{
	fgr->name = 0;
	fgr->txtr = 0;
	fgr->mater = 0;
	fgr->rad = 0.0;
	fgr->rad1 = 0.0;
	fgr->reflect = 0.0;
	fgr->trans = 0.0;
	fgr->centr.x = 0.0;
	fgr->centr.y = 0.0;
	fgr->centr.z = 0.0;
	fgr->direct.x = 0.0;
	fgr->direct.y = 0.0;
	fgr->direct.z = 0.0;
	fgr->cut_f[0].x = 0.0;
	fgr->cut_f[0].y = 0.0;
	fgr->cut_f[0].z = 0.0;
}

void	init_helper2(t_figur *fgr)
{
	fgr->cut_f[1].x = 0.0;
	fgr->cut_f[1].y = 0.0;
	fgr->cut_f[1].z = 0.0;
	fgr->cut_f[2].x = 0.0;
	fgr->cut_f[2].y = 0.0;
	fgr->cut_f[2].z = 0.0;
	fgr->max_fgr[0] = INFINITY;
	fgr->min_fgr[0] = -INFINITY;
	fgr->max_fgr[1] = INFINITY;
	fgr->min_fgr[1] = -INFINITY;
	fgr->max_fgr[2] = INFINITY;
	fgr->min_fgr[2] = -INFINITY;
	fgr->cut_real.x = 0.0;
	fgr->cut_real.y = 0.0;
	fgr->cut_real.z = 0.0;
	fgr->max_real = INFINITY;
	fgr->min_real = -INFINITY;
	fgr->color.r = 0;
	fgr->color.g = 0;
	fgr->color.b = 0;
}

void	init_figur(t_r *rtv)
{
	int		i;

	rtv->fgr = (t_figur *)malloc(sizeof(t_figur) * NUM_FIG);
	i = -1;
	while (++i < NUM_FIG)
	{
		init_helper1(&rtv->fgr[i]);
		init_helper2(&rtv->fgr[i]);
	}
	pars_fig(rtv);
}
