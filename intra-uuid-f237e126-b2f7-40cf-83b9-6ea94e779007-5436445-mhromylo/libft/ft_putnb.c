/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:57:58 by mhromylo          #+#    #+#             */
/*   Updated: 2023/12/01 16:25:22 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnb(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		i += ft_putstr_counter("-2147483648");
	else if (nb < 0)
	{
		i += ft_putchar_count('-');
		nb = -nb;
		i += ft_putnb(nb);
	}
	else
	{
		if (nb >= 10)
		{
			i += ft_putnb(nb / 10);
			i += ft_putnb(nb % 10);
		}
		else
			i += ft_putchar_count(nb + '0');
	}
	return (i);
}
