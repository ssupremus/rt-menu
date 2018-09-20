/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:48:37 by ysushkov          #+#    #+#             */
/*   Updated: 2018/09/20 13:48:41 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

void		fields(t_menu *m)
{
	int i;
	int t;

	m->f.s = IMG_Load("m_images/50.png");
	m->f.tex = SDL_CreateTextureFromSurface(m->r, m->f.s);
	m->f.rect[0].x = 20;
	m->f.rect[0].y = 20;
	m->f.rect[0].w = MWIDTH - 40;
	m->f.rect[0].h = MHEIGHT - 40;
	i = 0;
	t = 60;
	while (++i < 5)
	{
		m->f.rect[i].x = 160;
		m->f.rect[i].y = t;
		m->f.rect[i].w = 85;
		m->f.rect[i].h = 30;
		m->f.rect[i + 4].x = 250;
		m->f.rect[i + 4].y = t;
		m->f.rect[i + 4].w = 85;
		m->f.rect[i + 4].h = 30;
		t = t + 40;
	}
	i = 8;
	t = 220;
	while (++i < 16)
	{
		if (i == 10)
			m->f.rect[i].x = 160;
		else if (i == 11)
		{
			t -= 40;
			m->f.rect[i].x = 250;
		}
		else
			m->f.rect[i].x = 205;
		m->f.rect[i].y = t;
		m->f.rect[i].w = 85;
		m->f.rect[i].h = 30;
		t += 40;	
	}
}

void		ft_sw(t_menu *m)
{
	int i;

	m->slct.s = IMG_Load("m_images/transparent.png");
	m->slct.tex = SDL_CreateTextureFromSurface(m->r, m->slct.s);
	i = -1;
	while (++i < 16)
	{
		m->slct.rect[i].x = m->f.rect[i + 1].x;
		m->slct.rect[i].y = m->f.rect[i + 1].y;
		m->slct.rect[i].w = m->f.rect[i + 1].w;
		m->slct.rect[i].h = m->f.rect[i + 1].h; 
	}
}

void		initializer(t_menu *m)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0)
	{
		write(1, "Error\n", 1);
		exit(1);
	}
	m->w = SDL_CreateWindow("RT - Menu", 0, 0, MWIDTH, MHEIGHT, SDL_WINDOW_SHOWN);
	m->r = SDL_CreateRenderer(m->w, -1, SDL_RENDERER_ACCELERATED);
	m->wid = SDL_GetWindowID(m->w);
	m->quit = 0;
	m->sw = -1;
	m->backgrnd.s = IMG_Load("m_images/blue_rect.png");
	m->backgrnd.tex = SDL_CreateTextureFromSurface(m->r, m->backgrnd.s);
	m_loadtexts(m);
	m->backgrnd.rect.x = 0;
	m->backgrnd.rect.y = 0;
	m->backgrnd.rect.w = MWIDTH;
	m->backgrnd.rect.h = MHEIGHT;
	fields(m);
	ft_sw(m);
}

void		event_listener(t_menu *m)
{
	if (m->e.type == SDL_QUIT)
		m->quit = 1;
	else if (m->e.type == SDL_KEYDOWN && m->e.key.windowID == m->wid)
		menu_keys(m);
	else if (m->e.type == SDL_MOUSEMOTION && m->e.motion.windowID == m->wid)
		menu_motion(m);
	else if (m->e.type == SDL_MOUSEBUTTONUP && m->e.button.windowID == m->wid)
		menu_mouse(m);
}

void		destructor(t_menu *m)
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
	SDL_FreeSurface(m->slct.s);
	SDL_DestroyTexture(m->slct.tex);
	SDL_DestroyTexture(m->f.tex);
	SDL_FreeSurface(m->f.s);
	SDL_FreeSurface(m->backgrnd.s);
	SDL_DestroyRenderer(m->r);
	SDL_DestroyWindow(m->w);
}

void			menu(void)
{
	t_menu	m;
	int		i;

	initializer(&m);
	while (!m.quit && m.e.type != SDL_QUIT)
	{
		if (SDL_WaitEvent(&m.e))
			event_listener(&m);
		SDL_RenderClear(m.r);
		SDL_RenderCopy(m.r, m.backgrnd.tex, NULL, &m.backgrnd.rect);
		i = -1;
		while (++i < 16)
			SDL_RenderCopy(m.r, m.f.tex, NULL, &m.f.rect[i]);
		i = -1;
		while (++i < 22)
			SDL_RenderCopy(m.r, m.txt.tex[i], NULL, &m.txt.rect[i]);
		if (m.sw >= 0)
			SDL_RenderCopy(m.r, m.slct.tex, NULL, &m.slct.rect[m.sw]);
		SDL_RenderPresent(m.r);
	}
	destructor(&m);
	TTF_Quit();
	SDL_Quit();
	system("leaks menu");
}

int		main(void)
{
	menu();
	return (0);
}
