/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:41:10 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/15 22:06:44 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_error(const char *msg, const char *msg2)
{
	printf("Error\n%s", ((char *)msg));
	if (msg2)
		printf(" :\n'%s' file", ((char *)msg2));
	printf(".\n");
	return (FALSE);
}

t_bool	ft_freerror(const char *msg, const char *msg2)
{
	ft_error(msg, msg2);
	free ((char *)msg2);
	return (FALSE);
}

t_bool	ft_memerror(const char *forfree)
{
	free((char *)forfree);
	return (ft_error("insufficient memory", 0));
}