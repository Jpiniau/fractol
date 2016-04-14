/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:17:32 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/09 16:09:54 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_env *env, int *i)
{
	double		n;
	double		tmpr;
	double		tmpi;

	tmpr = 0;
	tmpi = 0;
	EZR = 0;
	EZI = 0;
	ECR = (env->f.x + DECALX) / (double)env->f.zoom + env->f.x1;
	ECI = (env->f.y + DECALY) / (double)env->f.zoom + env->f.y1;
	n = EZR * EZR + EZI * EZI;
	while (++(*i) < ITERM && n < 4)
	{
		EZI = 2 * fabs(EZI * EZR) + ECI;
		EZR = tmpr - tmpi - ECR;
		tmpr = EZR * EZR;
		tmpi = EZI * EZI;
		n = tmpr + tmpi;
	}
	ft_pixel_put(env, color(*i, (EZR * EZR + EZI * EZI), env));
}
