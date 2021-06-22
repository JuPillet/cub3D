/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:28:58 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/19 11:29:01 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			octet;
	unsigned char	*str;

	octet = 0;
	str = (unsigned char *)s;
	while (octet < n)
	{
		if (str[octet] == (unsigned char)c)
			return (str + octet);
		octet++;
	}
	return (NULL);
}
