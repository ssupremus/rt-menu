/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:14:42 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/24 21:46:18 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

int		main(int ac, char **av)
{
	t_r		rtv;
	t_menu	m;

	if (ac != 2)
	{
		ft_putstr("usage: ./RT [name.xml]\n");
		return (0);
	}
	parsing(av[1], &rtv);
	ft_init(&rtv, &m);
	init_light(&rtv);
	init_cam(&rtv);
	init_figur(&rtv);
	draw(&rtv);
	ft_events(&rtv, &m);
	destroy_texture(&rtv);
	SDL_DestroyRenderer(rtv.ren);
	SDL_DestroyWindow(rtv.win);
	SDL_Quit();
	return (0);
}
