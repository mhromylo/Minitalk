/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:13:38 by mhromylo          #+#    #+#             */
/*   Updated: 2023/11/15 12:21:27 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*find;

	find = NULL;
	while (*s)
	{
		if (*s == ((char)c))
			find = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)find);
}
