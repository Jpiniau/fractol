/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:18:23 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 18:21:13 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cubic_mandelbrot(t_env *env, int *i)
{
	double n;
	double tmp;

	env->f.cr = (env->f.x + DECALX) / env->f.zoom + env->f.x1;
	env->f.ci = (env->f.y + DECALY) / env->f.zoom + env->f.y1;
	env->f.zr = 0;
	env->f.zi = 0;
	n = EZR * EZR + EZI * EZI;
	while (n < 4 && ++(*i) < env->f.iter_max)
	{
		tmp = env->f.zr;
		env->f.zr = EZR * EZR * EZR - 3 * EZR * EZI * EZI + env->f.cr;
		env->f.zi = 3 * tmp * tmp * EZI - EZI * EZI * EZI + env->f.ci;
		n = EZR * EZR + EZI * EZI;
	}
	ft_pixel_put(env, color(*i, (EZR * EZR + EZI * EZI), env));
}
