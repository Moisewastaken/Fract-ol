/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:59:25 by mcochin           #+#    #+#             */
/*   Updated: 2022/08/10 18:39:15 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

/* STRUCTS */

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	int		w_size;
	int		iteration;
	char	*title;
	double	zoom;
	double	offset_y;
	double	offset_x;
	double	zoom_x;
	double	zoom_y;
	double	cx;
	double	cy;
	char	cur_fract;
	int		(*cur_palette)(int);
	int		palette_num;
}	t_mlx;

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
}	t_img;

typedef struct s_args {
	double	x;
	double	y;
	double	x_r;
	double	y_i;
	double	tmp_x;
	double	tmp_y;
	double	cx;
	double	cy;
	int		iteration;
	int		count;
}	t_args;

/* PROTOTYPES */

void	ft_fractal(t_mlx *cur);
void	mlx_events(t_mlx *cur);
void	ft_select(t_mlx *cur, int argc, char **argv);
void	get_julia_num(t_mlx *cur, char **argv);
void	print_msg(t_mlx *cur, int argc);
void	ft_exit(t_mlx *cur);
void	fractal_draw(t_mlx *cur, t_img *img);
double	coo_to_mark(t_mlx *cur, int n);
int		get_iteration(t_mlx *cur, t_args *arg);

/* EVENTS */

int		ft_close(t_mlx *cur);
int		ft_key_hook(int keycode, t_mlx *cur);
int		ft_mouse_hook(int keycode, int x, int y, t_mlx *cur);

/* IMG */

void	init_img(t_mlx *cur, t_img *img);
void	pxl_to_img(t_img *img, int x, int y, int color);

/* BONUS */

int		trippy_palette(int iter);
int		red_palette(int iter);
int		blue_palette(int iter);
int		green_palette(int iter);
int		pastel_palette(int iter);
int		pastel2_palette(int iter);
int		blacknwhite_palette(int iter);
void	get_palette(t_mlx *cur);
void	do_math(t_mlx *cur, t_args *arg);

#endif
