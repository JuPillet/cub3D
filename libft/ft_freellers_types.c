/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freellers_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 23:29:34 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/22 16:18:40 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_free_char(char **ptr)
{
	if (!(*ptr))
		return (FALSE);
	free(*ptr);
	*ptr = 0;
	return (TRUE);
}

t_bool	ft_free_int(int **ptr)
{
	if (!(*ptr))
		return (FALSE);
	free(*ptr);
	*ptr = 0;
	return (TRUE);
}

t_bool	ft_free_float(float **ptr)
{
	if (!(*ptr))
		return (FALSE);
	free(*ptr);
	*ptr = 0;
	return (TRUE);
}

t_bool	ft_free_double(double **ptr)
{
	if (!(*ptr))
		return (FALSE);
	free(*ptr);
	*ptr = 0;
	return (TRUE);
}

t_bool	ft_free_t_bool(t_bool **ptr)
{
	if (!(*ptr))
		return (FALSE);
	free(*ptr);
	*ptr = 0;
	return (TRUE);
}
