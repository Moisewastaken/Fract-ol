/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:44:33 by mcochin           #+#    #+#             */
/*   Updated: 2022/08/10 18:41:01 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

void	mlx_events(t_mlx *cur)
{
	mlx_hook(cur->win, 2, 1L << 0, ft_key_hook, cur);
	mlx_hook(cur->win, 17, 0, ft_close, cur);
	mlx_hook(cur->win, 4, 1L << 2, ft_mouse_hook, cur);
}

int	ft_mouse_hook(int keycode, int x, int y, t_mlx *cur)
{
	cur->zoom_x = coo_to_mark(cur, x) + cur->offset_x;
	cur->zoom_y = coo_to_mark(cur, y) + cur->offset_y;
	if (keycode == 4)
	{
		cur->zoom *= 0.8;
		cur->offset_x = cur->zoom_x - coo_to_mark(cur, x);
		cur->offset_y = cur->zoom_y - coo_to_mark(cur, y);
		ft_fractal(cur);
	}
	if (keycode == 5)
	{
		cur->zoom *= 1.2;
		cur->offset_x = cur->zoom_x - coo_to_mark(cur, x);
		cur->offset_y = cur->zoom_y - coo_to_mark(cur, y);
		ft_fractal(cur);
	}
	if (keycode == 1)
	{
		cur->offset_x = cur->zoom_x;
		cur->offset_y = cur->zoom_y;
		ft_fractal(cur);
	}
	return (0);
}

int	ft_key_hook(int keycode, t_mlx *cur)
{
	int	i;

	i = 0;
	if (keycode == 65307)
		ft_close(cur);
	if (keycode == 65362 && ++i)
		cur->offset_y -= 0.20 * cur->zoom;
	if (keycode == 65364 && ++i)
		cur->offset_y += 0.20 * cur->zoom;
	if (keycode == 65361 && ++i)
		cur->offset_x -= 0.20 * cur->zoom;
	if (keycode == 65363 && ++i)
		cur->offset_x += 0.20 * cur->zoom;
	if (keycode == 32 && ++i)
		get_palette(cur);
	if (keycode == 65453 && ++i)
		cur->iteration -= 10;
	if (keycode == 65451 && ++i)
		cur->iteration += 10;
	if (i > 0)
		ft_fractal(cur);
	return (0);
}

int	ft_close(t_mlx *cur)
{
	if (cur->win)
		mlx_destroy_window(cur->mlx, cur->win);
	mlx_destroy_display(cur->mlx);
	free(cur->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
