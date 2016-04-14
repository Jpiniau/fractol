/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:34:40 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/14 16:39:48 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

# define HEIGHT (env->f.height)
# define WIDTH (env->f.width)
# define ITER (50)
# define ITERM (env->f.iter_max)
# define ZOOM (100)

# define MBL (1)
# define MBR (2)
# define MBM (3)
# define MBDW (4)
# define MBUP (5)

# define ANGLE (0)
# define HAUTEUR (1)
# define ECHAP (53)
# define SPACE (49)
# define RIGHT (124)
# define LEFT (123)
# define UP (126)
# define DOWN (125)
# define MINUS (27)
# define PLUS (24)
# define A (0)
# define D (2)
# define H (4)
# define I (34)
# define M (46)
# define P (35)
# define R (15)
# define S (1)
# define W (13)
# define X (7)
# define Z (6)
# define VAG (50)
# define NUM_1 (18)
# define NUM_2 (19)
# define NUM_3 (20)
# define NUM_4 (21)
# define NUM_5 (23)
# define NUM_6 (22)
# define NUM_7 (26)
# define NUM_8 (28)
# define NUM_9 (25)
# define NUM_0 (29)
# define NUM__ (27)
# define NUM___ (24)
# define NUMPAD_PLUS (78)
# define NUMPAD_MINUS (69)
# define NUMPAD_0 (82)
# define NUMPAD_1 (83)
# define NUMPAD_2 (84)
# define NUMPAD_3 (85)
# define NUMPAD_4 (86)
# define NUMPAD_5 (87)
# define NUMPAD_6 (88)
# define NUMPAD_7 (89)
# define NUMPAD_8 (91)
# define NUMPAD_9 (92)
# define PUP (116)
# define PDOWN (121)

# define DECALX (env->f.decal_x)
# define DECALY (env->f.decal_y)
# define EZI (env->f.zi)
# define EZI2 (env->f.zi * env->f.zi)
# define EZI5 (EZI2 * EZI2 * EZI)
# define EZR (env->f.zr)
# define EZR2 (env->f.zr * env->f.zr)
# define EZR5 (EZR2 * EZR2 * EZR)
# define ECI (env->f.ci)
# define ECR (env->f.cr)

typedef struct	s_hsv
{
	double	i;
	double	f;
	double	l;
	double	m;
	double	n;
}				t_hsv;

typedef struct	s_frac
{
	double		x;
	double		x1;
	double		x2;
	double		y;
	double		y1;
	double		y2;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		mx;
	double		my;
	double		zoom;
	double		height;
	double		width;
	double		decal_x;
	double		decal_y;
	char		*ch;
	int			iter_max;
	int			motion;
	int			m;
	int			first;
	double		color;
}				t_frac;

typedef struct	s_data_img
{
	int			bpp;
	int			sizeline;
	int			endian;
}				t_data_img;

typedef struct	s_env
{
	char		*name;
	void		*mlx;
	void		*win;
	void		*img;
	t_data_img	data_img;
	char		*data;
	t_frac		f;
}				t_env;

t_frac			ft_init();
int				ft_pixel_put(t_env *e, int color);
void			mandelbrot(t_env *env, int *i);
void			cubic_mandelbrot(t_env *env, int *i);
void			quadric_mandelbrot(t_env *env, int *i);
void			quintic_mandelbrot(t_env *env, int *i);
void			julia(t_env *env, int *i);
void			julia_cubic(t_env *env, int *i);
void			julia_quadric(t_env *env, int *i);
void			julia_quintic(t_env *env, int *i);
void			bird(t_env *env, int *i);
void			julia_bird(t_env *env, int *i);
void			burning_ship(t_env *env, int *i);
void			julia_burning_ship(t_env *env, int *i);
unsigned int	color(int i, double n, t_env *env);
int				ft_draw(t_env *e);
int				ft_mouse_hook(int button, int x, int y, t_env *e);
int				motion_hook(int x, int y, t_env *e);
void			apply_zoom(t_env *env, int zoom, int x, int y);
void			ft_reset(t_env *env);
void			ft_change(t_env *env, int key);
void			ft_menu(t_env *e);
void			ft_menu_shell(void);

#endif
