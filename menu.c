#include "menu.h"
#include <stdio.h>

void		initializer(t_menu *m)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		write(1, "Error\n", 1);
		exit(1);
	}
	m->w = SDL_CreateWindow("Menu RT", 0, 0, MWIDTH, MHEIGHT, SDL_WINDOW_SHOWN);
	m->r = SDL_CreateRenderer(m->w, -1, SDL_RENDERER_ACCELERATED);
	m->quit = 0;
	m->sw = 0;
	m->backgrnd.s = IMG_Load("m_images/blue_rect.png");
	m->backgrnd.tex = SDL_CreateTextureFromSurface(m->r, m->backgrnd.s);
	m->backgrnd.rect.x = 0;
	m->backgrnd.rect.y = 0;
	m->backgrnd.rect.w = 400;
	m->backgrnd.rect.h = 1300;	
}

void		menu_keys(t_menu *m)
{
	m->keystate = SDL_GetKeyboardState(NULL);
	if (m->keystate[SDL_SCANCODE_ESCAPE])
			m->quit = 1;
}

void		event_listener(t_menu *m)
{
	if (m->e.type == SDL_QUIT)
		m->quit = 1;
	else if (m->e.type == SDL_KEYDOWN)
		menu_keys(m);
}

void		destructor(t_menu *m)
{
	SDL_DestroyTexture(m->backgrnd.tex);
	SDL_FreeSurface(m->backgrnd.s);
	SDL_DestroyRenderer(m->r);
	SDL_DestroyWindow(m->w);
}

void			menu(void)
{
	t_menu m;

	initializer(&m);
	while (!m.quit)
	{
		if (SDL_WaitEvent(&m.e))
			event_listener(&m);
		SDL_RenderClear(m.r);
		SDL_RenderCopy(m.r, m.backgrnd.tex, NULL, &m.backgrnd.rect);
		SDL_RenderPresent(m.r);
	}
	destructor(&m);
	SDL_Quit();
}

int		main(void)
{
	menu();
	return (0);
}