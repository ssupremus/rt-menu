/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:35:35 by ylesik            #+#    #+#             */
/*   Updated: 2018/09/25 17:00:57 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

double		*plane_mapping(t_vek d, t_figur *sf)
{
	double	*uv;
	t_vek	u_axis;
	t_vek	v_axis;

	u_axis = (t_vek){sf->dir.y, sf->dir.z, -sf->dir.x};
	v_axis = vek_cross(u_axis, sf->dir);
	uv = malloc(sizeof(double) * 2);
	uv[0] = vek_skal(d, u_axis) * 0.05;
	uv[1] = vek_skal(d, v_axis) * 0.05;
	uv[0] = uv[0] - floor(uv[0]);
	uv[1] = uv[1] - floor(uv[1]);
	return (uv);
}

double		*sph_mapping(t_vek d)
{
	double *uv;

	uv = malloc(sizeof(double) * 2);
	uv[0] = (0.5 + atan2(d.z, d.x) / (2 * M_PI));
	uv[1] = (0.5 - (asin(d.y) / M_PI));
	return (uv);
}

double		*con_mapping(t_vek d, t_figur *sf)
{
	double	*uv;
	t_vek	coord;

	uv = malloc(sizeof(double) * 2);
	get_local_coords(d, &coord, sf->centr, sf->dir);
	uv[0] = atan2(coord.y, coord.x) / (M_PI * 2);
	uv[1] = coord.z / sf->max_fgr[0] + sf->min_fgr[0];
	uv[1] = uv[1] - floor(uv[1]);
	return (uv);
}

double		*cyl_mapping(t_vek d, t_figur *sf)
{
	double	*uv;
	t_vek	coord;

	uv = malloc(sizeof(double) * 2);
	get_local_coords(d, &coord, sf->centr, sf->dir);
	uv[0] = atan2(coord.y, coord.x) / (M_PI * 2);
	uv[1] = coord.z / sf->max_fgr[0] + sf->min_fgr[0];
	uv[1] = uv[1] - floor(uv[1]);
	return (uv);
}
