/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:50:49 by mcochin           #+#    #+#             */
/*   Updated: 2022/07/16 15:33:40 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

int	pastel_palette(int iter)
{
	int	palette[21];

	palette[0] = 0xf7a1a1;
	palette[1] = 0xf79ea4;
	palette[2] = 0xf69ca6;
	palette[3] = 0xf69aaa;
	palette[4] = 0xf497ad;
	palette[5] = 0xf395b0;
	palette[6] = 0xf193b4;
	palette[7] = 0xee92b8;
	palette[8] = 0xeb90bc;
	palette[9] = 0xe78fc0;
	palette[10] = 0xe38ec5;
	palette[11] = 0xdf8ec9;
	palette[12] = 0xd98dcd;
	palette[13] = 0xd48dd1;
	palette[14] = 0xcd8dd5;
	palette[15] = 0xc68dd9;
	palette[16] = 0xbe8edd;
	palette[17] = 0xb68ee1;
	palette[18] = 0xac8fe4;
	palette[19] = 0xa290e8;
	palette[20] = 0x9791ea;
	palette[21] = 0x8b92ed;
	return (palette[iter % 21]);
}

int	pastel2_palette(int iter)
{
	int	palette[21];

	palette[0] = 0xa1f7e6;
	palette[1] = 0xa1f7e3;
	palette[2] = 0xa1f8df;
	palette[3] = 0xa2f8db;
	palette[4] = 0xa4f8d7;
	palette[5] = 0xa5f8d3;
	palette[6] = 0xa7f8ce;
	palette[7] = 0xaaf8ca;
	palette[8] = 0xadf7c5;
	palette[9] = 0xb0f7c1;
	palette[10] = 0xb3f7bc;
	palette[11] = 0xb7f6b7;
	palette[12] = 0xbbf6b2;
	palette[13] = 0xbff5ae;
	palette[14] = 0xc3f5a9;
	palette[15] = 0xc8f4a4;
	palette[16] = 0xcdf3a0;
	palette[17] = 0xd2f29b;
	palette[18] = 0xd7f197;
	palette[19] = 0xdcf093;
	palette[20] = 0xe2ee8f;
	palette[21] = 0xe7ed8b;
	return (palette[iter % 21]);
}

int	blacknwhite_palette(int iter)
{
	int	palette[21];

	palette[0] = 0xffffff;
	palette[1] = 0xffffff;
	palette[2] = 0xe4e4e4;
	palette[3] = 0xd6d6d6;
	palette[4] = 0xc9c9c9;
	palette[5] = 0xbcbcbc;
	palette[6] = 0xafafaf;
	palette[7] = 0xa2a2a2;
	palette[8] = 0x969696;
	palette[9] = 0x898989;
	palette[10] = 0x7d7d7d;
	palette[11] = 0x717171;
	palette[12] = 0x656565;
	palette[13] = 0x5a5a5a;
	palette[14] = 0x4e4e4e;
	palette[15] = 0x434343;
	palette[16] = 0x393939;
	palette[17] = 0x2e2e2e;
	palette[18] = 0x242424;
	palette[19] = 0x1b1b1b;
	palette[20] = 0x101010;
	palette[21] = 0x000000;
	return (palette[iter % 21]);
}
