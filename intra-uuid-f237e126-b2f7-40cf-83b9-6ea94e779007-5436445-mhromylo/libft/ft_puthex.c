/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:34:33 by mhromylo          #+#    #+#             */
/*   Updated: 2023/12/01 15:40:05 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, char str)
{
	char	*base;
	int		i;

	i = 0;
	if (str == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		i += ft_puthex(nb / 16, str);
		i += ft_puthex(nb % 16, str);
	}
	else
		i += ft_putchar_count(base[nb]);
	return (i);
}
