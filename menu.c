#include "menu.h"
#include <stdio.h>

void		loadtexts(t_menu *m)
{
	int i;
	int t;

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
	m->txt.s[0] = TTF_RenderText_Solid(m->txt.font, "Rotation:", m->txt.color);
	m->txt.s[1] = TTF_RenderText_Solid(m->txt.font, "X-axis", m->txt.color);
	m->txt.s[2] = TTF_RenderText_Solid(m->txt.font, "Y-axis", m->txt.color);
	m->txt.s[3] = TTF_RenderText_Solid(m->txt.font, "Z-axis", m->txt.color);
	m->txt.s[4] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[5] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[6] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[7] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[8] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[9] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	i = -1;
	while (++i < 10)
		m->txt.tex[i] = SDL_CreateTextureFromSurface(m->r, m->txt.s[i]);
	m->txt.rect[0].x = 50;
	m->txt.rect[0].y = 30;
	m->txt.rect[0].w = 100;
	m->txt.rect[0].h = 30;
	i = 0;
	t = 60;
	while (++i < 4)
	{
		m->txt.rect[i].x = 50;
		m->txt.rect[i].y = t;
		m->txt.rect[i].w = 80;
		m->txt.rect[i].h = 25;
		t = t + 40;
	}
	i = 3;
	t = 60;
	while (++i < 7)
	{
		m->txt.rect[i].x = 180;
		m->txt.rect[i].y = t;
		m->txt.rect[i].w = 25;
		m->txt.rect[i].h = 30;
		m->txt.rect[i + 3].x = 268;
		m->txt.rect[i + 3].y = t;
		m->txt.rect[i + 3].w = 25;
		m->txt.rect[i + 3].h = 25;
		t = t + 40;
	}
}

void		fields(t_menu *m)
{
	int i;
	int t;

	m->f.s = IMG_Load("m_images/50.png");
	m->f.tex = SDL_CreateTextureFromSurface(m->r, m->f.s);
	m->f.rect[0].x = 20;
	m->f.rect[0].y = 20;
	m->f.rect[0].w = MWIDTH - 40;
	m->f.rect[0].h = MHEIGHT - 40;
	i = 0;
	t = 60;
	while (++i < 4)
	{
		m->f.rect[i].x = 150;
		m->f.rect[i].y = t;
		m->f.rect[i].w = 80;
		m->f.rect[i].h = 30;
		m->f.rect[i + 3].x = 240;
		m->f.rect[i + 3].y = t;
		m->f.rect[i + 3].w = 80;
		m->f.rect[i + 3].h = 30;
		t = t + 40;
	}
}

void		initializer(t_menu *m)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0)
	{
		write(1, "Error\n", 1);
		exit(1);
	}
	m->w = SDL_CreateWindow("RT - Menu", 0, 0, MWIDTH, MHEIGHT, SDL_WINDOW_SHOWN);
	m->r = SDL_CreateRenderer(m->w, -1, SDL_RENDERER_ACCELERATED);
	m->quit = 0;
	m->sw = 0;
	m->backgrnd.s = IMG_Load("m_images/blue_rect.png");
	m->backgrnd.tex = SDL_CreateTextureFromSurface(m->r, m->backgrnd.s);
	loadtexts(m);
	m->backgrnd.rect.x = 0;
	m->backgrnd.rect.y = 0;
	m->backgrnd.rect.w = MWIDTH;
	m->backgrnd.rect.h = MHEIGHT;
	fields(m);	
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
	while (++i < 10)
	{
		SDL_DestroyTexture(m->txt.tex[i]);
		SDL_FreeSurface(m->txt.s[i]);
	}
	SDL_DestroyTexture(m->f.tex);
	SDL_FreeSurface(m->f.s);
	SDL_FreeSurface(m->backgrnd.s);
	SDL_DestroyRenderer(m->r);
	SDL_DestroyWindow(m->w);
}

void			menu(void)
{
	t_menu	m;
	int		i;

	initializer(&m);
	while (!m.quit && m.e.type != SDL_QUIT)
	{
		if (SDL_WaitEvent(&m.e))
			event_listener(&m);
		SDL_RenderClear(m.r);
		SDL_RenderCopy(m.r, m.backgrnd.tex, NULL, &m.backgrnd.rect);
		i = -1;
		while (++i < 7)
			SDL_RenderCopy(m.r, m.f.tex, NULL, &m.f.rect[i]);
		i = -1;
		while (++i < 10)
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