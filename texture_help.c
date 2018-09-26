/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:19:50 by ylesik            #+#    #+#             */
/*   Updated: 2018/09/23 13:10:33 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void		destroy_texture(t_r *rtv)
{
	if (rtv->background != NULL)
		SDL_DestroyTexture(rtv->background);
	if (rtv->jpg_4 != NULL)
		SDL_FreeSurface(rtv->jpg_4);
	if (rtv->jpg_3 != NULL)
		SDL_FreeSurface(rtv->jpg_3);
	if (rtv->jpg_u != NULL)
		SDL_FreeSurface(rtv->jpg_u);
}

int			fix_xy(int v, int min, int max)
{
	v > max ? v = max : 0;
	v < min ? v = min : 0;
	return (v);
}

SDL_Surface	*surface_find(t_figur *sf, t_r *rtv)
{
	if (sf->txtr == 1)
		return (rtv->jpg_4);
	else if (sf->txtr == 2)
		return (rtv->jpg_3);
	else if (sf->txtr == 3)
		return (rtv->jpg_u);
	return (rtv->jpg_u);
}

t_color		put_pxl(unsigned int c)
{
	t_color rgb;

	rgb.r = (c >> 16) & 255;
	rgb.g = (c >> 8) & 255;
	rgb.b = c & 255;
	rgb.a = (c >> 24) & 255;
	return (rgb);
}

void		maping_help(t_figur *sf, t_r *rtv, int *wh)
{
	if (sf->txtr == 1)
	{
		wh[0] = rtv->surf_w[0];
		wh[1] = rtv->surf_h[0];
	}
	else if (sf->txtr == 2)
	{
		wh[0] = rtv->surf_w[1];
		wh[1] = rtv->surf_h[1];
	}
	else if (sf->txtr == 3)
	{
		wh[0] = rtv->surf_w[2];
		wh[1] = rtv->surf_h[2];
	}
}
