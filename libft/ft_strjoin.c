/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:42:22 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/22 20:42:54 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	strlen;
	size_t	strlen2;

	if (!s1 || !s2)
		return (0);
	strlen = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	strlen += strlen2;
	str = (char *)malloc((strlen + 1) * sizeof(char));
	if (!str)
		return (0);
	str[strlen] = '\0';
	while (strlen2)
		str[--strlen] = ((char *)s2)[--strlen2];
	while (strlen--)
		str[strlen] = ((char *)s1)[strlen];
	return (str);
}
