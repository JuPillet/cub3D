/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsers_leaves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:33:12 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/17 18:29:33 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "miniRT.h"

t_bool mini_check_orientation(t_coord *orientation)
{
	if (*(orientation->x_coord) < -1 || *(orientation->x_coord) > 1
		|| *(orientation->y_coord) < -1 || *(orientation->y_coord) > 1
		|| *(orientation->z_coord) < -1 || *(orientation->z_coord) > 1)
		return (FALSE);
	return (TRUE);
}

t_bool	mini_parse_coord(char *line, int *indln, t_coord *coord)
{
	if (!mini_set_double(line, indln, coord->x_coord))
		return (FALSE);
	if (line[(*indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(line[*indln])
		&& !(ft_issigned(line[*indln]) && ft_isdigit(line[(*indln) + 1])))
		return (FALSE);
	if (!mini_set_double(line, indln, coord->y_coord))
		return (FALSE);
	if (line[(*indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(line[*indln])
		&& !(ft_issigned(line[*indln]) && ft_isdigit(line[(*indln) + 1])))
		return (FALSE);
	if (!mini_set_double(line, indln, coord->z_coord))
		return (FALSE);
	return (TRUE);
}

t_bool	mini_parse_color(char *line, int *indln, t_color *color)
{
	if (!mini_set_int(line, indln, color->r))
		return (FALSE);
	if (line[(*indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(line[*indln]))
		return (FALSE);
	if (!mini_set_int(line, indln, color->g))
		return (FALSE);
	if (line[(*indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(line[*indln]))
		return (FALSE);
	if (!mini_set_int(line, indln, color->b))
		return (FALSE);
	if (*(color->r) < 0 || *(color->r) > 255 || *(color->g) < 0
		|| *(color->g) > 255 || *(color->b) < 0 || *(color->b) > 255)
		return (FALSE);
	*(color->a) = 0;
	*(color->argb) = mini_set_argb(*(color->a), *(color->r),
		*(color->g), *(color->b));
	return(TRUE);
}

t_bool	mini_parse_fov(char *line, int *indln, t_fov *fov)
{
	if (!mini_set_double(line, indln, fov->radius))
		return (ft_error("bad format, invalid field of view values", line));
	if (*(fov->radius) < 0 || *(fov->radius) > 180)
		return (ft_error("bad format, invalid field of view values", line));
	return (TRUE);
}
