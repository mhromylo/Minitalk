/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:20:40 by mhromylo          #+#    #+#             */
/*   Updated: 2023/12/01 15:46:00 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbu(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
	{
		i += ft_putnbu(nb / 10);
		i += ft_putnbu(nb % 10);
	}
	else
		i += ft_putchar_count(nb + '0');
	return (i);
}
