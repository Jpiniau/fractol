/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:52:59 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 19:30:22 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ch_fractal2(t_env *e, int *i)
{
	if (!ft_strcmp(e->f.ch, "burning_ship"))
		burning_ship(e, i);
	else if (!ft_strcmp(e->f.ch, "julia_burning_ship"))
		julia_burning_ship(e, i);
	else if (!ft_strcmp(e->f.ch, "bird"))
		bird(e, i);
	else if (!ft_strcmp(e->f.ch, "julia_bird"))
		julia_bird(e, i);
	else
		mandelbrot(e, i);
}

static void		ch_fractal(t_env *e, int *i)
{
	if (!ft_strcmp(e->f.ch, "mandelbrot"))
		mandelbrot(e, i);
	else if (!ft_strcmp(e->f.ch, "cubic_mandelbrot"))
		cubic_mandelbrot(e, i);
	else if (!ft_strcmp(e->f.ch, "quadric_mandelbrot"))
		quadric_mandelbrot(e, i);
	else if (!ft_strcmp(e->f.ch, "quintic_mandelbrot"))
		quintic_mandelbrot(e, i);
	else if (!ft_strcmp(e->f.ch, "julia"))
		julia(e, i);
	else if (!ft_strcmp(e->f.ch, "julia_cubic"))
		julia_cubic(e, i);
	else if (!ft_strcmp(e->f.ch, "julia_quadric"))
		julia_quadric(e, i);
	else if (!ft_strcmp(e->f.ch, "julia_quintic"))
		julia_quintic(e, i);
	else
		ch_fractal2(e, i);
}

int				ft_draw(t_env *env)
{
	int			i;

	env->f.x = -1;
	if (env->f.first != 1)
		mlx_clear_window(env->mlx, env->win);
	env->f.first = 0;
	while (++env->f.x < env->f.height)
	{
		env->f.y = -1;
		while (++env->f.y < env->f.width)
		{
			i = -1;
			ch_fractal(env, &i);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	ft_menu(env);
	return (0);
}
