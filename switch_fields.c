/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_fields.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:20:21 by ysushkov          #+#    #+#             */
/*   Updated: 2018/09/25 12:20:24 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

static void		fields_enlarge(t_menu *m)
{
	int i;
	int t;

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

void			fields(t_menu *m)
{
	int i;
	int t;

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
	fields_enlarge(m);
}

void			ft_sw(t_menu *m)
{
	int i;

	m->slct.tex = SDL_CreateTextureFromSurface(m->r, m->slct.s);
	i = 0;
	while (i < 15)
	{
		m->slct.rect[i].x = m->f.rect[i + 1].x;
		m->slct.rect[i].y = m->f.rect[i + 1].y;
		m->slct.rect[i].w = m->f.rect[i + 1].w;
		m->slct.rect[i].h = m->f.rect[i + 1].h;
		i++;
	}
}
