/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bird.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:52:25 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 18:08:10 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia_bird(t_env *env, int *i)
{
	double		n;
	double		tmp;

	EZR = (env->f.x + DECALX) / (double)env->f.zoom + env->f.x1;
	EZI = (env->f.y + DECALY) / (double)env->f.zoom + env->f.y1;
	n = EZR * EZR + EZI * EZI;
	while (++(*i) < ITERM && n < 4)
	{
		tmp = EZI;
		EZI = ((EZR * EZR * 3) - (EZI * EZI)) * fabs(EZI) + ECI;
		EZR = ((EZR * EZR) - (tmp * tmp * 3)) * fabs(EZR) + ECR;
		n = EZR * EZR + EZI * EZI;
	}
	ft_pixel_put(env, color(*i, (EZR * EZR + EZI * EZI), env));
}
