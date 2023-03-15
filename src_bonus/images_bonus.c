/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:57:48 by mcochin           #+#    #+#             */
/*   Updated: 2022/07/16 18:43:55 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

void	init_img(t_mlx *cur, t_img *img)
{
	img->ptr = mlx_new_image(cur->mlx, cur->w_size, cur->w_size);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->ll, &img->end);
}

void	pxl_to_img(t_img *img, int x, int y, int color)
{	
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
