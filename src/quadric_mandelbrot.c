/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:40:32 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 15:00:40 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	quadric_mandelbrot(t_env *env, int *i)
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
		tmp = EZR;
		EZR = EZR2 * EZR2 - 6 * EZR2 * EZI2 + EZI2 * EZI2 + env->f.cr;
		EZI = 4 * tmp * tmp * tmp * EZI - 4 * tmp * EZI2 * EZI + env->f.ci;
		n = EZR * EZR + EZI * EZI;
	}
	ft_pixel_put(env, color(*i, (EZR * EZR + EZI * EZI), env));
}
