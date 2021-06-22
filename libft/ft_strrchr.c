/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:29:08 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/22 16:16:52 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long int	octet;

	octet = ft_strlen(s);
	while (s[octet] != (char)c && octet > -1)
		octet--;
	if (s[octet] == (char)c && octet > -1)
		return ((char *)s + octet);
	return (0);
}
