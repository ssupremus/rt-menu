/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_loadtexts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:23:37 by ysushkov          #+#    #+#             */
/*   Updated: 2018/09/25 12:23:40 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

static void		m_text_surf(t_menu *m)
{
	m->txt.s[0] = TTF_RenderText_Solid(m->txt.font, "Rotation:", m->txt.color);
	m->txt.s[1] = TTF_RenderText_Solid(m->txt.font, "X-axis", m->txt.color);
	m->txt.s[2] = TTF_RenderText_Solid(m->txt.font, "Y-axis", m->txt.color);
	m->txt.s[3] = TTF_RenderText_Solid(m->txt.font, "Z-axis", m->txt.color);
	m->txt.s[4] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[5] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[6] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[7] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[8] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[9] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[10] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[11] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[12] = TTF_RenderText_Solid(m->txt.font, "up", m->txt.color);
	m->txt.s[13] = TTF_RenderText_Solid(m->txt.font, "left", m->txt.color);
	m->txt.s[14] = TTF_RenderText_Solid(m->txt.font, "right", m->txt.color);
	m->txt.s[15] = TTF_RenderText_Solid(m->txt.font, "down", m->txt.color);
	m->txt.s[16] = TTF_RenderText_Solid(m->txt.font, "Zoom:", m->txt.color);
	m->txt.s[17] = TTF_RenderText_Solid(m->txt.font, "Move:", m->txt.color);
	m->txt.s[18] = TTF_RenderText_Solid(m->txt.font, "Color gels:",
		m->txt.color);
	m->txt.s[19] = TTF_RenderText_Solid(m->txt.font, "switch", m->txt.color);
	m->txt.s[20] = TTF_RenderText_Solid(m->txt.font, "Screenshot:",
		m->txt.color);
	m->txt.s[21] = TTF_RenderText_Solid(m->txt.font, "Optimization:",
		m->txt.color);
}

static void		m_text_rect1(t_menu *m, int i, int *t)
{
	i = 0;
	*t = 60;
	while (++i < 4)
	{
		m->txt.rect[i].x = 75;
		m->txt.rect[i].y = *t;
		m->txt.rect[i].w = 75;
		m->txt.rect[i].h = 25;
		*t = *t + 40;
	}
	i = 3;
	*t = 60;
	while (++i < 8)
	{
		m->txt.rect[i].x = 190;
		m->txt.rect[i].y = *t;
		m->txt.rect[i].w = 25;
		m->txt.rect[i].h = 25;
		m->txt.rect[i + 4].x = 278;
		m->txt.rect[i + 4].y = *t;
		m->txt.rect[i + 4].w = 25;
		m->txt.rect[i + 4].h = 30;
		*t = *t + 40;
	}
}

static void		m_text_rect2(t_menu *m)
{
	m->txt.rect[12].x = 233;
	m->txt.rect[12].y = 220;
	m->txt.rect[12].w = 30;
	m->txt.rect[12].h = 25;
	m->txt.rect[13].x = 175;
	m->txt.rect[13].y = 266;
	m->txt.rect[13].w = 45;
	m->txt.rect[13].h = 20;
	m->txt.rect[14].x = 265;
	m->txt.rect[14].y = 266;
	m->txt.rect[14].w = 50;
	m->txt.rect[14].h = 20;
	m->txt.rect[15].x = 222;
	m->txt.rect[15].y = 300;
	m->txt.rect[15].w = 50;
	m->txt.rect[15].h = 25;
	m->txt.rect[16].x = 50;
	m->txt.rect[16].y = 180;
	m->txt.rect[16].w = 100;
	m->txt.rect[16].h = 30;
	m->txt.rect[17].x = 50;
	m->txt.rect[17].y = 220;
	m->txt.rect[17].w = 100;
	m->txt.rect[17].h = 30;
}

static void		m_text_rect3(t_menu *m)
{
	m->txt.rect[18].x = 50;
	m->txt.rect[18].y = 340;
	m->txt.rect[18].w = 150;
	m->txt.rect[18].h = 30;
	m->txt.rect[19].x = 220;
	m->txt.rect[19].y = 345;
	m->txt.rect[19].w = 55;
	m->txt.rect[19].h = 20;
	m->txt.rect[20].x = 50;
	m->txt.rect[20].y = 380;
	m->txt.rect[20].w = 150;
	m->txt.rect[20].h = 30;
	m->txt.rect[21].x = 50;
	m->txt.rect[21].y = 420;
	m->txt.rect[21].w = 150;
	m->txt.rect[21].h = 30;
}

void			m_loadtexts(t_menu *m)
{
	int i;
	int t;

	m->txt.font = TTF_OpenFont("m_fonts/opensans.ttf", 50);
	if (m->txt.font == NULL)
	{
		write(1, "Font error\n", 11);
		SDL_DestroyRenderer(m->r);
		SDL_DestroyWindow(m->w);
		exit(1);
	}
	m->txt.color.r = 255;
	m->txt.color.g = 255;
	m->txt.color.b = 255;
	m_text_surf(m);
	i = -1;
	while (++i < 22)
		m->txt.tex[i] = SDL_CreateTextureFromSurface(m->r, m->txt.s[i]);
	m->txt.rect[0].x = 50;
	m->txt.rect[0].y = 30;
	m->txt.rect[0].w = 150;
	m->txt.rect[0].h = 30;
	m_text_rect1(m, i, &t);
	m_text_rect2(m);
	m_text_rect3(m);
}
