/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:15:48 by mhromylo          #+#    #+#             */
/*   Updated: 2023/11/23 17:20:07 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c1;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	c1 = malloc(sizeof(char) * (i + 1));
	if (!(c1))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		c1[i] = s1[i];
		i++;
	}
	c1[i] = '\0';
	return (c1);
}
