/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fig_help_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:09:54 by ylesik            #+#    #+#             */
/*   Updated: 2018/09/26 14:53:25 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	cyl_parse_help(int *i, t_r *rtv, int f_c)
{
	if (ft_strstr(rtv->list[*i], "<r>") != 0)
		rtv->fgr[f_c].rad = p_atof(rtv->list[(*i)++]);
	if (ft_strstr(rtv->list[*i], "<Specular>") != 0)
		rtv->fgr[f_c].mater = p_atof(rtv->list[(*i)++]);
	if (ft_strstr(rtv->list[*i], "<Transparency>") != 0)
		rtv->fgr[f_c].trans = p_atof(rtv->list[(*i)++]);
	if (ft_strstr(rtv->list[*i], "<Texture>") != 0)
	{
		rtv->fgr[f_c].txtr = p_atoi(rtv->list[(*i)++]);
		if (rtv->fgr[f_c].txtr > 0 && rtv->fgr[f_c].txtr < 4)
			rtv->count_texture++;
		else
			rtv->fgr[f_c].txtr = 0;
	}
	if (ft_strstr(rtv->list[*i], "<Reflect>") != 0)
		rtv->fgr[f_c].reflect = p_atof(rtv->list[(*i)++]);
}

void	cyl_parse(int i, t_r *rtv, int f_c)
{
	if (pars_fig_close(rtv, i, "<Cylinder>", "</Cylinder>") == 1 &&
		f_c < rtv->count_fgr)
	{
		rtv->fgr[f_c].name = CYLINDER;
		while ((ft_strstr(rtv->list[i++], "</Cylinder>") == 0) &&
			rtv->list[i] != NULL)
		{
			cyl_parse_help(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Direct>") != 0)
				fgr_help_dir(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Figur_cut>") != 0)
				fgr_help_cut_f(&i, rtv, f_c, 0);
			if (ft_strstr(rtv->list[i], "<Min_max_figur_cut>") != 0)
				fgr_help_cut_min_max(&i, rtv, f_c, 0);
			if (ft_strstr(rtv->list[i], "<Real_cut>") != 0)
				fgr_help_cut_real(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Min_max_real_cut>") != 0)
				fgr_help_real_cut_min_max(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Centr>") != 0)
				fgr_help_centr(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<RGBA>") != 0)
				fgr_help_rgba(&i, rtv, f_c);
		}
	}
}

void	con_parse_help(int *i, t_r *rtv, int f_c)
{
	if (ft_strstr(rtv->list[*i], "<r>") != 0)
		rtv->fgr[f_c].rad = p_atof(rtv->list[(*i)++]);
	dop_init_cone(&rtv->fgr[f_c].rad);
	if (ft_strstr(rtv->list[*i], "<Specular>") != 0)
		rtv->fgr[f_c].mater = p_atof(rtv->list[(*i)++]);
	if (ft_strstr(rtv->list[*i], "<Transparency>") != 0)
		rtv->fgr[f_c].trans = p_atof(rtv->list[(*i)++]);
	if (ft_strstr(rtv->list[*i], "<Texture>") != 0)
	{
		rtv->fgr[f_c].txtr = p_atoi(rtv->list[(*i)++]);
		if (rtv->fgr[f_c].txtr > 0 && rtv->fgr[f_c].txtr < 4)
			rtv->count_texture++;
		else
			rtv->fgr[f_c].txtr = 0;
	}
	if (ft_strstr(rtv->list[*i], "<Reflect>") != 0)
		rtv->fgr[f_c].reflect = p_atof(rtv->list[(*i)++]);
}

void	con_parse(int i, t_r *rtv, int f_c)
{
	if (pars_fig_close(rtv, i, "<Cone>", "</Cone>") == 1 &&
		f_c < rtv->count_fgr)
	{
		rtv->fgr[f_c].name = CONE;
		while ((ft_strstr(rtv->list[i++], "</Cone>") == 0) &&
			rtv->list[i] != NULL)
		{
			con_parse_help(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Direct>") != 0)
				fgr_help_dir(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Figur_cut>") != 0)
				fgr_help_cut_f(&i, rtv, f_c, 0);
			if (ft_strstr(rtv->list[i], "<Min_max_figur_cut>") != 0)
				fgr_help_cut_min_max(&i, rtv, f_c, 0);
			if (ft_strstr(rtv->list[i], "<Real_cut>") != 0)
				fgr_help_cut_real(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Min_max_real_cut>") != 0)
				fgr_help_real_cut_min_max(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<Centr>") != 0)
				fgr_help_centr(&i, rtv, f_c);
			if (ft_strstr(rtv->list[i], "<RGBA>") != 0)
				fgr_help_rgba(&i, rtv, f_c);
		}
	}
}
