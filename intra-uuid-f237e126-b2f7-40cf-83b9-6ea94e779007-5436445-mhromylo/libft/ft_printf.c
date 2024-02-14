/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:57:23 by mhromylo          #+#    #+#             */
/*   Updated: 2023/12/04 11:36:18 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_args(const char *str, void *args)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += ft_putchar_count((int)args);
	else if (*str == 's')
		i += ft_putstr_counter((char *)args);
	else if (*str == 'p')
		i += ft_putstr_counter("0x") + ft_putp((unsigned long)args);
	else if (*str == 'd' || *str == 'i')
		i += ft_putnb((int)args);
	else if (*str == 'u')
		i += ft_putnbu((unsigned int)args);
	else if (*str == 'x' || *str == 'X')
		i += ft_puthex((unsigned int)args, *str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				i += ft_putchar_count(*str);
			else
				i += ft_print_args(str, va_arg(args, void *));
			str++;
		}
		else
		{
			i += ft_putchar_count(*str);
			str++;
		}
	}
	va_end(args);
	return (i);
}
