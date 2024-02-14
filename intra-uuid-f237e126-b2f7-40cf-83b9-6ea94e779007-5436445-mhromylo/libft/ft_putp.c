/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:03:58 by mhromylo          #+#    #+#             */
/*   Updated: 2023/12/01 14:46:40 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(uintptr_t nb)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		i += ft_putp(nb / 16);
		i += ft_putp(nb % 16);
	}
	else
		i += ft_putchar_count(base[nb]);
	return (i);
}
