/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:55:26 by ysushkov          #+#    #+#             */
/*   Updated: 2018/09/25 16:55:40 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	init_cam(t_r *rtv)
{
	rtv->pos.x = 0.0;
	rtv->pos.y = 0.0;
	rtv->pos.z = 0.0;
	rtv->a = 0.0;
	rtv->b = 0.0;
	rtv->c = 0.0;
}

void	cam_parse(int i, t_r *rtv)
{
	if (pars_fig_close(rtv, i, "<Cam>", "</Cam>") == 1)
	{
		while (ft_strstr(rtv->list[i++], "</Cam>") == 0)
		{
			if (ft_strstr(rtv->list[i], "<Pos>") != 0)
			{
				rtv->pos.x = p_atof(rtv->list[++i]);
				rtv->pos.y = p_atof(rtv->list[++i]);
				rtv->pos.z = p_atof(rtv->list[++i]);
			}
			if (ft_strstr(rtv->list[i], "<Angle>") != 0)
			{
				rtv->a = p_atof(rtv->list[++i]);
				rtv->b = p_atof(rtv->list[++i]);
				rtv->c = p_atof(rtv->list[++i]);
			}
		}
	}
}
