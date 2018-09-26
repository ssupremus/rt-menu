/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:45:46 by ysushkov          #+#    #+#             */
/*   Updated: 2018/09/25 16:46:00 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

t_vek		get_x_axe(t_vek dir)
{
	t_vek x_axe;

	x_axe = vek_norm(vek_cross(vek_new(0., 1., 0.), dir));
	if (vek_len(x_axe) == 0.0)
		x_axe = vek_norm(vek_cross(vek_new(1., 0., 0.), dir));
	return (x_axe);
}

void		get_local_coords(t_vek hit, t_vek *coord, t_vek orig, t_vek dir)
{
	t_vek x_axe;
	t_vek y_axe;

	hit = vek_sub(orig, hit);
	coord->z = vek_skal(hit, dir);
	x_axe = get_x_axe(dir);
	hit = vek_sub(hit, vek_num(dir, coord->z));
	y_axe = vek_cross(x_axe, dir);
	coord->x = vek_skal(hit, x_axe);
	coord->y = vek_skal(hit, y_axe);
}

int			*maping(t_vek d, t_r *rtv, t_figur *sf)
{
	int		wh[2];
	double	*uv;
	int		*xy;

	uv = NULL;
	xy = malloc(sizeof(int) * 2);
	maping_help(sf, rtv, wh);
	if (sf->name == SPHERE)
		uv = sph_mapping(d);
	else if (sf->name == PLANE)
		uv = plane_mapping(d, sf);
	else if (sf->name == CYLINDER)
		uv = cyl_mapping(d, sf);
	else if (sf->name == CONE)
		uv = con_mapping(d, sf);
	xy[0] = fix_xy(uv[0] * wh[0], 0, wh[0]);
	xy[1] = fix_xy(uv[1] * wh[1], 0, wh[1]);
	free(uv);
	return (xy);
}

t_color		get_pixel_int(SDL_Surface *surface, t_vek p, t_r *rtv, t_figur *sf)
{
	unsigned int	*pixels;
	t_color			rgb;
	int				*xy;
	t_vek			d;

	d = (t_vek){0, 0, 0};
	if (sf->name == SPHERE)
		d = vek_norm(vek_sub(p, sf->centr));
	else if (sf->name == CONE)
		d = vek_sub(p, vek_mult(sf->centr, sf->dir));
	else if (sf->name == PLANE)
		d = vek_sub(p, sf->centr);
	else if (sf->name == CYLINDER)
		d = vek_sub(p, vek_mult(sf->centr, sf->dir));
	pixels = (unsigned int *)surface->pixels;
	xy = maping(d, rtv, sf);
	xy[0] = fix_xy(xy[0] + rtv->pos.x * 10, 0, surface->w);
	xy[1] = fix_xy(xy[1] + rtv->pos.y * 10, 0, surface->h);
	rgb = put_pxl(pixels[(xy[1] * surface->w) + xy[0]]);
	free(xy);
	return (rgb);
}
