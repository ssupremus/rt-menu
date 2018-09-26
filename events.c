/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 17:08:30 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 21:38:10 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	screen(t_r *rtv)
{
	SDL_Surface	*surface;

	draw(rtv);
	surface = SDL_CreateRGBSurface(0, rtv->w, rtv->h, 32, 0, 0, 0, 0);
	if (surface == NULL)
		return (error3(SDL_GetError(), &surface));
	if (SDL_RenderReadPixels(rtv->ren, NULL, surface->format->format,
			surface->pixels, surface->pitch) != 0)
		return (error3(SDL_GetError(), &surface));
	if (SDL_SaveBMP(surface, "screen.bmp") != 0)
		return (error3(SDL_GetError(), &surface));
	SDL_FreeSurface(surface);
	return ;
}

void	efects(t_r *rtv, int *i)
{
	rtv->col_efekt = *i;
	*i += 1;
	if (*i > 12)
		*i = 0;
	draw(rtv);
}

void	pixels(t_r *rtv, int *j)
{
	(*j)++;
	if (*j > 1)
		*j = 0;
	if (*j == 1)
	{
		rtv->step = 7;
		draw(rtv);
	}
	else if (*j == 0)
	{
		rtv->step = 1;
		draw(rtv);
	}
}

void	ft_events(t_r *rtv, t_menu *m)
{
	int			k;

	m->keystate = SDL_GetKeyboardState(NULL);
	while (!m->keystate[SDL_SCANCODE_ESCAPE] &&
		m->e.window.event != SDL_WINDOWEVENT_CLOSE)
	{
		if (SDL_WaitEvent(&m->e) && m->e.window.windowID == m->wid)
			m_event_listener(m, rtv);
		SDL_RenderClear(m->r);
		SDL_RenderCopy(m->r, m->backgrnd.tex, NULL, &m->backgrnd.rect);
		k = -1;
		while (++k < 16)
			SDL_RenderCopy(m->r, m->f.tex, NULL, &m->f.rect[k]);
		k = -1;
		while (++k < 22)
			SDL_RenderCopy(m->r, m->txt.tex[k], NULL, &m->txt.rect[k]);
		SDL_RenderCopy(m->r, m->ph.tex, NULL, &m->ph.rect);
		if (m->sw >= 0)
			SDL_RenderCopy(m->r, m->slct.tex, NULL, &m->slct.rect[m->sw]);
		SDL_RenderPresent(m->r);
	}
	m_destructor(m);
}
