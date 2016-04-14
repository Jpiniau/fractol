/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 11:23:26 by jpiniau           #+#    #+#             */
/*   Updated: 2016/04/14 16:35:31 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_env	ft_get_data(t_env *e)
{
	int		bpp;
	int		sizeline;
	int		endian;

	e->data = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
	e->data_img.bpp = bpp;
	e->data_img.sizeline = sizeline;
	e->data_img.endian = endian;
	return (*e);
}

static int		ft_key_hook_2(int keycode, t_env *env)
{
	if (keycode == PUP)
		env->f.iter_max += 10;
	else if (keycode == PDOWN)
		env->f.iter_max -= 10;
	else if (keycode == Z)
		env->f.color = 1;
	else if (keycode == X)
		env->f.color = 2;
	else if (keycode == R)
		ft_reset(env);
	else
		ft_change(env, keycode);
	return (0);
}

static int		ft_key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == W)
		env->f.decal_y -= 10;
	else if (keycode == S)
		env->f.decal_y += 10;
	else if (keycode == A)
		env->f.decal_x -= 10;
	else if (keycode == D)
		env->f.decal_x += 10;
	else if (keycode == P && env->f.motion == 1)
		env->f.motion = 0;
	else if (keycode == P && env->f.motion == 0)
		env->f.motion = 1;
	else if (keycode == M && env->f.m == 0)
		env->f.m = 1;
	else if (keycode == M && env->f.m == 1)
		env->f.m = 0;
	else
		ft_key_hook_2(keycode, env);
	ft_draw(env);
	return (0);
}

int				main(int ac, char **av)
{
	t_env	env;

	(void)av;
	if (ac < 2)
	{
		ft_menu_shell();
		return (0);
	}
	env.f = ft_init(av[1]);
	env.f.height = (env.f.x2 - env.f.x1) * env.f.zoom;
	env.f.width = (env.f.y2 - env.f.y1) * env.f.zoom;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.f.height, env.f.width, "Fractol");
	env.img = mlx_new_image(env.mlx, env.f.height, env.f.width);
	env = ft_get_data(&env);
	ft_draw(&env);
	mlx_key_hook(env.win, ft_key_hook, &env);
	mlx_mouse_hook(env.win, ft_mouse_hook, &env);
	mlx_hook(env.win, 6, (1L << 6), motion_hook, &env);
	mlx_loop(env.mlx);
}
