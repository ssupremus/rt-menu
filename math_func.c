/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:31:03 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/25 18:48:56 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	helper_draw1(t_r *rtv, double x, double y, t_vek *d)
{
	d[0] = conversion(rtv, x - rtv->w / 2,
		y - rtv->h / 2, 1);
	d[0] = rot_z(rtv, d[0]);
	d[1].x = x;
	d[1].y = y;
}

void	*draw1(void *ptk)
{
	t_threads	*p;
	t_vek		d[2];
	t_draw		dr;
	t_color		color;

	p = (t_threads *)ptk;
	dr.o = p->d->pos;
	dr.depth = DEPTH;
	dr.min_max = (t_t){p->d->min_cl, p->d->max_cl};
	p->x = p->d->w / NUM_POT * p->num;
	p->x1 = p->d->w / NUM_POT * (p->num + 1);
	while (p->x < p->x1)
	{
		p->y = 0;
		while (p->y < p->d->h)
		{
			dr.sf = NULL;
			helper_draw1(p->d, p->x, p->y, d);
			color = tracer(p->d, &dr, d);
			p->col[p->x * p->d->w + p->y] = col_efekt(color, p->d);
			p->y += p->d->step;
		}
		p->x += p->d->step;
	}
	pthread_exit(0);
}

void	draw2(t_r *rtv, t_color *color)
{
	int		x;
	int		y;

	if (rtv->col_efekt == BLUR)
		blur(color, rtv->w, rtv->h, 2);
	x = -1;
	while (++x < rtv->w)
	{
		y = -1;
		while (++y < rtv->h)
		{
			if (color[x * rtv->w + y].a == 254 && (rtv->img_background == 1 ||
				rtv->img_background == 3))
				;
			else
			{
				SDL_SetRenderDrawColor(rtv->ren, color[x * rtv->w + y].r,
					color[x * rtv->w + y].g, color[x * rtv->w + y].b, 255);
				SDL_RenderDrawPoint(rtv->ren, x, y);
			}
		}
	}
}

void	draw(t_r *rtv)
{
	t_threads	potok[NUM_POT];
	int			i;
	t_color		*color;

	if (rtv->count_texture > 0)
		texture_draw(rtv);
	dop_init(rtv);
	color = (t_color *)malloc(sizeof(t_color) * rtv->w * rtv->h);
	i = -1;
	while (++i < NUM_POT)
	{
		potok[i].d = rtv;
		potok[i].col = color;
		potok[i].num = i;
		pthread_create(&potok[i].threads, NULL, draw1, &potok[i]);
	}
	i = -1;
	while (++i < NUM_POT)
		pthread_join(potok[i].threads, NULL);
	draw2(rtv, color);
	ft_bzero(color, rtv->w * rtv->h * 16);
	free(color);
	SDL_RenderPresent(rtv->ren);
}
