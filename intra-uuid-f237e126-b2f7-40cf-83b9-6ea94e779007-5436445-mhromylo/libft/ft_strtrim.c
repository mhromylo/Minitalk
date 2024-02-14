/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:06:19 by mhromylo          #+#    #+#             */
/*   Updated: 2023/11/16 17:20:42 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charfind(char c, char const *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	begin;
	size_t	end;

	begin = 0;
	while (s1[begin] && ft_charfind(s1[begin], set))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_charfind(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - begin + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (begin < end)
		str[i++] = s1[begin++];
	str[i] = 0;
	return (str);
}
