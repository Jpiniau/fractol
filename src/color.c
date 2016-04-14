/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:21:56 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 20:15:50 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <math.h>

static double			ft_rand(int lim)
{
	static long a = 100001;

	a = (a * 125) % 2796203;
	return ((a % lim) + 1);
}

static unsigned int		hsv_to_rgb(double h, double s, double v)
{
	t_hsv	hsv;

	hsv.i = floor(h / 60);
	hsv.f = (h / 60) - hsv.i;
	hsv.l = v * (1 - s);
	hsv.m = v * (1 - hsv.f * s);
	hsv.n = v * (1 - (1 - hsv.f) * s);
	hsv.l *= 255;
	hsv.m *= 255;
	hsv.n *= 255;
	v *= 255;
	if (hsv.i == 0)
		return (((int)v << 16) + ((int)hsv.n << 8) + (int)hsv.l);
	else if (hsv.i == 1)
		return (((int)hsv.m << 16) + ((int)v << 8) + (int)hsv.l);
	else if (hsv.i == 2)
		return (((int)hsv.l << 16) + ((int)v << 8) + (int)hsv.n);
	else if (hsv.i == 3)
		return (((int)hsv.l << 16) + ((int)hsv.m << 8) + (int)v);
	else if (hsv.i == 4)
		return (((int)hsv.n << 16) + ((int)hsv.l << 8) + (int)v);
	else
		return (((int)v << 16) + ((int)hsv.l << 8) + (int)hsv.m);
}

static void				ft_creset(double *a, double *c)
{
	*a = 10;
	*c = 1;
}

unsigned int			color(int i, double n, t_env *env)
{
	double			color;
	static double	a = 10;
	static double	c = 1;

	n = sqrt(n);
	if (i == ITERM)
		return (0);
	color = i + 1 - log(log(n) / log(2)) / log(2);
	if (env->f.color == 1)
	{
		a = ft_rand(90);
		c = ft_rand(9);
		env->f.color = 0;
	}
	else if (env->f.color == 2)
	{
		ft_creset(&a, &c);
		env->f.color = 0;
	}
	return (hsv_to_rgb(0.50 + a * color, 0.6, c));
}
