/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 11:41:09 by jpiniau           #+#    #+#             */
/*   Updated: 2016/03/11 16:19:41 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	ft_mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == MBL || button == MBUP)
		apply_zoom(e, 1, x, y);
	else if (button == MBR || button == MBDW)
		apply_zoom(e, 0, x, y);
	return (ft_draw(e));
}
