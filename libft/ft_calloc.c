/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:18:28 by jpillet           #+#    #+#             */
/*   Updated: 2021/01/20 15:18:31 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*newcal;

	newcal = malloc(count * size);
	if (!(newcal))
		return (0);
	ft_memset(newcal, 0, (count * size));
	return (newcal);
}
