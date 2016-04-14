/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:07:25 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/14 16:21:14 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac			ft_init(char *ch)
{
	t_frac	f;

	f.x1 = -2;
	f.x2 = 2;
	f.y1 = -2;
	f.y2 = 2;
	f.ch = ch;
	f.first = 1;
	f.zoom = ZOOM;
	f.iter_max = ITER;
	f.decal_x = 0;
	f.decal_y = 0;
	f.motion = 1;
	f.m = 0;
	f.color = 0;
	return (f);
}
