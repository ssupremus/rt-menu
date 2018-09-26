/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:40:29 by ylesik            #+#    #+#             */
/*   Updated: 2018/09/25 21:09:52 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	draw_scene_space(t_r *rtv)
{
	SDL_Surface *bmp_background;

	rtv->jpg_4 = IMG_Load("res/4.jpg");
	rtv->jpg_3 = IMG_Load("res/ds2.jpg");
	rtv->jpg_u = IMG_Load("res/yupiter.jpg");
	bmp_background = IMG_Load("res/space_fon.jpg");
	if (!bmp_background || !rtv->jpg_4 || !rtv->jpg_3 || !rtv->jpg_u)
		error1("texture not found!", rtv);
	rtv->surf_h[0] = rtv->jpg_4->h;
	rtv->surf_w[0] = rtv->jpg_4->w;
	rtv->surf_h[1] = rtv->jpg_3->h;
	rtv->surf_w[1] = rtv->jpg_3->w;
	rtv->surf_h[2] = rtv->jpg_u->h;
	rtv->surf_w[2] = rtv->jpg_u->w;
	rtv->background = SDL_CreateTextureFromSurface(rtv->ren, bmp_background);
	SDL_FreeSurface(bmp_background);
	SDL_RenderCopy(rtv->ren, rtv->background, NULL, NULL);
}

void	draw_scene_space2(t_r *rtv)
{
	SDL_Surface *bmp_background;

	rtv->jpg_4 = IMG_Load("res/4.jpg");
	rtv->jpg_3 = IMG_Load("res/1.bmp");
	rtv->jpg_u = IMG_Load("res/U_U.jpg");
	bmp_background = IMG_Load("res/space_fon.jpg");
	if (!bmp_background || !rtv->jpg_4 || !rtv->jpg_3 || !rtv->jpg_u)
		error1("texture not found!", rtv);
	rtv->surf_h[0] = rtv->jpg_4->h;
	rtv->surf_w[0] = rtv->jpg_4->w;
	rtv->surf_h[1] = rtv->jpg_3->h;
	rtv->surf_w[1] = rtv->jpg_3->w;
	rtv->surf_h[2] = rtv->jpg_u->h;
	rtv->surf_w[2] = rtv->jpg_u->w;
	rtv->background = SDL_CreateTextureFromSurface(rtv->ren, bmp_background);
	SDL_FreeSurface(bmp_background);
	SDL_RenderCopy(rtv->ren, rtv->background, NULL, NULL);
}

void	draw_scene_box(t_r *rtv)
{
	SDL_Surface *bmp_background;

	rtv->jpg_4 = IMG_Load("res/Bricks1.jpg");
	rtv->jpg_3 = IMG_Load("res/lise3.jpg");
	rtv->jpg_u = IMG_Load("res/U_U.jpg");
	bmp_background = IMG_Load("res/space_fon.jpg");
	if (!bmp_background || !rtv->jpg_4 || !rtv->jpg_3 || !rtv->jpg_u)
		error1("texture not found!", rtv);
	rtv->surf_h[0] = rtv->jpg_4->h;
	rtv->surf_w[0] = rtv->jpg_4->w;
	rtv->surf_h[1] = rtv->jpg_3->h;
	rtv->surf_w[1] = rtv->jpg_3->w;
	rtv->surf_h[2] = rtv->jpg_u->h;
	rtv->surf_w[2] = rtv->jpg_u->w;
	rtv->background = SDL_CreateTextureFromSurface(rtv->ren, bmp_background);
	SDL_FreeSurface(bmp_background);
	SDL_RenderCopy(rtv->ren, rtv->background, NULL, NULL);
}

void	texture_draw_standart(t_r *rtv)
{
	SDL_Surface *bmp_background;

	rtv->jpg_4 = IMG_Load("res/4.jpg");
	rtv->jpg_3 = IMG_Load("res/1.bmp");
	rtv->jpg_u = IMG_Load("res/U_U.jpg");
	bmp_background = IMG_Load("res/5_2.jpg");
	if (!bmp_background || !rtv->jpg_4 || !rtv->jpg_3 || !rtv->jpg_u)
		error1("texture not found!", rtv);
	rtv->surf_h[0] = rtv->jpg_4->h;
	rtv->surf_w[0] = rtv->jpg_4->w;
	rtv->surf_h[1] = rtv->jpg_3->h;
	rtv->surf_w[1] = rtv->jpg_3->w;
	rtv->surf_h[2] = rtv->jpg_u->h;
	rtv->surf_w[2] = rtv->jpg_u->w;
	rtv->background = SDL_CreateTextureFromSurface(rtv->ren, bmp_background);
	SDL_FreeSurface(bmp_background);
	SDL_RenderCopy(rtv->ren, rtv->background, NULL, NULL);
}

void	texture_draw(t_r *rtv)
{
	destroy_texture(rtv);
	if (rtv->img_background == 1)
		draw_scene_space(rtv);
	else if (rtv->img_background == 2)
		draw_scene_box(rtv);
	else if (rtv->img_background == 3)
		draw_scene_space2(rtv);
	else
		texture_draw_standart(rtv);
}
