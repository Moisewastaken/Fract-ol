/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:32:29 by mcochin           #+#    #+#             */
/*   Updated: 2022/07/16 19:01:43 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
				pxl_to_img(img, arg.x, arg.y, cur->color_a);
			else
				pxl_to_img(img, arg.x, arg.y, cur->color_b + arg.count * 20);
		}
	}
}

int	get_iteration(t_mlx *cur, t_args *arg)
{
	arg->count = -1;
	if (cur->cur_fract == 'm')
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
	{
		arg->tmp_x = arg->x_r;
		arg->tmp_y = arg->y_i;
		arg->x_r = arg->tmp_x * arg->tmp_x - arg->tmp_y * arg->tmp_y + arg->cx;
		arg->y_i = 2 * arg->tmp_x * arg->tmp_y + arg->cy;
	}
	return (arg->count);
}

double	coo_to_mark(t_mlx *cur, int n)
{
	double	res;

	res = (4 * (double)n - cur->w_size * 2) / cur->w_size;
	res *= cur->zoom;
	return (res);
}
