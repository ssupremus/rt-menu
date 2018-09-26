/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fig_help_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:28:44 by ylesik            #+#    #+#             */
/*   Updated: 2018/09/26 14:55:37 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	parabol_parse_help(int *i, t_r *rtv, int f_c)
{
	if (ft_strstr(rtv->list[*i], "<coef>") != 0)
		rtv->fgr[f_c].rad = p_atof(rtv->list[(*i)++]);
	dop_init_parabol(&rtv->fgr[f_c].rad);
	if (ft_strstr(rtv->list[*i], "<Specular>") != 0)
		rtv->fgr[f_c].mater = p_atoi(rtv->list[(*i)++]);
	if (ft_strstr(rtv->list[*i], "<Transparency>") != 0)
		rtv->fgr[f_c].trans = p_atof(rtv->list[(*i)++]);
	if (ft_strstr(rtv->list[*i], "<Reflect>") != 0)
		rtv->fgr[f_c].reflect = p_atof(rtv->list[(*i)++]);
}

void	parabol_parse(int i, t_r *rtv, int f_c)
{
	if (pars_fig_close(rtv, i, "<Parabol>", "</Parabol>") == 1 &&
		f_c < rtv->count_fgr)
	{
		rtv->fgr[f_c].name = PARABOL;
		while ((ft_strstr(rtv->list[i++], "</Parabol>") == 0) &&
			rtv->list[i] != NULL)
		{
			parabol_parse_help(&i, rtv, f_c);
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
