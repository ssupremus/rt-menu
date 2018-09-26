/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:11:00 by anhloba           #+#    #+#             */
/*   Updated: 2018/09/25 21:09:55 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <unistd.h>

# include "../src/libft/libft.h"
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define DEPTH 10
# define AMB 1
# define PNT 2
# define DIR 3
# define PAR 4
# define NUM_FIG rtv->count_fgr
# define NUM_LIT rtv->count_light
# define NUM_POT 4

# define NON 0
# define SEP 1
# define GRAY 2
# define GRAY1 3
# define B_W 4
# define ABSTRAKT 5
# define NEG 6
# define MULT1 7
# define MULT 8
# define BLUR 9
# define DISRUP1 10
# define DISRUP2 11
# define DISRUP3 12

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define CONE 4
# define PARABOL 5
# define MEBIUS 6
# define TORUS 7

# define MWIDTH 400
# define MHEIGHT 800

typedef struct				s_vektor
{
	double					x;
	double					y;
	double					z;
}							t_vek;

typedef struct				s_color
{
	int						r;
	int						g;
	int						b;
	int						a;
}							t_color;

typedef struct				s_rama
{
	double					d;
	double					w;
	double					h;
}							t_rama;

typedef struct				s_figur
{
	double					rad;
	double					rad1;
	double					r_r;
	double					r1_r1;
	double					reflect;
	double					trans;
	double					max_real;
	double					max_fgr[3];
	double					min_real;
	double					min_fgr[3];
	int						mater;
	int						name;
	t_vek					direct;
	t_vek					dir;
	t_vek					cut_real;
	t_vek					cut_f[3];
	t_vek					centr;
	t_color					color;
	int						txtr;
}							t_figur;

typedef struct				s_tochki
{

	double					t1;
	double					t2;
}							t_t;

typedef struct				s_light
{
	t_vek					pos;
	t_vek					direct;
	double					radiance;
	int						type;
	double					intence;
}							t_lit;

typedef struct				s_torus
{
	t_vek					oc;
	int						n_roots;
	int						i;
	double					roots[4];
	double					root;
	double					m;
	double					n;
	double					o1;
	double					p;
	double					q;
	double					a[4];
}							t_torus;

typedef struct				s_mebius
{
	double					a1;
	double					a2;
	double					a3;
	double					a4;
	t_vek					oc;
	double					roots[3];
	int						n_roots;
	int						i;
	double					res;
}							t_mebius;

typedef	struct				s_draw
{
	t_vek					o;
	t_figur					*sf;
	int						depth;
	t_t						min_max;
}							t_draw;

typedef struct				s_tracer
{
	t_vek					p;
	double					t_max;
	t_vek					n_v[2];
	t_color					c;
	t_vek					r;
	t_color					col;
	t_color					ref_col;
	int						inside;
	double					fac;
	double					fres;
	t_color					refract_col;
	double					ior;
	double					eta;
	double					cosi;
	double					k;
	double					inten;
	t_vek					refract;
	t_color					color_na_ekran;
	t_vek					cam_dir;

}							t_tracer;

typedef struct				s_liting
{
	t_vek					n_v_l[3];
	double					inten;
	t_t						min_max_sd;
	double					theta;
	t_figur					*sf;
	double					mat;
}							t_liting;

typedef struct				s_rtv1
{
	SDL_Window				*win;
	SDL_Renderer			*ren;
	SDL_Surface				*screen_shot;
	SDL_Texture				*background;
	t_rama					rama;
	t_figur					*fgr;
	t_lit					*lit;
	t_vek					pos;
	t_vek					rot;
	char					**list;
	double					min_cl;
	double					max_cl;
	double					min_sd;
	double					max_sd;
	double					a;
	double					b;
	double					c;
	double					w1;
	double					h1;
	int						col_efekt;
	int						count_cam;
	int						count_fgr;
	int						count_light;
	int						count_texture;
	int						w;
	int						h;
	int						depth;
	int						step;
	int						my_x;
	int						my_y;
	SDL_Surface				*jpg_4;
	SDL_Surface				*jpg_3;
	SDL_Surface				*jpg_u;
	int						surf_w[3];
	int						surf_h[3];
	int						img_background;
}							t_r;

typedef	struct				s_threads
{
	struct s_rtv1			*d;
	pthread_t				threads;
	t_color					*col;
	int						num;
	int						x;
	int						x1;
	int						y;
}							t_threads;

typedef struct				s_mtext
{
	TTF_Font				*font;
	SDL_Color				color;
	SDL_Surface				*s[22];
	SDL_Texture				*tex[22];
	SDL_Rect				rect[22];
}							t_mtext;

typedef struct				s_back
{
	SDL_Surface				*s;
	SDL_Texture				*tex;
	SDL_Rect				rect;
}							t_back;

typedef struct				s_fld
{
	SDL_Surface				*s;
	SDL_Texture				*tex;
	SDL_Rect				rect[16];
}							t_fld;

typedef struct				s_sw
{
	SDL_Surface				*s;
	SDL_Texture				*tex;
	SDL_Rect				rect[15];
}							t_sw;

typedef struct				s_mimg
{
	SDL_Surface				*sf;
	SDL_Texture				*tex;
	SDL_Rect				rect;
}							t_mimg;

typedef struct				s_menu
{
	SDL_Window				*w;
	SDL_Renderer			*r;
	Uint32					wid;
	t_back					backgrnd;
	t_mtext					txt;
	t_fld					f;
	t_sw					slct;
	t_mimg					ph;
	SDL_Event				e;
	int						quit;
	int						sw;
	const Uint8				*keystate;
}							t_menu;

void						error(const char *str);
void						error1(const char *str, t_r *rtv);
void						error2(int ret, int fd, char *av, t_r *rtv);
void						error3(const char *str, SDL_Surface **surface);
void						ft_init(t_r *rtv, t_menu *m);
void						dop_init(t_r *rtv);
void						dop_init_cone(double *r);
void						dop_init_parabol(double *r);
void						dop_init_mebius(double *r, double *rr);
void						dop_init_torus(double *r, double *rr);
void						ft_events(t_r *rtv, t_menu *m);
void						init_light(t_r *rtv);
void						init_figur(t_r *rtv);
void						init_cam(t_r *rtv);
void						draw(t_r *rtv);
t_color						color(t_color c, double coef);
int							debug(int color);
t_color						color_sum(t_color v1, t_color v2);
t_color						tracer(t_r *rtv, t_draw *dr, t_vek *d);
t_vek						vek_sum(t_vek v1, t_vek v2);
t_vek						vek_sub(t_vek v1, t_vek v2);
t_vek						vek_num(t_vek v1, double n);
t_vek						vek_mult(t_vek v1, t_vek v2);
double						vek_skal(t_vek v1, t_vek v2);
double						vek_len(t_vek v);
t_t							tracer_obj(t_vek o, t_vek d, t_figur *fgr);
t_vek						get_normal(t_tracer *tr, t_draw *dr, t_vek d);
t_vek						vek_cross(t_vek va, t_vek vb);
t_vek						vek_norm(t_vek v);
t_vek						conversion(t_r *rtv, int x, int y, int z);
t_vek						rot_z(t_r *rtv, t_vek d);
void						parsing(char *av, t_r *rtv);
int							pars_fig_close(t_r *rtv, int i,
										char *str, char *str_end);
int							p_atoi(const char *str);
double						p_atof(const char *str);
void						sph_parse(int i, t_r *rtv, int f_c);
void						plane_parse(int i, t_r *rtv, int f_c);
void						cyl_parse(int i, t_r *rtv, int f_c);
void						con_parse(int i, t_r *rtv, int f_c);
void						parabol_parse(int i, t_r *rtv, int f_c);
void						cam_parse(int i, t_r *rtv);
void						ligth_parse(int i, t_r *rtv, int c_l);
void						dvig_left(t_r *rtv, int s);
void						dvig_right(t_r *rtv, int s);
void						dvig_up(t_r *rtv, int s);
void						dvig_down(t_r *rtv, int s);
void						zoom_on(t_r *rtv, int s);
void						zoom_of(t_r *rtv, int s);
void						texture_draw(t_r *rtv);
t_color						get_pixel_int(SDL_Surface *surface, t_vek p,
										t_r *rtv, t_figur *sf);
SDL_Surface					*surface_find(t_figur *sf, t_r *rtv);
t_vek						reflect(t_vek r, t_vek n);
int							resolventa(double *x, double a, double b, double c);
t_t							tracer_mebius(t_vek o, t_vek d, t_figur *fgr);
void						mebius_parse(int i, t_r *rtv, int f_c);
void						torus_parse(int i, t_r *rtv, int f_c);
t_t							tracer_torus(t_vek o, t_vek d, t_figur *fgr);
int							quadric(double *x, double *a);
int							bikvadrat(double *x, double b, double d);
int							privedennoe(double *x, double b,
										double c, double d);
void						swap_roots(double *a, double *b, double *c);
t_t							my_csqrt(t_t a);
t_color						col_efekt(t_color c, t_r *rtv);
void						blur(t_color *c, int w, int h, int r);
t_color						mult(t_color c);
t_color						mult1(t_color c);
t_color						abstrakt(t_color c);
t_color						b_w_color(t_color c);
void						destroy_texture(t_r *rtv);
int							fix_xy(int v, int min, int max);
t_color						put_pxl(unsigned int c);
t_vek						vek_new(double x, double y, double z);
void						maping_help(t_figur *sf, t_r *rtv, int *wh);
double						*plane_mapping(t_vek d, t_figur *sf);
double						*sph_mapping(t_vek d);
double						*con_mapping(t_vek d, t_figur *sf);
double						*cyl_mapping(t_vek d, t_figur *sf);
double						mix(double a, double b, double mix);
t_t							tracer_sphere(t_vek o, t_vek d, t_figur *fgr);
t_t							tracer_helper(t_vek d, t_figur *fgr,
											t_vek oc, t_t t);
t_vek						get_norm_plane(t_figur *sf);
t_vek						get_norm_sphere(t_figur *sf, t_vek p);
t_vek						get_norm_cylinder(t_figur *sf, t_tracer *tr,
											t_vek o, t_vek d);
void						intence_cut(t_r *rtv);
void						get_local_coords(t_vek hit, t_vek *coord,
											t_vek orig, t_vek dir);
t_figur						*closest(t_r *rtv, t_draw *dr, t_vek *d,
									double *t_max);
t_figur						*closest_sd(t_r *rtv, t_vek o, t_vek *d,
										t_t min_max);
double						liting(t_r *rtv, t_tracer *tr, double mat, t_vek d);
void						fields(t_menu *m);
void						ft_sw(t_menu *m);
void						m_loadtexts(t_menu *m);
void						m_img_read(t_menu *m);
void						m_event_listener(t_menu *m, t_r *rtv);
void						menu_motion(t_menu *m);
void						menu_mouse(t_menu *m, t_r *rtv, int *i, int *j);
void						m_destructor(t_menu *m);
void						screen(t_r *rtv);
void						efects(t_r *rtv, int *i);
void						pixels(t_r *rtv, int *j);
int							*maping(t_vek d, t_r *rtv, t_figur *sf);

void						fgr_help_dir(int *i, t_r *rtv, int f_c);
void						fgr_help_centr(int *i, t_r *rtv, int f_c);
void						fgr_help_rgba(int *i, t_r *rtv, int f_c);
void						fgr_help_cut_f(int *i, t_r *rtv, int f_c, int n);
void						fgr_help_cut_real(int *i, t_r *rtv, int f_c);

void						fgr_help_cut_min_max(int *i, t_r *rtv,
							int f_c, int n);
void						fgr_help_real_cut_min_max(int *i, t_r *rtv,
							int f_c);

void						helper(char *list, t_r *rtv);

#endif
