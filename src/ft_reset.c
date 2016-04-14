/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:49:27 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 19:53:06 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_reset(t_env *env)
{
	env->f.first = 1;
	env->f.zoom = ZOOM;
	env->f.iter_max = ITER;
	env->f.decal_x = 0;
	env->f.decal_y = 0;
	env->f.motion = 1;
	env->f.m = 0;
	env->f.color = 2;
}
