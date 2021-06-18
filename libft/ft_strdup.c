/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:18:51 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/20 15:18:54 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned long int	len;
	char				*strdup;

	len = ft_strlen(s1);
	strdup = malloc((len + 1) * sizeof(char));
	if (!strdup)
		return (0);
	strdup[len] = '\0';
	while (len--)
		(strdup[len] = s1[len]);
	return (strdup);
}
