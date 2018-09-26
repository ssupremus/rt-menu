/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:52:35 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/26 14:38:11 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	m_initializer(t_menu *m)
{
	if (TTF_Init() < 0)
	{
		error(SDL_GetError());
		return ;
	}
	m->w = SDL_CreateWindow("RT - Menu", 10, 0, MWIDTH, MHEIGHT,
		SDL_WINDOW_SHOWN);
	m->r = SDL_CreateRenderer(m->w, -1, SDL_RENDERER_ACCELERATED);
	m->wid = SDL_GetWindowID(m->w);
	m->quit = 0;
	m->sw = -1;
	m_loadtexts(m);
	m_img_read(m);
	m->backgrnd.tex = SDL_CreateTextureFromSurface(m->r, m->backgrnd.s);
	m->backgrnd.rect.x = 0;
	m->backgrnd.rect.y = 0;
	m->backgrnd.rect.w = MWIDTH;
	m->backgrnd.rect.h = MHEIGHT;
	fields(m);
	ft_sw(m);
	m->ph.tex = SDL_CreateTextureFromSurface(m->r, m->ph.sf);
	m->ph.rect.x = 220;
	m->ph.rect.y = 382;
	m->ph.rect.w = 50;
	m->ph.rect.h = 25;
}

void	m_destructor(t_menu *m)
{
	int i;

	TTF_CloseFont(m->txt.font);
	SDL_DestroyTexture(m->backgrnd.tex);
	i = -1;
	while (++i < 22)
	{
		SDL_DestroyTexture(m->txt.tex[i]);
		SDL_FreeSurface(m->txt.s[i]);
	}
	SDL_DestroyTexture(m->ph.tex);
	SDL_FreeSurface(m->ph.sf);
	SDL_FreeSurface(m->slct.s);
	SDL_DestroyTexture(m->slct.tex);
	SDL_DestroyTexture(m->f.tex);
	SDL_FreeSurface(m->f.s);
	SDL_FreeSurface(m->backgrnd.s);
	SDL_DestroyRenderer(m->r);
	SDL_DestroyWindow(m->w);
	TTF_Quit();
}

void	ft_init1(t_r *rtv, t_menu *m)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		return ;
	}
	rtv->win = SDL_CreateWindow("RT", 410, 0, rtv->w, rtv->h,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (!rtv->win)
	{
		error(SDL_GetError());
		SDL_Quit();
		return ;
	}
	rtv->ren = SDL_CreateRenderer(rtv->win, -1, SDL_RENDERER_ACCELERATED);
	m_initializer(m);
}

void	ft_init(t_r *rtv, t_menu *m)
{
	rtv->w = 800;
	rtv->h = 800;
	rtv->w1 = rtv->w / 2;
	rtv->h1 = rtv->h / 2;
	rtv->depth = 1;
	rtv->step = 1;
	rtv->col_efekt = NON;
	rtv->rama.w = 1.0;
	rtv->rama.h = 1.0;
	rtv->rama.d = 1.0;
	rtv->min_cl = 1.0;
	rtv->max_cl = 4000;
	rtv->min_sd = 0.0000001;
	rtv->max_sd = 1.0;
	rtv->count_texture = 0;
	rtv->img_background = 0;
	rtv->jpg_4 = NULL;
	rtv->jpg_3 = NULL;
	rtv->jpg_u = NULL;
	ft_init1(rtv, m);
}
