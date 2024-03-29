/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:11:53 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/19 14:12:17 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= ' ' && c <= '\'') || (c >= '(' && c <= '/')
		|| (c >= '0' && c <= '?') || (c >= '@' && c <= '_')
		|| (c >= '`' && c <= '~'))
		return (1);
	return (0);
}
