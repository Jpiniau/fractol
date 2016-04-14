/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_burning_ship.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:28:32 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 17:39:03 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_burning_ship(t_env *env, int *i)
{
	double		n;
	double		tmpr;
	double		tmpi;

	tmpr = 0;
	tmpi = 0;
	EZR = (env->f.x + DECALX) / (double)env->f.zoom + env->f.x1;
	EZI = (env->f.y + DECALY) / (double)env->f.zoom + env->f.y1;
	n = EZR * EZR + EZI * EZI;
	while (++(*i) < ITERM && n < 4)
	{
		tmpi = EZI * EZI;
		tmpr = EZR * EZR;
		EZI = 2 * fabs(EZI * EZR) + ECI;
		EZR = tmpr - tmpi - ECR;
		n = tmpr + tmpi;
	}
	ft_pixel_put(env, color(*i, (EZR * EZR + EZI * EZI), env));
}
