/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_cubic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:46:27 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 16:54:50 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_cubic(t_env *env, int *i)
{
	double n;
	double tmp;

	env->f.zr = (env->f.x + DECALX) / env->f.zoom + env->f.x1;
	env->f.zi = (env->f.y + DECALY) / env->f.zoom + env->f.y1;
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
