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
	m->txt.s[0] = TTF_RenderText_Solid(m->txt.font, "Rotation:", m->txt.color);
	m->txt.s[1] = TTF_RenderText_Solid(m->txt.font, "X-axis", m->txt.color);
	m->txt.s[2] = TTF_RenderText_Solid(m->txt.font, "Y-axis", m->txt.color);
	m->txt.s[3] = TTF_RenderText_Solid(m->txt.font, "Z-axis", m->txt.color);
	m->txt.s[4] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[5] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[6] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[7] = TTF_RenderText_Solid(m->txt.font, "-", m->txt.color);
	m->txt.s[8] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[9] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[10] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[11] = TTF_RenderText_Solid(m->txt.font, "+", m->txt.color);
	m->txt.s[12] = TTF_RenderText_Solid(m->txt.font, "up", m->txt.color);
	m->txt.s[13] = TTF_RenderText_Solid(m->txt.font, "left", m->txt.color);
	m->txt.s[14] = TTF_RenderText_Solid(m->txt.font, "right", m->txt.color);
	m->txt.s[15] = TTF_RenderText_Solid(m->txt.font, "down", m->txt.color);
	m->txt.s[16] = TTF_RenderText_Solid(m->txt.font, "Zoom:", m->txt.color);
	m->txt.s[17] = TTF_RenderText_Solid(m->txt.font, "Movements:", m->txt.color);
	m->txt.s[18] = TTF_RenderText_Solid(m->txt.font, "Color filters:", m->txt.color);
	m->txt.s[19] = TTF_RenderText_Solid(m->txt.font, "switch", m->txt.color);
	i = -1;
	while (++i < 20)
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
	while (++i < 8)
	{
		m->txt.rect[i].x = 190;
		m->txt.rect[i].y = t;
		m->txt.rect[i].w = 25;
		m->txt.rect[i].h = 25;
		m->txt.rect[i + 4].x = 278;
		m->txt.rect[i + 4].y = t;
		m->txt.rect[i + 4].w = 25;
		m->txt.rect[i + 4].h = 30;
		t = t + 40;
	}
	m->txt.rect[12].x = 222;
	m->txt.rect[12].y = 220;
	m->txt.rect[12].w = 50;
	m->txt.rect[12].h = 25;
	m->txt.rect[13].x = 175;
	m->txt.rect[13].y = 260;
	m->txt.rect[13].w = 50;
	m->txt.rect[13].h = 25;
	m->txt.rect[14].x = 265;
	m->txt.rect[14].y = 260;
	m->txt.rect[14].w = 60;
	m->txt.rect[14].h = 25;
	m->txt.rect[15].x = 222;
	m->txt.rect[15].y = 300;
	m->txt.rect[15].w = 50;
	m->txt.rect[15].h = 25;

	m->txt.rect[16].x = 50;
	m->txt.rect[16].y = 180;
	m->txt.rect[16].w = 100;
	m->txt.rect[16].h = 30;

	m->txt.rect[17].x = 50;
	m->txt.rect[17].y = 220;
	m->txt.rect[17].w = 150;
	m->txt.rect[17].h = 30;

	m->txt.rect[18].x = 50;
	m->txt.rect[18].y = 340;
	m->txt.rect[18].w = 150;
	m->txt.rect[18].h = 30;
	
	m->txt.rect[19].x = 210;
	m->txt.rect[19].y = 340;
	m->txt.rect[19].w = 75;
	m->txt.rect[19].h = 25;
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
	while (++i < 5)
	{
		m->f.rect[i].x = 160;
		m->f.rect[i].y = t;
		m->f.rect[i].w = 85;
		m->f.rect[i].h = 30;
		m->f.rect[i + 4].x = 250;
		m->f.rect[i + 4].y = t;
		m->f.rect[i + 4].w = 85;
		m->f.rect[i + 4].h = 30;
		t = t + 40;
	}
	m->f.rect[9].x = 205;
	m->f.rect[9].y = 220;
	m->f.rect[9].w = 85;
	m->f.rect[9].h = 30;
	m->f.rect[10].x = 160;
	m->f.rect[10].y = 260;
	m->f.rect[10].w = 85;
	m->f.rect[10].h = 30;
	m->f.rect[11].x = 250;
	m->f.rect[11].y = 260;
	m->f.rect[11].w = 85;
	m->f.rect[11].h = 30;
	m->f.rect[12].x = 205;
	m->f.rect[12].y = 300;
	m->f.rect[12].w = 85;
	m->f.rect[12].h = 30;

	m->f.rect[13].x = 205;
	m->f.rect[13].y = 340;
	m->f.rect[13].w = 85;
	m->f.rect[13].h = 30;
}

void		ft_sw(t_menu *m)
{
	int i;

	m->slct.s = IMG_Load("m_images/transparent.png");
	m->slct.tex = SDL_CreateTextureFromSurface(m->r, m->slct.s);
	i = -1;
	while (++i < 13)
	{
		m->slct.rect[i].x = m->f.rect[i + 1].x;
		m->slct.rect[i].y = m->f.rect[i + 1].y;
		m->slct.rect[i].w = m->f.rect[i + 1].w;
		m->slct.rect[i].h = m->f.rect[i + 1].h; 
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
	m->sw = -1;
	m->backgrnd.s = IMG_Load("m_images/blue_rect.png");
	m->backgrnd.tex = SDL_CreateTextureFromSurface(m->r, m->backgrnd.s);
	loadtexts(m);
	m->backgrnd.rect.x = 0;
	m->backgrnd.rect.y = 0;
	m->backgrnd.rect.w = MWIDTH;
	m->backgrnd.rect.h = MHEIGHT;
	fields(m);
	ft_sw(m);
}

void		menu_keys(t_menu *m)
{
	m->keystate = SDL_GetKeyboardState(NULL);
	if (m->keystate[SDL_SCANCODE_ESCAPE])
			m->quit = 1;
}

void		menu_motion(t_menu *m)
{
	if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 60 && m->e.motion.y < 90)
		m->sw = 0;
	else if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 100 && m->e.motion.y < 130)
		m->sw = 1;
	else if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 140 && m->e.motion.y < 170)
		m->sw = 2;
	else if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 180 && m->e.motion.y < 210)
		m->sw = 3;
	else if (m->e.motion.x > 250 && m->e.motion.x < 335 && m->e.motion.y > 60 && m->e.motion.y < 90)
		m->sw = 4;
	else if (m->e.motion.x > 250 && m->e.motion.x < 335 && m->e.motion.y > 100 && m->e.motion.y < 130)
		m->sw = 5;
	else if (m->e.motion.x > 250 && m->e.motion.x < 335&& m->e.motion.y > 140 && m->e.motion.y < 170)
		m->sw = 6;
	else if (m->e.motion.x > 250 && m->e.motion.x < 335 && m->e.motion.y > 180 && m->e.motion.y < 210)
		m->sw = 7;
	else if (m->e.motion.x > 205 && m->e.motion.x < 290 && m->e.motion.y > 220 && m->e.motion.y < 250)
		m->sw = 8;
	else if (m->e.motion.x > 160 && m->e.motion.x < 245 && m->e.motion.y > 260 && m->e.motion.y < 290)
		m->sw = 9;
	else if (m->e.motion.x > 250 && m->e.motion.x < 335 && m->e.motion.y > 260 && m->e.motion.y < 290)
		m->sw = 10;
	else if (m->e.motion.x > 205 && m->e.motion.x < 290 && m->e.motion.y > 300 && m->e.motion.y < 330)
		m->sw = 11;
	else if (m->e.motion.x > 205 && m->e.motion.x < 290 && m->e.motion.y > 340 && m->e.motion.y < 370)
		m->sw = 12;
}

void		event_listener(t_menu *m)
{
	if (m->e.type == SDL_QUIT)
		m->quit = 1;
	else if (m->e.type == SDL_KEYDOWN)
		menu_keys(m);
	else if (m->e.type == SDL_MOUSEMOTION)
		menu_motion(m);
}

void		destructor(t_menu *m)
{
	int i;

	TTF_CloseFont(m->txt.font);
	SDL_DestroyTexture(m->backgrnd.tex);
	i = -1;
	while (++i < 20)
	{
		SDL_DestroyTexture(m->txt.tex[i]);
		SDL_FreeSurface(m->txt.s[i]);
	}
	SDL_FreeSurface(m->slct.s);
	SDL_DestroyTexture(m->slct.tex);
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
		while (++i < 14)
			SDL_RenderCopy(m.r, m.f.tex, NULL, &m.f.rect[i]);
		i = -1;
		while (++i < 20)
			SDL_RenderCopy(m.r, m.txt.tex[i], NULL, &m.txt.rect[i]);
		if (m.sw >= 0)
			SDL_RenderCopy(m.r, m.slct.tex, NULL, &m.slct.rect[m.sw]);
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