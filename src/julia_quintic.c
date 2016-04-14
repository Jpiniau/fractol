/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_quintic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:05:48 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 18:38:12 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_quintic(t_env *env, int *i)
{
	double n;
	double tmp;
	double tmp2;

	env->f.zr = (env->f.x + DECALX) / env->f.zoom + env->f.x1;
	env->f.zi = (env->f.y + DECALY) / env->f.zoom + env->f.y1;
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
