/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:22:22 by mhromylo          #+#    #+#             */
/*   Updated: 2023/11/24 16:42:48 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nblen(int nb)
{
	size_t	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	ft_numstr(int i, int filed, int nb, char *str)
{
	while (i > filed)
	{
		str[i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		filed;

	filed = 0;
	len = nblen(n);
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		filed = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		filed = 1;
		n = -n;
	}
	ft_numstr(len, filed, n, str);
	str[len] = '\0';
	return (str);
}
