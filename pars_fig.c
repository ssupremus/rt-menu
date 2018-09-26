/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:45:05 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/26 14:56:23 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

#define AB if (ft_strstr(rtv->list[i], "<Specular>") != 0)
#define AB_RES rtv->fgr[f_c].mater = p_atoi(rtv->list[i++]);
#define BC if (ft_strstr(rtv->list[i], "<Transparency>") != 0)
#define BC_RES rtv->fgr[f_c].trans = p_atof(rtv->list[i++]);
#define CD if (ft_strstr(rtv->list[i], "<Direct>") != 0)
#define CD_RES fgr_help_dir(&i, rtv, f_c);
#define RES AB AB_RES BC BC_RES CD CD_RES

void	sph_parse_help(int i, t_r *rtv, int f_c)
{
	if (ft_strstr(rtv->list[i], "<Texture>") != 0)
	{
		rtv->fgr[f_c].txtr = p_atoi(rtv->list[i++]);
		if (rtv->fgr[f_c].txtr > 0 && rtv->fgr[f_c].txtr < 4)
			rtv->count_texture++;
		else
			rtv->fgr[f_c].txtr = 0;
	}
	if (ft_strstr(rtv->list[i], "<Reflect>") != 0)
		rtv->fgr[f_c].reflect = p_atof(rtv->list[i++]);
	if (ft_strstr(rtv->list[i], "<Direct>") != 0)
		fgr_help_dir(&i, rtv, f_c);
	if (ft_strstr(rtv->list[i], "<Figur_cut>") != 0)
		fgr_help_cut_f(&i, rtv, f_c, 0);
	if (ft_strstr(rtv->list[i], "<Min_max_figur_cut>") != 0)
		fgr_help_cut_min_max(&i, rtv, f_c, 0);
	if (ft_strstr(rtv->list[i], "<Real_cut>") != 0)
		fgr_help_cut_real(&i, rtv, f_c);
}

void	sph_parse(int i, t_r *rtv, int f_c)
{
	if (pars_fig_close(rtv, i, "<Sphere>", "</Sphere>") == 1 &&
		f_c < rtv->count_fgr && (rtv->fgr[f_c].name = SPHERE))
		while ((ft_strstr(rtv->list[i++], "</Sphere>") == 0) &&
			rtv->list[i] != NULL)
		{
			if (ft_strstr(rtv->list[i], "<r>") != 0)
				rtv->fgr[f_c].rad = p_atof(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<Specular>") != 0)
				rtv->fgr[f_c].mater = p_atoi(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<Transparency>") != 0)
				rtv->fgr[f_c].trans = p_atof(rtv->list[i++]);
			if (ft_strstr(rtv->list[i], "<Texture>") != 0 ||
				ft_strstr(rtv->list[i], "<Reflect>") != 0 ||
				ft_strstr(rtv->list[i], "<Direct>") != 0 ||
				ft_strstr(rtv->list[i], "<Figur_cut>") != 0 ||
				ft_strstr(rtv->list[i], "<Min_max_figur_cut>") != 0 ||
				ft_strstr(rtv->list[i], "<Real_cut>") != 0)
				sph_parse_help(i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Min_max_real_cut>") != 0)
				fgr_help_real_cut_min_max(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Centr>") != 0)
				fgr_help_centr(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<RGBA>") != 0)
				fgr_help_rgba(&i, rtv, f_c);
		}
}

void	plane_parse_help_2(int i, t_r *rtv, int f_c)
{
	if (ft_strstr(rtv->list[i], "<Texture>") != 0)
	{
		rtv->fgr[f_c].txtr = p_atoi(rtv->list[i++]);
		if (rtv->fgr[f_c].txtr > 0 && rtv->fgr[f_c].txtr < 4)
			rtv->count_texture++;
		else
			rtv->fgr[f_c].txtr = 0;
	}
	if (ft_strstr(rtv->list[i], "<Reflect>") != 0)
		rtv->fgr[f_c].reflect = p_atof(rtv->list[i++]);
}

void	plane_parse_help(int i, t_r *rtv, int f_c)
{
	RES;
	if (ft_strstr(rtv->list[i], "<Texture>") != 0 ||
		ft_strstr(rtv->list[i], "<Reflect>") != 0)
		plane_parse_help_2(i, rtv, f_c);
	if (ft_strstr(rtv->list[i], "<Figur_cut_1>") != 0)
		fgr_help_cut_f(&i, rtv, f_c, 0);
	if (ft_strstr(rtv->list[i], "<Figur_cut_2>") != 0)
		fgr_help_cut_f(&i, rtv, f_c, 1);
	if (ft_strstr(rtv->list[i], "<Figur_cut_3>") != 0)
		fgr_help_cut_f(&i, rtv, f_c, 2);
	if (ft_strstr(rtv->list[i], "<Min_max_figur_cut_1>") != 0)
		fgr_help_cut_min_max(&i, rtv, f_c, 0);
	if (ft_strstr(rtv->list[i], "<Min_max_figur_cut_2>") != 0)
		fgr_help_cut_min_max(&i, rtv, f_c, 1);
	if (ft_strstr(rtv->list[i], "<Min_max_figur_cut_3>") != 0)
		fgr_help_cut_min_max(&i, rtv, f_c, 2);
	if (ft_strstr(rtv->list[i], "<Real_cut>") != 0)
		fgr_help_cut_real(&i, rtv, f_c);
	if (ft_strstr(rtv->list[i], "<Min_max_real_cut>") != 0)
		fgr_help_real_cut_min_max(&i, rtv, f_c);
	if (ft_strstr(rtv->list[i], "<Centr>") != 0)
		fgr_help_centr(&i, rtv, f_c);
	if (ft_strstr(rtv->list[i], "<RGBA>") != 0)
		fgr_help_rgba(&i, rtv, f_c);
}

void	plane_parse(int i, t_r *rtv, int f_c)
{
	if (pars_fig_close(rtv, i, "<Plane>", "</Plane>") == 1 &&
		f_c < rtv->count_fgr && (rtv->fgr[f_c].name = PLANE))
	{
		while ((ft_strstr(rtv->list[i++], "</Plane>") == 0) &&
			rtv->list[i] != NULL)
		{
			plane_parse_help(i, rtv, f_c);
		}
	}
}
