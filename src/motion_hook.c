/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:50:38 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 18:34:38 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int						motion_hook(int x, int y, t_env *e)
{
	int i;

	i = 0;
	if (!ft_strcmp(e->f.ch, "julia") || !ft_strcmp(e->f.ch, "julia_cubic")
			|| !ft_strcmp(e->f.ch, "julia_quadric")
			|| !ft_strcmp(e->f.ch, "julia_quintic")
			|| !ft_strcmp(e->f.ch, "julia_bird")
			|| !ft_strcmp(e->f.ch, "julia_burning_ship"))
		i = 1;
	if (x >= 0 && y >= 0 && x <= e->f.height && y <= e->f.width
			&& i && e->f.motion)
	{
		e->f.ci = y / e->f.zoom + e->f.y1;
		e->f.cr = x / e->f.zoom + e->f.x1;
	}
	else
		return (0);
	return (ft_draw(e));
}
