/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quintic_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:11:04 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 18:39:53 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	quintic_mandelbrot(t_env *env, int *i)
{
	double n;
	double tmp;
	double tmp2;

	env->f.cr = (env->f.x + DECALX) / env->f.zoom + env->f.x1;
	env->f.ci = (env->f.y + DECALY) / env->f.zoom + env->f.y1;
	env->f.zr = 0;
	env->f.zi = 0;
	n = EZR * EZR + EZI * EZI;
	while (n < 4 && ++(*i) < env->f.iter_max)
	{
		tmp = EZR;
		tmp2 = EZR2;
		EZR = EZR5 - 10 * EZR2 * EZR * EZI2 + 5 * EZR * EZI2 * EZI2 + env->f.cr;
		EZI = 5 * tmp2 * tmp2 * EZI - 10 * tmp2 * EZI2 * EZI + EZI5 + env->f.ci;
		n = EZR * EZR + EZI * EZI;
	}
	ft_pixel_put(env, color(*i, (EZR * EZR + EZI * EZI), env));
}
