/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocers_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:06:42 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 22:48:12 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool ft_malloc_char(int size, char **ptr)
{
	*ptr = (char *)malloc(size * sizeof(char));
	if (!(*ptr))
		return (FALSE);
	while (size--)
		(*ptr)[size] = 0;
	return (TRUE);
}

t_bool ft_malloc_int(int size, int **ptr)
{
	*ptr = (int *)malloc(size * sizeof(int));
	if (!(*ptr))
		return (FALSE);
	while (size--)
		(*ptr)[size] = 0;
	return (TRUE);
}

t_bool ft_malloc_float(int size, float **ptr)
{
	*ptr = (float *)malloc(size * sizeof(float));
	if (!(*ptr))
		return (FALSE);
	while (size--)
		(*ptr)[size] = 0;
	return (TRUE);
}

t_bool ft_malloc_double(int size, double **ptr)
{
	*ptr = (double *)malloc(size * sizeof(double));
	if (!(*ptr))
		return (FALSE);
	while (size--)
		(*ptr)[size] = 0;
	return (TRUE);
}

t_bool ft_malloc_t_bool(int size, t_bool **ptr)
{
	*ptr = (t_bool *)malloc(size * sizeof(t_bool));
	if (!(*ptr))
		return (FALSE);
	while (size--)
		(*ptr)[size] = FALSE;
	return (TRUE);
}
