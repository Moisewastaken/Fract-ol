/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:50:49 by mcochin           #+#    #+#             */
/*   Updated: 2022/07/16 18:44:19 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

void	get_palette(t_mlx *cur)
{
	cur->palette_num++;
	if (cur->palette_num >= 7)
		cur->palette_num = 0;
	if (cur->palette_num == 0)
		cur->cur_palette = red_palette;
	if (cur->palette_num == 1)
		cur->cur_palette = green_palette;
	if (cur->palette_num == 2)
		cur->cur_palette = blue_palette;
	if (cur->palette_num == 3)
		cur->cur_palette = trippy_palette;
	if (cur->palette_num == 4)
		cur->cur_palette = pastel_palette;
	if (cur->palette_num == 5)
		cur->cur_palette = pastel2_palette;
	if (cur->palette_num == 6)
		cur->cur_palette = blacknwhite_palette;
}

int	red_palette(int iter)
{
	int	palette[21];

	palette[0] = 0x000000;
	palette[1] = 0x170000;
	palette[2] = 0x260000;
	palette[3] = 0x3b0000;
	palette[4] = 0x4d0000;
	palette[5] = 0x5c0000;
	palette[6] = 0x700000;
	palette[7] = 0x800000;
	palette[8] = 0x900000;
	palette[9] = 0x820000;
	palette[10] = 0x910000;
	palette[11] = 0x990000;
	palette[12] = 0xa20000;
	palette[13] = 0xa70000;
	palette[14] = 0xb20000;
	palette[15] = 0xb80000;
	palette[16] = 0xc100000;
	palette[17] = 0xc50000;
	palette[18] = 0xd10000;
	palette[19] = 0xd90000;
	palette[20] = 0xeb0000;
	palette[21] = 0xff0000;
	return (palette[iter % 21]);
}

int	blue_palette(int iter)
{
	int	palette[21];

	palette[0] = 0x01b2e8;
	palette[1] = 0x02a5df;
	palette[2] = 0x0299d7;
	palette[3] = 0x0389cc;
	palette[4] = 0x0380c6;
	palette[5] = 0x0474be;
	palette[6] = 0x0564b3;
	palette[7] = 0x0657ab;
	palette[8] = 0x074aa3;
	palette[9] = 0x07419d;
	palette[10] = 0x073897;
	palette[11] = 0x082289;
	palette[12] = 0x090979;
	palette[13] = 0x070768;
	palette[14] = 0x060659;
	palette[15] = 0x060552;
	palette[16] = 0x07064a;
	palette[17] = 0x040341;
	palette[18] = 0x030235;
	palette[19] = 0x030130;
	palette[20] = 0x020024;
	palette[21] = 0x01000e;
	return (palette[iter % 21]);
}

int	green_palette(int iter)
{
	int	palette[21];

	palette[0] = 0x1ae000;
	palette[1] = 0x14e61e;
	palette[2] = 0x13e826;
	palette[3] = 0x12e92d;
	palette[4] = 0x11eb35;
	palette[5] = 0x10ec3b;
	palette[6] = 0x0fed41;
	palette[7] = 0x0eee45;
	palette[8] = 0x0def49;
	palette[9] = 0x0cf150;
	palette[10] = 0x0bf254;
	palette[11] = 0x0af35a;
	palette[12] = 0x09f460;
	palette[13] = 0x08f566;
	palette[14] = 0x07f66c;
	palette[15] = 0x06f772;
	palette[16] = 0x05f878;
	palette[17] = 0x04fa7f;
	palette[18] = 0x03fb86;
	palette[19] = 0x01fd8f;
	palette[20] = 0x00ff97;
	palette[21] = 0x12fa9b;
	return (palette[iter % 21]);
}

int	trippy_palette(int iter)
{
	int	palette[21];

	palette[0] = 0xf51010;
	palette[1] = 0xff2700;
	palette[2] = 0xfb5903;
	palette[3] = 0xfa9304;
	palette[4] = 0xf8d205;
	palette[5] = 0xa7f706;
	palette[6] = 0x83f607;
	palette[7] = 0x55f508;
	palette[8] = 0x17f409;
	palette[9] = 0x0af350;
	palette[10] = 0x0bf27d;
	palette[11] = 0x0cf1aa;
	palette[12] = 0x0cf1dc;
	palette[13] = 0x0dcbef;
	palette[14] = 0x0e76ee;
	palette[15] = 0x0f70ed;
	palette[16] = 0x1043ec;
	palette[17] = 0x2711eb;
	palette[18] = 0x3412e9;
	palette[19] = 0x6f13e8;
	palette[20] = 0x9514e6;
	palette[21] = 0xce00e0;
	return (palette[iter % 21]);
}
