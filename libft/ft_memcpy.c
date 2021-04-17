/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:27:32 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/18 14:27:35 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	octet;

	octet = 0;
	if ((!dst && !src) && n)
		return (NULL);
	while (octet < n)
	{
		((unsigned char *)dst)[octet] = ((unsigned char *)src)[octet];
		octet++;
	}
	return (dst);
}
