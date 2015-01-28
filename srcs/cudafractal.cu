/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cudafractal.cu                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 13:53:04 by svachere          #+#    #+#             */
/*   Updated: 2015/01/28 13:53:04 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		julia(t_env *env, int x, int y, int max)
{
	float		temp_x;
	float		temp_y;
	float		coord_x;
	float		coord_y;
	int			i;

	coord_x = (((x + env->xzoom) / env->zoom / WIN_WIDTH) * 4 - 2);
	coord_y = (((y + env->yzoom) / env->zoom / WIN_HEIGHT) * 4 - 2);
	i = 0;
	while (((coord_x * coord_x) + (coord_y * coord_y)) < 4 && i < max)
	{
		temp_x = coord_x;
		temp_y = coord_y;
		coord_x = (temp_x * temp_x) - (temp_y * temp_y) + env->dx;
		coord_y = (temp_x * temp_y) + (temp_x * temp_y) + env->dy;
		i++;
	}
	return (i);
}

int		mandelbrot(t_env *env, int x, int y, int max)
{
	float		temp_x;
	float		temp_y;
	float		coord_x;
	float		coord_y;
	int			i;

	coord_x = 0.0;
	coord_y = 0.0;
	i = 0;
	while (((coord_x * coord_x) + (coord_y * coord_y)) < 4 && i < max)
	{
		temp_x = coord_x;
		temp_y = coord_y;
		coord_x = (temp_x * temp_x) - (temp_y * temp_y) + \
				(((x + env->xzoom) / env->zoom / WIN_WIDTH) * 4 - 2);
		coord_y = (temp_x * temp_y) + (temp_x * temp_y) + \
				(((y + env->yzoom) / env->zoom / WIN_HEIGHT) * 4 - 2);
		i++;
	}
	return (i);
}

int		sierpinski(t_env *env, int x, int y, int max)
{
	int		i;
	int		temp;

	x = ((x + env->xzoom) / env->zoom);
	if (x < 0)
		x = -x;
	y = ((y + env->yzoom) / env->zoom);
	if (y < 0)
		y = -y;
	temp = max;
	i = 0;
	while ((x > 0 || y > 0) && i < temp)
	{
		if ((x % 3) == 1 && (y % 3) == 1)
			return (i);
		x /= 3;
		y /= 3;
		i++;
	}
	return (temp);
}



void	cuda_draw_frac(t_env *env, int max)
{
	while (x <= WIN_WIDTH)
	{
		y = 0
		while (y <= WIN_HEIGHT)
		{
			if (env->choice == 's')
				put_pxl_img(env, x, y, get_clr(sierpinski(env, x, y, max), \
							max, env->clr));
			else if (env->choice == 'm')
				put_pxl_img(env, x, y, get_clr(mandelbrot(env, x, y, max), \
							max, env->clr));
			else if (env->choice == 'j')
				put_pxl_img(env, x, y, get_clr(julia(env, x, y, max), \
							max, env->clr));
			y++;
		}
		x++;
	}
}
