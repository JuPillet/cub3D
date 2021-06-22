/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:37:00 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/18 14:37:03 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*sour;
	unsigned char	*dest;

	i = -1;
	sour = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (++i < n)
	{
		dest[i] = sour[i];
		if (sour[i] == (unsigned char)c)
			return (dest + i + 1);
	}
	return (0);
}
