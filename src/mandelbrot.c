/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:57:39 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 18:34:08 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *env, int *i)
{
	double	tmp;

	env->f.cr = (env->f.x + DECALX) / env->f.zoom + env->f.x1;
	env->f.ci = (env->f.y + DECALY) / env->f.zoom + env->f.y1;
	env->f.zr = 0;
	env->f.zi = 0;
	while (EZR * EZR + EZI * EZI < 4 && ++(*i) < env->f.iter_max)
	{
		tmp = env->f.zr;
		env->f.zr = EZR * EZR - EZI * EZI + env->f.cr;
		env->f.zi = 2 * tmp * env->f.zi + env->f.ci;
	}
	ft_pixel_put(env, color(*i, (EZR * EZR + EZI * EZI), env));
}
