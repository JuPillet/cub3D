/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:01:29 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/19 15:01:31 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	octet;

	octet = -1;
	while (s[++octet] || (char)c == '\0')
		if (s[octet] == (char)c)
			return ((char *)s + octet);
	return (0);
}
