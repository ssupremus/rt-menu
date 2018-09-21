/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:27:44 by ysushkov          #+#    #+#             */
/*   Updated: 2018/09/21 11:27:47 by ysushkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MENU_H
# define __MENU_H

# define MWIDTH 400
# define MHEIGHT 1300
# include <unistd.h>
# include <SDL2/SDL.h>
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"

/*
** # include <SDL2/SDL_image.h>
** # include <SDL2/SDL_ttf.h>
** # include <SDL2/SDL_mixer.h>
*/

typedef struct		s_mtext
{
	TTF_Font		*font;
	SDL_Color		color;
	SDL_Surface		*s[22];
	SDL_Texture		*tex[22];
	SDL_Rect		rect[22];
}					t_mtext;

typedef struct		s_back
{
	SDL_Surface		*s;
	SDL_Texture		*tex;
	SDL_Rect		rect;
}					t_back;

typedef struct		s_fld
{
	SDL_Surface		*s;
	SDL_Texture		*tex;
	SDL_Rect		rect[16];
}					t_fld;

typedef struct		s_sw
{
	SDL_Surface		*s;
	SDL_Texture		*tex;
	SDL_Rect		rect[15];
}					t_sw;

typedef struct		s_menu
{
	SDL_Window		*w;
	SDL_Renderer	*r;
	Uint32			wid;
	t_back			backgrnd;
	t_mtext			txt;
	t_fld			f;
	t_sw			slct;
	SDL_Event		e;
	int				quit;
	int				sw;
	const Uint8		*keystate;
}					t_menu;

void				menu_keys(t_menu *m);
void				menu_motion(t_menu *m);
void				menu_mouse(t_menu *m);
void				m_loadtexts(t_menu *m);
void				fields(t_menu *m);
void				ft_sw(t_menu *m);
void				menu(void);

#endif
