/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:40:00 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 18:09:16 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_menu_shell(void)
{
	ft_putstr("utilisation: ./fractol <fractal>\n");
	ft_putstr("exemple: ./fractol mandelbrot\n");
	ft_putstr("Fractal possible:\n");
	ft_putendl("\tmandelbrot");
	ft_putendl("\tjulia");
	ft_putendl("\tburning_ship");
	ft_putendl("\tjulia_burning_ship");
	ft_putendl("\tbird");
	ft_putendl("\tjulia_bird");
	ft_putendl("\tcubic_mandelbrot");
	ft_putendl("\tquadric_mandelbrot");
	ft_putendl("\tquintic_mandelbrot");
	ft_putendl("\tjulia_cubic");
	ft_putendl("\tjulia_quadric");
	ft_putendl("\tjulia_quintic");
}
