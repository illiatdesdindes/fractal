/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 11:32:04 by alepinoy          #+#    #+#             */
/*   Updated: 2015/01/28 14:35:46 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fractol.h"

void			put_pxl_img(t_env *env, int x, int y, int color)
{
	unsigned int	value;
	char			*data;

	if (x < WIN_WIDTH && x >= 0 && y < WIN_HEIGHT && y >= 0)
	{
		value = mlx_get_color_value(env->mlx, color);
		data = env->data;
		ft_memcpy(data + y * env->linesize + x * (env->bits / 8), &value, 3);
	}
}

__device__ int	rgb(int type, int n, int m)
{
	return ((sin(((double)n / m) * 3.14 * type - (3.14 / 2)) + 1) / 2 * 255);
}

__device__ int	get_clr(int n, int m, int clr)
{
	if (clr == 0)
		return (CLR1 * rgb(2, n, m) + CLR2 * rgb(2, n, m) + rgb(2, n, m));
	else if (clr == 1)
		return (CLR1 * rgb(0, n, m) + CLR2 * rgb(2, n, m) + rgb(2, n, m));
	else if (clr == 2)
		return (CLR1 * rgb(0, n, m) + CLR2 * rgb(2, n, m) + rgb(0, n, m));
	else if (clr == 3)
		return (CLR1 * rgb(0, n, m) + CLR2 * rgb(4, n, m) + rgb(0, n, m));
	else if (clr == 4)
		return (CLR1 * rgb(4, n, m) + CLR2 * rgb(2, n, m) + rgb(0, n, m));
	return (CLR1 * rgb(6, n, m) + CLR2 * rgb(4, n, m) + rgb(0, n, m));
}
