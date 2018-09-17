#ifndef __MENU_H
# define __MENU_H
# define MWIDTH 400
# define MHEIGHT 1300
# include <unistd.h>
# include <SDL2/SDL.h>
//# include <SDL2/SDL_image.h>
//# include <SDL2/SDL_ttf.h>
//# include <SDL2/SDL_mixer.h>
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"


typedef struct 		s_mtext
{
	TTF_Font		*font;
	SDL_Color		color;
	SDL_Surface		*s[10];
	SDL_Texture		*tex[10];
	SDL_Rect		rect[10];
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
	SDL_Rect		rect[7];
}					t_fld;

typedef struct		s_menu
{
	SDL_Window		*w;
	SDL_Renderer	*r;
	t_back			backgrnd;
	t_mtext			txt;
	t_fld			f;
	SDL_Event		e;
	int				quit;
	int				sw;
	const Uint8		*keystate;
}					t_menu;

void				menu(void);

#endif
