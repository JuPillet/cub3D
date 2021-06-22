/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:14:47 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/20 13:14:49 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	*hstk;
	unsigned char	*ndl;
	size_t			ndllen;
	size_t			hstind;

	hstk = (unsigned char *)haystack;
	ndl = (unsigned char *)needle;
	hstind = 0;
	ndllen = ft_strlen(needle);
	if (!(ndl[0]))
		return ((char *)haystack);
	while (hstk[hstind] && (hstind + ndllen) <= len)
	{
		if (!(ft_strncmp((char *)hstk + hstind, (char *)ndl, ndllen)))
			return ((char *)hstk + hstind);
		hstind++;
	}
	return (NULL);
}
