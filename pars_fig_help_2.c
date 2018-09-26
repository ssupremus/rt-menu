/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fig_help_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:00:26 by ylesik            #+#    #+#             */
/*   Updated: 2018/09/26 14:55:25 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	fgr_help_cut_min_max(int *i, t_r *rtv, int f_c, int n)
{
	rtv->fgr[f_c].min_fgr[n] = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].max_fgr[n] = p_atof(rtv->list[++(*i)]);
}

void	fgr_help_real_cut_min_max(int *i, t_r *rtv, int f_c)
{
	rtv->fgr[f_c].min_real = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].max_real = p_atof(rtv->list[++(*i)]);
}

void	torus_parse(int i, t_r *rtv, int f_c)
{
	if (pars_fig_close(rtv, i, "<Torus>", "</Torus>") == 1 &&
		f_c < rtv->count_fgr && (rtv->fgr[f_c].name = TORUS))
	{
		while ((ft_strstr(rtv->list[i++], "</Torus>") == 0) &&
			rtv->list[i] != NULL)
		{
			if (ft_strstr(rtv->list[i], "<r>") != 0)
				rtv->fgr[f_c].rad = p_atof(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<R>") != 0)
				rtv->fgr[f_c].rad1 = p_atof(rtv->list[i++]);
			dop_init_torus(&rtv->fgr[f_c].rad, &rtv->fgr[f_c].rad1);
			if (ft_strstr(rtv->list[i], "<Specular>") != 0)
				rtv->fgr[f_c].mater = p_atoi(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<Transparency>") != 0)
				rtv->fgr[f_c].trans = p_atof(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<Reflect>") != 0)
				rtv->fgr[f_c].reflect = p_atof(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<Direct>") != 0)
				fgr_help_dir(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Centr>") != 0)
				fgr_help_centr(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<RGBA>") != 0)
				fgr_help_rgba(&i, rtv, f_c);
		}
	}
}

void	mebius_parse(int i, t_r *rtv, int f_c)
{
	if (pars_fig_close(rtv, i, "<Mebius>", "</Mebius>") == 1 &&
		f_c < rtv->count_fgr && (rtv->fgr[f_c].name = MEBIUS))
	{
		while ((ft_strstr(rtv->list[i++], "</Mebius>") == 0) &&
			rtv->list[i] != NULL)
		{
			if (ft_strstr(rtv->list[i], "<r>") != 0)
				rtv->fgr[f_c].rad1 = p_atof(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<R>") != 0)
				rtv->fgr[f_c].rad = p_atof(rtv->list[i++]);
			dop_init_mebius(&rtv->fgr[f_c].rad1, &rtv->fgr[f_c].rad);
			if (ft_strstr(rtv->list[i], "<Specular>") != 0)
				rtv->fgr[f_c].mater = p_atoi(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<Transparency>") != 0)
				rtv->fgr[f_c].trans = p_atof(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<Reflect>") != 0)
				rtv->fgr[f_c].reflect = p_atof(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<Direct>") != 0)
				fgr_help_dir(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Centr>") != 0)
				fgr_help_centr(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<RGBA>") != 0)
				fgr_help_rgba(&i, rtv, f_c);
		}
	}
}
