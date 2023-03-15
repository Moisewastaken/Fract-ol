/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:21:25 by mcochin           #+#    #+#             */
/*   Updated: 2022/08/31 15:24:57 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_msg(t_mlx *cur)
{
	ft_printf("Type 'mandelbrot' to display Mandelbrot's Set\n");
	ft_printf("Type 'julia' to display Julia's Set\n");
	ft_printf("You can add numbers after 'julia'");
	ft_printf(" to display different figures\n");
	ft_close(cur);
}

void	get_julia_num(t_mlx *cur, char **argv)
{
	if (argv[1][5] == '1')
	{
		cur->cx = 0.285;
		cur->cy = 0.01;
	}
	if (argv[1][5] == '2')
	{
		cur->cx = -0.8;
		cur->cy = 0.156;
	}
	if (argv[1][5] == '3')
	{
		cur->cx = 0.285;
		cur->cy = 0.013;
	}
	if (argv[1][5] == '4')
	{
		cur->cx = -0.4;
		cur->cy = 0.6;
	}
	if (argv[1][5] == '5')
	{
		cur->cx = -0.8;
		cur->cy = 0;
	}
}

void	ft_select(t_mlx *cur, int argc, char **argv)
{
	if (argc <= 1 || argc >= 3)
	{
		if (argc >= 3)
			ft_printf("Too many arguments !\n");
		print_msg(cur);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
	{
		cur->cur_fract = 'm';
		cur->title = "Mandelbrot's Set";
		ft_fractal(cur);
	}
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		cur->cur_fract = 'j';
		cur->title = "Julia's Set";
		get_julia_num(cur, argv);
		ft_fractal(cur);
	}
	else
		print_msg(cur);
}

int	main(int argc, char **argv)
{
	t_mlx	cur;

	cur.zoom = 1;
	cur.offset_x = 0;
	cur.offset_y = 0;
	cur.w_size = 1000;
	cur.cx = 0;
	cur.cy = -0.75;
	cur.color_a = 0x000000;
	cur.color_b = 0x1010EE;
	cur.iteration = 100;
	cur.win = NULL;
	cur.mlx = mlx_init(&cur);
	ft_select(&cur, argc, argv);
	mlx_events(&cur);
	mlx_loop(cur.mlx);
}
