/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocers_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:06:42 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/21 13:17:53 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool ft_malloc_char(int size, char **ptr)
{
	int	clean;

	*ptr = (char *)malloc(size * sizeof(char));
	if (!(*ptr))
		return (FALSE);
	clean = 0;
	while (clean < size)
	{
		(*ptr)[clean] = 0;
		clean++;
	}
	return (TRUE);
}

t_bool ft_malloc_int(int size, int **ptr)
{
	int clean = 0;
	
	*ptr = (int *)malloc(size * sizeof(int));
	if (!(*ptr))
		return (FALSE);
	clean = 0;
	while (clean < size)
	{
		(*ptr)[clean] = 0;
		clean++;
	}
	return (TRUE);
}

t_bool ft_malloc_float(int size, float **ptr)
{
	int clean;

	*ptr = (float *)malloc(size * sizeof(float));
	if (!(*ptr))
		return (FALSE);
	clean = 0;
	while (clean < size)
	{
		(*ptr)[clean] = 0;
		clean++;
	}
	return (TRUE);
}

t_bool ft_malloc_double(int size, double **ptr)
{
	int clean;

	*ptr = (double *)malloc(size * sizeof(double));
	if (!(*ptr))
		return (FALSE);
	clean = 0;
	while (clean < size)
	{
		(*ptr)[clean] = 0;
		clean++;
	}
	return (TRUE);
}

t_bool ft_malloc_t_bool(int size, t_bool **ptr)
{
	int clean;

	*ptr = (t_bool *)malloc(size * sizeof(t_bool));
	if (!(*ptr))
		return (FALSE);
	clean = 0;
	while (clean < size)
	{
		(*ptr)[clean] = FALSE;
		clean++;
	}
	return (TRUE);
}
