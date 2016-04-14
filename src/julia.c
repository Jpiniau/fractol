/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:20:22 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/14 17:54:08 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			julia(t_env *env, int *i)
{
	double tmp;
	double n;

	env->f.zr = (env->f.x + env->f.decal_x) / env->f.zoom + env->f.x1;
	env->f.zi = (env->f.y + env->f.decal_y) / env->f.zoom + env->f.y1;
	n = EZR * EZR + EZI * EZI;
	while (n < 4 && ++(*i) < ITERM)
	{
		tmp = env->f.zr;
		env->f.zr = env->f.zr * env->f.zr - env->f.zi * env->f.zi + env->f.cr;
		env->f.zi = 2 * tmp * env->f.zi + env->f.ci;
		n = EZR * EZR + EZI * EZI;
	}
	ft_pixel_put(env, color(*i, n, env));
}
