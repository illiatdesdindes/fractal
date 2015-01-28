/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 13:53:04 by svachere          #+#    #+#             */
/*   Updated: 2015/01/28 13:56:27 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <fractol.h>

int		main(int ac, char **av)
{
	t_env	env;

	get_args(&env, ac, av);
	if ((env.mlx = mlx_init()) == NULL)
		return (-1);
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	env.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);
	env.data = mlx_get_data_addr(env.img, &(env.bits),
				&(env.linesize), &(env.end));
	mlx_expose_hook(env.win, draw_fractal, &env);
	mlx_mouse_hook(env.win, mouse_events, &env);
	mlx_key_hook(env.win, key_events, &env);
	if (env.choice == 'j')
		mlx_hook(env.win, MotionNotify, PointerMotionMask, move_mouse, &env);
	mlx_loop(env.mlx);
	return (0);
}

void	get_args(t_env *env, int ac, char **av)
{
	if (ac != 2 || (av[1][0] != 'm' && av[1][0] != 'j'
		&& av[1][0] != 's') || ft_strlen(av[1]) != 1)
		do_close("Syntax error. Please use ./fractol [m, j, or s]");
	else
	{
		env->xzoom = 0;
		env->yzoom = 0;
		env->zoom = 1;
		env->clr = 0;
		env->choice = av[1][0];
		env->iter = 42;
		if (env->choice == 's')
			env->clr = 5;
	}
}

void	do_close(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}
