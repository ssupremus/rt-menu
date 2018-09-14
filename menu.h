#ifndef __MENU_H
# define __MENU_H
# define MWIDTH 400
# define MHEIGHT 1300
# include <unistd.h>
# include <SDL2/SDL.h>
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"

typedef struct		s_menu
{
	SDL_Window		*w;
	SDL_Renderer	*r;
	SDL_Surface		*s;
	SDL_Event		e;
	int				quit;
	int				sw;
	const Uint8		*keystate;
}					t_menu;

void				menu(void);

#endif
