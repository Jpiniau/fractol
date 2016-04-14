/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:00:07 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/10 19:11:17 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_cadre(int x1, int y1, t_env *e)
{
	int x;
	int y;

	y = -1;
	if (e->f.m)
	{
		while (++y <= 135)
		{
			x = -1;
			while (++x <= 255)
				mlx_pixel_put(e->mlx, e->win, x + x1, y + y1, 0x000000);
		}
	}
	else
	{
		while (++y <= 25)
		{
			x = -1;
			while (++x <= 55)
				mlx_pixel_put(e->mlx, e->win, x + x1, y + y1, 0x000000);
		}
	}
}

static void	ft_affic(t_env *e)
{
	int		x1;
	int		y1;
	char	*vue;
	char	*echelle;
	char	*menu;

	vue = ft_strdup("Change fractal: arrow");
	echelle = ft_strdup("\"echelle\" de z: fleche haut/bas");
	menu = ft_strdup("afficher/cacher menu: m");
	x1 = e->f.height - 250;
	y1 = e->f.width - 135;
	ft_cadre(e->f.height - 255, e->f.width - 135, e);
	mlx_string_put(e->mlx, e->win, x1 + 120, y1, 0xffffff, "Menu");
	mlx_string_put(e->mlx, e->win, x1, y1 + 25, 0xffffff, vue);
	mlx_string_put(e->mlx, e->win, x1, y1 + 40, 0xffffff, "Move: wasd");
	mlx_string_put(e->mlx, e->win, x1, y1 + 55, 0xffffff, "Zoom in/out: wheel");
	mlx_string_put(e->mlx, e->win, x1, y1 + 70, 0xffffff, "Reset: r");
	mlx_string_put(e->mlx, e->win, x1, y1 + 85, 0xffffff, "Random color: z");
	mlx_string_put(e->mlx, e->win, x1, y1 + 100, 0xffffff, "Normal color: x");
	mlx_string_put(e->mlx, e->win, x1, y1 + 115, 0xffffff, "Pause: p");
}

void		ft_menu(t_env *env)
{
	int		x1;
	int		y1;

	if (env->f.m)
		ft_affic(env);
	else
	{
		ft_cadre(HEIGHT - 55, WIDTH - 25, env);
		x1 = HEIGHT - 55;
		y1 = WIDTH - 25;
		mlx_string_put(env->mlx, env->win, x1, y1, 0xffffff, "Menu");
		mlx_string_put(env->mlx, env->win, x1 + 45, y1, 0xffffff, "m");
	}
}
