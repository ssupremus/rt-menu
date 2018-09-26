/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fig_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:58:49 by ylesik            #+#    #+#             */
/*   Updated: 2018/09/25 20:58:50 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	fgr_help_dir(int *i, t_r *rtv, int f_c)
{
	rtv->fgr[f_c].direct.x = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].direct.y = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].direct.z = p_atof(rtv->list[++(*i)]);
}

void	fgr_help_centr(int *i, t_r *rtv, int f_c)
{
	rtv->fgr[f_c].centr.x = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].centr.y = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].centr.z = p_atof(rtv->list[++(*i)]);
}

void	fgr_help_rgba(int *i, t_r *rtv, int f_c)
{
	rtv->fgr[f_c].color.r = p_atoi(rtv->list[++(*i)]);
	rtv->fgr[f_c].color.g = p_atoi(rtv->list[++(*i)]);
	rtv->fgr[f_c].color.b = p_atoi(rtv->list[++(*i)]);
	rtv->fgr[f_c].color.a = 253;
}

void	fgr_help_cut_f(int *i, t_r *rtv, int f_c, int n)
{
	rtv->fgr[f_c].cut_f[n].x = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].cut_f[n].y = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].cut_f[n].z = p_atof(rtv->list[++(*i)]);
}

void	fgr_help_cut_real(int *i, t_r *rtv, int f_c)
{
	rtv->fgr[f_c].cut_real.x = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].cut_real.y = p_atof(rtv->list[++(*i)]);
	rtv->fgr[f_c].cut_real.z = p_atof(rtv->list[++(*i)]);
}
