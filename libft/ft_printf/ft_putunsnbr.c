/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:25:33 by mcochin           #+#    #+#             */
/*   Updated: 2022/04/26 16:56:29 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putunsnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += ft_putunsnbr(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}