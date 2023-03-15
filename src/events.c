/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:44:33 by mcochin           #+#    #+#             */
/*   Updated: 2022/08/10 18:38:24 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mlx_events(t_mlx *cur)
{	
	mlx_hook(cur->win, 2, 1L << 0, ft_key_hook, cur);
	mlx_hook(cur->win, 17, 0, ft_close, cur);
	mlx_hook(cur->win, 4, 1L << 2, ft_mouse_hook, cur);
}

int	ft_mouse_hook(int keycode, int x, int y, t_mlx *cur)
{
	if (keycode == 4)
	{
		cur->zoom *= 0.8;
		ft_fractal(cur);
	}
	if (keycode == 5)
	{
		cur->zoom *= 1.2;
		ft_fractal(cur);
	}
	if (keycode == 1)
	{
		cur->offset_x += coo_to_mark(cur, x);
		cur->offset_y += coo_to_mark(cur, y);
		ft_fractal(cur);
	}
	return (0);
}

int	ft_key_hook(int keycode, t_mlx *cur)
{
	if (keycode == 65307)
		ft_close(cur);
	if (keycode == 65453)
	{
		cur->iteration -= 10;
		ft_fractal(cur);
	}
	if (keycode == 65451)
	{
		cur->iteration += 10;
		ft_fractal(cur);
	}
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
