/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:32:29 by mcochin           #+#    #+#             */
/*   Updated: 2022/07/16 18:44:48 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

void	ft_fractal(t_mlx *cur)
{
	t_img	img;
	int		s;

	s = cur->w_size;
	if (cur->win == NULL)
	{
		img.ptr = NULL;
		cur->win = mlx_new_window(cur->mlx, s, s, cur->title);
	}
	init_img(cur, &img);
	fractal_draw(cur, &img);
	mlx_put_image_to_window(cur->mlx, cur->win, img.ptr, 0, 0);
	mlx_destroy_image(cur->mlx, img.ptr);
}

void	fractal_draw(t_mlx *cur, t_img *img)
{
	t_args	arg;

	arg.y = -1;
	while (++arg.y < cur->w_size)
	{
		arg.x = -1;
		while (++arg.x < cur->w_size)
		{
			if (get_iteration(cur, &arg) == cur->iteration)
				pxl_to_img(img, arg.x, arg.y, 0x000000);
			else
				pxl_to_img(img, arg.x, arg.y, cur->cur_palette(arg.count));
		}
	}
}

int	get_iteration(t_mlx *cur, t_args *arg)
{
	arg->count = -1;
	if (cur->cur_fract == 'm' || cur->cur_fract == 'b')
	{
		arg->cx = coo_to_mark(cur, arg->x) + cur->offset_x;
		arg->cy = coo_to_mark(cur, arg->y) + cur->offset_y;
		arg->x_r = 0;
		arg->y_i = 0;
	}
	else
	{
		arg->cx = cur->cx;
		arg->cy = cur->cy;
		arg->x_r = coo_to_mark(cur, arg->x) + cur->offset_x;
		arg->y_i = coo_to_mark(cur, arg->y) + cur->offset_y;
	}
	while (++arg->count < cur->iteration
		&& arg->x_r * arg->x_r + arg->y_i * arg->y_i < 4)
		do_math(cur, arg);
	return (arg->count);
}

void	do_math(t_mlx *cur, t_args *arg)
{
	long double	tmp_x;
	long double	tmp_y;

	tmp_x = arg->x_r;
	tmp_y = arg->y_i;
	arg->x_r = tmp_x * tmp_x - tmp_y * tmp_y + arg->cx;
	arg->y_i = 2 * tmp_x * tmp_y + arg->cy;
	if (cur->cur_fract == 'b' && arg->x_r < 0)
		arg->x_r *= -1;
	if (cur->cur_fract == 'b' && arg->y_i < 0)
		arg->y_i *= -1;
}

double	coo_to_mark(t_mlx *cur, int n)
{
	double	res;

	res = (4 * (double)n - cur->w_size * 2) / cur->w_size;
	res *= cur->zoom;
	return (res);
}
