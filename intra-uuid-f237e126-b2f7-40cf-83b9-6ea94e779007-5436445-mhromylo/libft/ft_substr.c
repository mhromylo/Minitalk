/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:02:39 by mhromylo          #+#    #+#             */
/*   Updated: 2023/11/28 12:01:41 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	if (start < ft_strlen(s))
	{
		str = (char *)malloc((len +1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, (s + start), (len + 1));
		return (str);
	}
	else
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	return (NULL);
}
