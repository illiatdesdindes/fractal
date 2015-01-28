/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 11:32:04 by alepinoy          #+#    #+#             */
/*   Updated: 2015/01/28 14:43:22 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
// # define env->iter 42
# define ZOOM 1.1
# define CLR1 0x10000
# define CLR2 0x100

# include <string.h>
# include <math.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	char		choice;
	double		dx;
	double		dy;
	float		zoom;
	int			clr;
	int			end;
	int			bits;
	int			linesize;
	int			xzoom;
	int			yzoom;
	int			iter;
}				t_env;

void			put_pxl_img(t_env *env, int x, int y, int color);
void			draw_frac(t_env *env, int max, int x, int y);
void			do_close(char *str);
void			get_args(t_env *env, int ac, char **av);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
int				draw_fractal(t_env *env);
int				mouse_events(int button, int x, int y, t_env *env);
int				move_mouse(int x, int y, t_env *env);
int				key_events(int key, t_env *env);
int				ft_pow(int n, int pow);
__device__ int	get_clr(int n, int m, int clr);
int				julia(t_env *env, int x, int y, int max);
int				mandelbrot(t_env *env, int x, int y, int max);
size_t			ft_strlen(const char *str);
size_t			ft_intlen(int n);
char			*ft_strnew(size_t size);
void			cuda_draw_frac(t_env *env, int max);

#endif
