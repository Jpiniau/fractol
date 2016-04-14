/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 20:01:45 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/14 16:04:04 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_change(t_env *env, int key)
{
	if (key == NUM_1)
		env->f.ch = ft_strdup("mandelbrot");
	else if (key == NUM_2)
		env->f.ch = ft_strdup("julia");
	else if (key == NUM_3)
		env->f.ch = ft_strdup("cubic_mandelbrot");
	else if (key == NUM_4)
		env->f.ch = ft_strdup("quadric_mandelbrot");
	else if (key == NUM_5)
		env->f.ch = ft_strdup("quintic_mandelbrot");
	else if (key == NUM_6)
		env->f.ch = ft_strdup("julia_cubic");
	else if (key == NUM_7)
		env->f.ch = ft_strdup("julia_quadric");
	else if (key == NUM_8)
		env->f.ch = ft_strdup("julia_quintic");
	else if (key == NUM_9)
		env->f.ch = ft_strdup("burning_ship");
	else if (key == NUM_0)
		env->f.ch = ft_strdup("julia_burning_ship");
	else if (key == NUM__)
		env->f.ch = ft_strdup("bird");
	else if (key == NUM___)
		env->f.ch = ft_strdup("julia_bird");
}
