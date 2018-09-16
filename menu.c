#include "menu.h"
#include <stdio.h>

void		loadtexts(t_menu *m)
{
	int i;

	m->txt.font = TTF_OpenFont("m_fonts/opensans.ttf", 50);
	if (m->txt.font == NULL)
	{
		write(1, "Font error\n", 11);
		exit(1);
	}
	m->txt.color.r = 255;
	m->txt.color.g = 255;
	m->txt.color.b = 255;
	//m->txt.color.a = 100;
	m->txt.s[0] = TTF_RenderText_Solid(m->txt.font, "Example 1", m->txt.color);
	m->txt.s[1] = TTF_RenderText_Solid(m->txt.font, "Example 2", m->txt.color);
	i = -1;
	while (++i < 2)
		m->txt.tex[i] = SDL_CreateTextureFromSurface(m->r, m->txt.s[i]);
	m->txt.rect[0].x = 10;
	m->txt.rect[0].y = 10;
	m->txt.rect[0].w = 100;
	m->txt.rect[0].h = 30;
	m->txt.rect[1].x = 150;
	m->txt.rect[1].y = 10;
	m->txt.rect[1].w = 100;
	m->txt.rect[1].h = 30;
}

void		initializer(t_menu *m)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0)
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
	loadtexts(m);
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
	int i;

	TTF_CloseFont(m->txt.font);
	SDL_DestroyTexture(m->backgrnd.tex);
	i = -1;
	while (++i < 2)
	{
		SDL_DestroyTexture(m->txt.tex[i]);
		SDL_FreeSurface(m->txt.s[i]);
	}
	SDL_FreeSurface(m->backgrnd.s);
	SDL_DestroyRenderer(m->r);
	SDL_DestroyWindow(m->w);
}

void			menu(void)
{
	t_menu	m;
	int		i;

	initializer(&m);
	while (!m.quit)
	{
		if (SDL_WaitEvent(&m.e))
			event_listener(&m);
		SDL_RenderClear(m.r);
		SDL_RenderCopy(m.r, m.backgrnd.tex, NULL, &m.backgrnd.rect);
		i = -1;
		while (++i < 2)
			SDL_RenderCopy(m.r, m.txt.tex[i], NULL, &m.txt.rect[i]);
		SDL_RenderPresent(m.r);
	}
	destructor(&m);
	TTF_Quit();
	SDL_Quit();
}

int		main(void)
{
	menu();
	return (0);
}