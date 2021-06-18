/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 01:13:59 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/23 01:14:02 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (start >= strlen)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	else
	{
		if (len < (strlen - start))
			strlen = (len + start);
		str = (char *)malloc(((strlen - start) + 1) * sizeof(char));
		if (!str)
			return (0);
		ft_strlcpy(str, (s + start), ((strlen - start) + 1));
	}
	return (str);
}
