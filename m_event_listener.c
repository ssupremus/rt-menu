/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_event_listener.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:39:37 by ysushkov          #+#    #+#             */
/*   Updated: 2018/09/25 12:39:39 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void				m_event_listener(t_menu *m, t_r *rtv)
{
	static int i = 1;
	static int j = 0;

	if (m->e.type == SDL_MOUSEMOTION && m->e.motion.windowID == m->wid)
		menu_motion(m);
	else if (m->e.type == SDL_MOUSEBUTTONUP && m->e.button.windowID == m->wid)
		menu_mouse(m, rtv, &i, &j);
}
