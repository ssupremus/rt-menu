/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:50:07 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/25 16:50:07 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	help_init_light(t_lit *lit)
{
	if (lit->type < 0 || lit->type > 4)
		lit->type = 0;
	if (lit->intence < 0)
		lit->intence = 0.0;
	if (lit->radiance < 0.1)
		lit->radiance = 0.1;
	else if (lit->radiance > 0.99)
		lit->radiance = 0.99;
}

void	intence_cut(t_r *rtv)
{
	double	intence1;
	int		i;

	intence1 = 0.0;
	i = -1;
	while (++i < NUM_LIT)
		intence1 += rtv->lit[i].intence;
	if (intence1 > 1.0 && (i = -1))
		while (++i < NUM_LIT)
			rtv->lit[i].intence = rtv->lit[i].intence / intence1;
	else
		return ;
}

void	init_light(t_r *rtv)
{
	int		i;

	rtv->lit = (t_lit *)malloc(sizeof(t_lit) * NUM_LIT);
	i = -1;
	while (++i < NUM_LIT)
	{
		rtv->lit[i].type = 0;
		rtv->lit[i].intence = 0.0;
		rtv->lit[i].radiance = 0.0;
		rtv->lit[i].pos.x = 0.0;
		rtv->lit[i].pos.y = 0.0;
		rtv->lit[i].pos.z = 0.0;
		rtv->lit[i].direct.x = 0.0;
		rtv->lit[i].direct.y = 0.0;
		rtv->lit[i].direct.z = 0.0;
	}
}

void	light_parse_loop(int i, t_r *rtv, int c_l)
{
	while (ft_strstr(rtv->list[i++], "</Light>") == 0)
	{
		if (ft_strstr(rtv->list[i], "<Type>") != 0)
			rtv->lit[c_l].type = p_atoi(rtv->list[i++]);
		if (ft_strstr(rtv->list[i], "<Intense>") != 0)
			rtv->lit[c_l].intence = p_atof(rtv->list[i++]);
		if (ft_strstr(rtv->list[i], "<Radianse>") != 0)
			rtv->lit[c_l].radiance = p_atof(rtv->list[i++]);
		help_init_light(&rtv->lit[c_l]);
		if (ft_strstr(rtv->list[i], "<Centr>") != 0)
		{
			rtv->lit[c_l].pos.x = p_atof(rtv->list[++i]);
			rtv->lit[c_l].pos.y = p_atof(rtv->list[++i]);
			rtv->lit[c_l].pos.z = p_atof(rtv->list[++i]);
		}
		if (ft_strstr(rtv->list[i], "<Direct>") != 0)
		{
			rtv->lit[c_l].direct.x = p_atof(rtv->list[++i]);
			rtv->lit[c_l].direct.y = p_atof(rtv->list[++i]);
			rtv->lit[c_l].direct.z = p_atof(rtv->list[++i]);
			rtv->lit[c_l].direct = vek_norm(rtv->lit[c_l].direct);
		}
	}
}

void	ligth_parse(int i, t_r *rtv, int c_l)
{
	if (pars_fig_close(rtv, i, "<Light>", "</Light>") == 1 &&
		c_l < rtv->count_light)
		light_parse_loop(i, rtv, c_l);
}
