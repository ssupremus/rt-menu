/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_img_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:25:24 by ysushkov          #+#    #+#             */
/*   Updated: 2018/09/21 18:25:26 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"

static void		check_enlarger(t_menu *m)
{
	if ((m->slct.s = IMG_Load("m_images/transparent.png")) == NULL)
	{
		SDL_FreeSurface(m->backgrnd.s);
		SDL_FreeSurface(m->f.s);
		SDL_DestroyRenderer(m->r);
		SDL_DestroyWindow(m->w);
		write(1, "Menu image not found\n", 21);
		exit(1);
	}
	if ((m->ph.sf = IMG_Load("m_images/camera.png")) == NULL)
	{
		SDL_FreeSurface(m->slct.s);
		SDL_FreeSurface(m->backgrnd.s);
		SDL_FreeSurface(m->f.s);
		SDL_DestroyRenderer(m->r);
		SDL_DestroyWindow(m->w);
		write(1, "Menu image not found\n", 21);
		exit(1);
	}
}

void			m_img_read(t_menu *m)
{
	if ((m->backgrnd.s = IMG_Load("m_images/blue_rect.png")) == NULL)
	{
		SDL_DestroyRenderer(m->r);
		SDL_DestroyWindow(m->w);
		write(1, "Menu image not found\n", 21);
		exit(1);
	}
	if ((m->f.s = IMG_Load("m_images/50.png")) == NULL)
	{
		SDL_FreeSurface(m->backgrnd.s);
		SDL_DestroyRenderer(m->r);
		SDL_DestroyWindow(m->w);
		write(1, "Menu image not found\n", 21);
		exit(1);
	}
	check_enlarger(m);
}
