/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsers_informs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:40:40 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/17 22:56:46 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "miniRT.h"

t_bool	mini_parse_resolution(char *line, int *indln, t_pov *pov)
{
	t_resolution *resolution;

	resolution = pov->screen->resolution;
	if (*(resolution->is))
		return (ft_error("the setting file has two or more declared \
resolution lines, you must need only one", line));
	if (!mini_set_int(line, indln, resolution->x))
		return (ft_error("incorrect resolution width line format", line));
	if (!ft_isspace(line[(*indln)++]))
		return (ft_error("incorrect resolution line format", line));
	if (!mini_set_int(line, indln, resolution->y))
		return (ft_error("incorrect resolution height line format", line));
	while (line[*indln])
		if (!ft_isspace(line[(*indln)++]))
			return (ft_error("incorrect resolution line format", line));
	if (*(resolution->x) < 256	|| *(resolution->y) < 144)
		return (ft_error("resolution format to small, minimum format :\n\
- width : 256\n- height 144", line));
	mini_set_screen(pov->screen);
	*(resolution->is) = TRUE;
	return (TRUE);
}

t_bool	mini_parse_camera(char *line, int *indln, t_camera *camera)
{
	if (!mini_parse_coord(line, indln, camera->coord))
		return (ft_error("incorrect camera coordinates format", line));
	if (!ft_isspace(line[*indln]))
		return (ft_error("incorrect camera line format", line));
	if (!mini_parse_coord(line, indln, camera->oriented))
		return (ft_error("incorrect camera orientation format", line));
	if (!ft_isspace(line[*indln]))
		return (ft_error("incorrect camera line format", line));
	if (!mini_parse_fov(line, indln, camera->fov))
		return (ft_error("incorrect camera fov format", line));
	while (line[*indln])
		if (!ft_isspace(line[(*indln)++]))
			return (ft_error("incorrect camera line format", line));
	if (!mini_check_orientation(camera->oriented))
		return (ft_error("camera orientation incorrect values :\n\
- minimum : -1.0\n- maximum : 1.0", line));

	return (TRUE);
}

t_bool	mini_parse_light(char *line, int *indln, t_light *light)
{
	if (!mini_parse_coord(line, indln, light->coord))
		return (ft_error("incorrect light coordinates format", line));
	if (!mini_set_double(line, indln, light->intensity))
		return (ft_error("incorrect light intensity format", line));
	if (!mini_parse_color(line, indln, light->color))
		return (ft_error("incorrect light color format", line));
	while (line[(*indln)])
		if (!ft_isspace(line[(*indln)++]))
			return (ft_error("incorrect light line format", line));
	if (*(light->intensity) < 0 && *(light->intensity) > 1)
		return (ft_error("light intensity incorrect value :\n\
- minimum : 0.0\n- maximum : 1.0", line));
	return (TRUE);
}
