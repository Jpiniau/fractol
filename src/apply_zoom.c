/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:07:29 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 19:21:11 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	apply_zoom(t_env *env, int zoom, int x, int y)
{
	static double	i = 6;

	if (zoom == 1)
	{
		env->f.zoom *= 1.5;
		DECALX = DECALX + ((WIDTH - (WIDTH / 1.5)) / 2);
		DECALX = (DECALX + (x - WIDTH / 2) * (1 - (1 / 1.5))) * 1.5;
		DECALY = DECALY + ((HEIGHT - (HEIGHT / 1.5)) / 2);
		DECALY = (DECALY + (y - HEIGHT / 2) * (1 - (1 / 1.5))) * 1.5;
		env->f.iter_max += (int)i;
		if (i > 1.1)
			i /= 1.0001;
	}
	else if (zoom == 0 && env->f.zoom > 50)
	{
		env->f.zoom *= 0.7;
		DECALX = DECALX + ((WIDTH - (WIDTH / 0.7)) / 2);
		DECALX = (DECALX + (x - WIDTH / 2) * (1 - (1 / 0.7))) * 0.7;
		DECALY = DECALY + ((HEIGHT - (HEIGHT / 0.7)) / 2);
		DECALY = (DECALY + (y - HEIGHT / 2) * (1 - (1 / 0.7))) * 0.7;
		i *= 1.0001;
		env->f.iter_max -= (int)i;
	}
}
