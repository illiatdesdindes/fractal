/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 11:32:04 by alepinoy          #+#    #+#             */
/*   Updated: 2015/01/28 14:17:37 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fractol.h"

int		move_mouse(int x, int y, t_env *env)
{
	env->dx = ((double)x / WIN_WIDTH) * 2 - 1;
	env->dy = ((double)y / WIN_HEIGHT) * 2 - 1;
	if (x % 5 == 0 || y % 5 == 0)
		draw_fractal(env);
	return (0);
}

int		key_events(int key, t_env *env)
{
	int		mult;

	mult = 10 * ZOOM;
	if (key == 65307)
		do_close("");
	else if (key == 99)
		env->clr = (env->clr == 5) ? 0 : env->clr + 1;
	else if (key == 65451)
		env->iter *= 2;
	else if (key == 65453)
		env->iter /= 2;
	env->yzoom = (key == 65362) ? env->yzoom - mult : env->yzoom;
	env->yzoom = (key == 65364) ? env->yzoom + mult : env->yzoom;
	env->xzoom = (key == 65361) ? env->xzoom - mult : env->xzoom;
	env->xzoom = (key == 65363) ? env->xzoom + mult : env->xzoom;
	draw_fractal(env);
	return (0);
}
int		mouse_events(int button, int x, int y, t_env *env)
{
	if (button == 5 && env->zoom > 0)
	{
		env->zoom /= ZOOM;
		env->xzoom /= ZOOM;
		env->yzoom /= ZOOM;
		env->xzoom -= ((WIN_WIDTH - (WIN_WIDTH / ZOOM)) / 2) / ZOOM
					- (x - WIN_WIDTH / 2) * ZOOM + (x - WIN_WIDTH / 2);
		env->yzoom -= ((WIN_HEIGHT - (WIN_HEIGHT / ZOOM)) / 2) / ZOOM
					- (y - WIN_HEIGHT / 2) * ZOOM + (y - WIN_HEIGHT / 2);
		draw_fractal(env);
	}
	else if (button == 4 && env->zoom < 300000)
	{
		env->zoom *= ZOOM;
		env->xzoom *= ZOOM;
		env->yzoom *= ZOOM;
		env->xzoom += ((WIN_WIDTH - (WIN_WIDTH / ZOOM)) / 2) * ZOOM
					+ (x - WIN_WIDTH / 2) * ZOOM - (x - WIN_WIDTH / 2);
		env->yzoom += ((WIN_HEIGHT - (WIN_HEIGHT / ZOOM)) / 2) * ZOOM
					+ (y - WIN_HEIGHT / 2) * ZOOM - (y - WIN_HEIGHT / 2);
		draw_fractal(env);
	}
	return (0);
}

int		draw_fractal(t_env *env)
{
	ft_bzero(env->data, env->linesize * WIN_HEIGHT);
	cuda_draw_frac(env, env->iter);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
