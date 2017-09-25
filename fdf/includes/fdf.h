/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:51:15 by vtiterin          #+#    #+#             */
/*   Updated: 2016/12/29 12:51:17 by vtiterin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define CH 1350
# define CW 1600

typedef struct	s_cord
{
	int			x;
	int			y;
	int			z;
}				t_cord;

typedef struct	s_c2d
{
	int			x2d;
	int			y2d;
	int			color;
	int			h;
}				t_c2d;

typedef struct	s_col
{
	int			col0;
	int			col1;
	int			col2;
	int			col3;
	int			p0;
	int			p1;
	int			p2;
	int			p3;
}				t_col;

typedef struct	s_main
{
	int			w;
	int			h;
	int			ox;
	int			oy;
	int			scale;
	t_cord		***tab;
	t_col		*col;
	void		*win;
	void		*mlx;
	void		*image;
	char		*ibuf;
	int			isize;
	int			icolor;
	int			iendian;
	double		scalez;
	int			maxz;
	double		anglex;
	double		angley;
	double		anglez;
	int			sx;
	int			sy;
	int			sz;
	int			options;
	int			proj;
}				t_main;

typedef struct	s_bresenh
{
	int			deltax;
	int			deltay;
	int			signx;
	int			signy;
	int			err;
	int			err2;
}				t_bresenh;

int				ft_color(t_main *tab, int z);
void			ft_col0(t_main *tab, int i);
void			ft_col1(t_main *tab, int i);
void			ft_col2(t_main *tab, int i);
void			ft_col3(t_main *tab, int i);
char			*ft_chm(char *arvg, int *h, int *w);
t_cord			***cord_tab(char *arvg, int *w, int *h, int *maxz);
void			ft_inibres(t_bresenh *br, t_c2d *pr1, t_c2d *pr2);
void			ft_wrtab_hor(t_main *tab, int y, int i);
void			ft_wrtab_vert(t_main *tab, int y, int i);
int				expose_hook(t_main *tab);
int				key_hook(int keycode, t_main *tab);
void			my_key_func(int keycode, t_main *tab);
void			my_key_func2(int keycode, t_main *tab);
void			ft_im_left(t_main *tab);
void			ft_im_right(t_main *tab);
void			ft_im_up(t_main *tab);
void			ft_im_down(t_main *tab);
void			ft_zoom_up_z(t_main *tab);
void			ft_zoom_down_z(t_main *tab);
void			ft_rot_xp(t_main *tab);
void			ft_rot_xm(t_main *tab);
void			ft_rot_yp(t_main *tab);
void			ft_rot_ym(t_main *tab);
void			ft_rot_zp(t_main *tab);
void			ft_rot_zm(t_main *tab);
void			ft_legend(t_main *tab);
void			ft_proj(t_main *tab);
void			ft_zoom_down(t_main *tab);
void			ft_color_b0(t_main *tab);
void			ft_color_b1(t_main *tab);
void			ft_color_b2(t_main *tab);
void			ft_color_b3(t_main *tab);
void			ft_zoom_up(t_main *tab);
void			ft_base_scale(t_main *tab);
int				ft_chcollor(t_c2d *pr1, t_c2d *pr2);
t_c2d			*ft_2d_proj(t_cord *cord, t_main *tab);
int				ft_intlen(int n);
int				ft_words(char *str, char c);
void			ft_up_str(char **buf, int l, char *line);
char			*read_matrix(char *arvg, int *h, int *w);
void			ft_frtab(char	**cord);
void			ft_rotate_x(t_main *tab, int *sx, int *sy, int *sz);
void			ft_rotate_y(t_main *tab, int *sx, int *sy, int *sz);
void			ft_rotate_z(t_main *tab, int *sx, int *sy, int *sz);
void			ft_pr_legend(t_main *tab);
void			ft_drawline(t_c2d *pr1, t_c2d *pr2, char *data, int size);
void			ft_wr_tab(t_main *tab);
void			ft_ini(t_main *tab, char **arg);

#endif
