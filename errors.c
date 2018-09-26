/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:45:56 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/14 12:27:14 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rt.h"

void	error(const char *str)
{
	ft_putstr("INIT ERROR: ");
	ft_putendl(str);
}

void	error1(const char *str, t_r *rtv)
{
	ft_putstr("RT ERROR: ");
	ft_putendl(str);
	SDL_DestroyRenderer(rtv->ren);
	SDL_DestroyWindow(rtv->win);
	SDL_Quit();
	exit(0);
}

void	error2(int ret, int fd, char *av, t_r *rtv)
{
	if (fd < 0)
	{
		perror(av);
		SDL_DestroyRenderer(rtv->ren);
		SDL_DestroyWindow(rtv->win);
		SDL_Quit();
		exit(0);
	}
	if (ret < 0)
	{
		error1(strerror(errno), rtv);
		SDL_DestroyRenderer(rtv->ren);
		SDL_DestroyWindow(rtv->win);
		SDL_Quit();
		exit(0);
	}
}

void	error3(const char *str, SDL_Surface **surface)
{
	ft_putstr("RT ERROR: ");
	ft_putendl(str);
	SDL_FreeSurface(*surface);
}
