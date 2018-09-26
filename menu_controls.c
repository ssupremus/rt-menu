/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:42:42 by ysushkov          #+#    #+#             */
/*   Updated: 2018/09/25 12:43:00 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

static void		motion_enlarge2(t_menu *m)
{
	if (m->e.motion.x > 205 && m->e.motion.x < 290 && m->e.motion.y > 420
		&& m->e.motion.y < 450)
		m->sw = 14;
	else
		m->sw = -1;
}

static void		motion_enlarge1(t_menu *m)
{
	if (m->e.motion.x > 250 && m->e.motion.x < 335 && m->e.motion.y > 180
		&& m->e.motion.y < 210)
		m->sw = 7;
	else if (m->e.motion.x > 205 && m->e.motion.x < 290 && m->e.motion.y > 220
		&& m->e.motion.y < 250)
		m->sw = 8;
	else if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 260
		&& m->e.motion.y < 290)
		m->sw = 9;
	else if (m->e.motion.x > 250 && m->e.motion.x < 335 && m->e.motion.y > 260
		&& m->e.motion.y < 290)
		m->sw = 10;
	else if (m->e.motion.x > 205 && m->e.motion.x < 290 && m->e.motion.y > 300
		&& m->e.motion.y < 330)
		m->sw = 11;
	else if (m->e.motion.x > 205 && m->e.motion.x < 290 && m->e.motion.y > 340
		&& m->e.motion.y < 370)
		m->sw = 12;
	else if (m->e.motion.x > 205 && m->e.motion.x < 290 && m->e.motion.y > 380
		&& m->e.motion.y < 410)
		m->sw = 13;
	else
		motion_enlarge2(m);
}

void			menu_motion(t_menu *m)
{
	if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 60
		&& m->e.motion.y < 90)
		m->sw = 0;
	else if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 100
		&& m->e.motion.y < 130)
		m->sw = 1;
	else if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 140
		&& m->e.motion.y < 170)
		m->sw = 2;
	else if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 180
		&& m->e.motion.y < 210)
		m->sw = 3;
	else if (m->e.motion.x > 250 && m->e.motion.x < 335 && m->e.motion.y > 60
		&& m->e.motion.y < 90)
		m->sw = 4;
	else if (m->e.motion.x > 250 && m->e.motion.x < 335 && m->e.motion.y > 100
		&& m->e.motion.y < 130)
		m->sw = 5;
	else if (m->e.motion.x > 250 && m->e.motion.x < 335 && m->e.motion.y > 140
		&& m->e.motion.y < 170)
		m->sw = 6;
	else
		motion_enlarge1(m);
}

static void		mouse_enlarge1(t_menu *m, t_r *rtv, int *i, int *j)
{
	if (m->e.button.x > 250 && m->e.button.x < 335 && m->e.button.y > 180
		&& m->e.button.y < 210)
		zoom_on(rtv, 0);
	else if (m->e.button.x > 205 && m->e.button.x < 290 && m->e.button.y > 220
		&& m->e.button.y < 250)
		dvig_up(rtv, 0);
	else if (m->e.button.x > 160 && m->e.button.x < 245 && m->e.button.y > 260
		&& m->e.button.y < 290)
		dvig_left(rtv, 0);
	else if (m->e.button.x > 250 && m->e.button.x < 335 && m->e.button.y > 260
		&& m->e.button.y < 290)
		dvig_right(rtv, 0);
	else if (m->e.button.x > 205 && m->e.button.x < 290 && m->e.button.y > 300
		&& m->e.button.y < 330)
		dvig_down(rtv, 0);
	else if (m->e.button.x > 205 && m->e.button.x < 290 && m->e.button.y > 340
		&& m->e.button.y < 370)
		efects(rtv, i);
	else if (m->e.button.x > 205 && m->e.button.x < 290 && m->e.button.y > 380
		&& m->e.button.y < 410)
		screen(rtv);
	else if (m->e.button.x > 205 && m->e.button.x < 290 && m->e.button.y > 420
		&& m->e.button.y < 450)
		pixels(rtv, j);
}

void			menu_mouse(t_menu *m, t_r *rtv, int *i, int *j)
{
	if (m->e.button.x > 160 && m->e.button.x < 245 && m->e.button.y > 60
		&& m->e.button.y < 90)
		dvig_left(rtv, 1);
	else if (m->e.button.x > 160 && m->e.button.x < 245 && m->e.button.y > 100
		&& m->e.button.y < 130)
		dvig_down(rtv, 1);
	else if (m->e.button.x > 160 && m->e.button.x < 245 && m->e.button.y > 140
		&& m->e.button.y < 170)
		zoom_of(rtv, 1);
	else if (m->e.button.x > 160 && m->e.button.x < 245 && m->e.button.y > 180
		&& m->e.button.y < 210)
		zoom_of(rtv, 0);
	else if (m->e.button.x > 250 && m->e.button.x < 335 && m->e.button.y > 60
		&& m->e.button.y < 90)
		dvig_right(rtv, 1);
	else if (m->e.button.x > 250 && m->e.button.x < 335 && m->e.button.y > 100
		&& m->e.button.y < 130)
		dvig_up(rtv, 1);
	else if (m->e.button.x > 250 && m->e.button.x < 335 && m->e.button.y > 140
		&& m->e.button.y < 170)
		zoom_on(rtv, 1);
	else
		mouse_enlarge1(m, rtv, i, j);
}
