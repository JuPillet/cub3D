/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_adders_2ds_primitives.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:26:22 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/15 13:30:35 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "miniRT.h"

t_bool	mini_adder_plane(char *line, int *indln, t_pov *pov)
{
	t_plane	*new_plane;

	if (!mini_malloc_plane(&new_plane))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->plane)
	{
		pov->scene->plane = new_plane;
		new_plane->p_plane = new_plane;
		new_plane->n_plane = new_plane;
	}
	else
	{
		new_plane->p_plane = pov->scene->plane->p_plane;
		new_plane->n_plane = pov->scene->plane;
		new_plane->p_plane->n_plane = new_plane;
		pov->scene->plane->p_plane = new_plane;
	}
	if (mini_parse_plane(line, indln, new_plane))
		return (TRUE);
	return (FALSE);
}

t_bool	mini_adder_triangle(char *line, int *indln, t_pov *pov)
{
	t_triangle	*new_triangle;

	if (!mini_malloc_triangle(&new_triangle))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->triangle)
	{
		pov->scene->triangle = new_triangle;
		new_triangle->p_triangle = new_triangle;
		new_triangle->n_triangle = new_triangle;
	}
	else
	{
		new_triangle->p_triangle = pov->scene->triangle->p_triangle;
		new_triangle->n_triangle = pov->scene->triangle;
		new_triangle->p_triangle->n_triangle = new_triangle;
		pov->scene->triangle->p_triangle = new_triangle;
	}
	if (mini_parse_triangle(line, indln, new_triangle))
		return (TRUE);
	return (FALSE);
}

t_bool	mini_adder_parallelogram(char *line, int *indln, t_pov *pov)
{
	t_parallelogram	*new_parallelogram;

	if (!mini_malloc_parallelogram(&new_parallelogram))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->parallelogram)
	{
		pov->scene->parallelogram = new_parallelogram;
		new_parallelogram->p_parallelogram = new_parallelogram;
		new_parallelogram->n_parallelogram = new_parallelogram;
	}
	else
	{
		new_parallelogram->p_parallelogram = pov->scene->parallelogram->p_parallelogram;
		new_parallelogram->n_parallelogram = pov->scene->parallelogram;
		new_parallelogram->p_parallelogram->n_parallelogram = new_parallelogram;
		pov->scene->parallelogram->p_parallelogram = new_parallelogram;
	}
	if (mini_parse_parallelogram(line, indln, new_parallelogram))
		return (TRUE);
	return (FALSE);
}

t_bool	mini_adder_square(char *line, int *indln, t_pov *pov)
{
	t_square	*new_square;

	if (!mini_malloc_square(&new_square))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->square)
	{
		pov->scene->square = new_square;
		new_square->p_square = new_square;
		new_square->n_square = new_square;
	}
	else
	{
		new_square->p_square = pov->scene->square->p_square;
		new_square->n_square = pov->scene->square;
		new_square->p_square->n_square = new_square;
		pov->scene->square->p_square = new_square;
	}
	if (mini_parse_square(line, indln, new_square))
		return (TRUE);
	return (FALSE);
}
