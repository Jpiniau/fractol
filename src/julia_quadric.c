/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_quadric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:09:21 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 17:09:24 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_quadric(t_env *env, int *i)
{
	double n;
	double tmp;

	env->f.zr = (env->f.x + DECALX) / env->f.zoom + env->f.x1;
	env->f.zi = (env->f.y + DECALY) / env->f.zoom + env->f.y1;
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
