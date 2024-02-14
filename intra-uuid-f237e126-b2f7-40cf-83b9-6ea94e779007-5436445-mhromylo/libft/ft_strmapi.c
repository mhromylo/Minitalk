/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhromylo <mhromylo@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:15:52 by mhromylo          #+#    #+#             */
/*   Updated: 2023/11/17 14:29:33 by mhromylo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	fstr = (char *)malloc (sizeof(char) * ft_strlen(s) +1);
	if (!fstr)
		return (NULL);
	while (s[i])
	{
		fstr[i] = f(i, s[i]);
		i++;
	}
	fstr[i] = '\0';
	return (fstr);
}
