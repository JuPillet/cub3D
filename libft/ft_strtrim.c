/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:46:20 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/22 21:46:27 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	s1_index0_not_exist(char **str)
{
	*str = (char *)malloc(1 * sizeof(char));
	if (!(*str))
		return (0);
	**str = '\0';
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	strlen;
	size_t	strind;

	if (!s1)
		return (0);
	strlen = ft_strlen(s1);
	strind = 0;
	while (s1[strind] && ft_strchr(set, s1[strind]))
		strind++;
	if (!s1[strind])
	{
		if (!s1_index0_not_exist(&str))
			return (0);
	}
	else
	{
		while (strlen && ft_strrchr(set, s1[(strlen - 1)]))
			strlen--;
		str = (char *)malloc(((strlen - strind) + 1) * sizeof(char));
		if (!str)
			return (0);
		ft_strlcpy(str, (s1 + strind), ((strlen - strind) + 1));
	}
	return (str);
}
