/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsers_informs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:40:40 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/26 23:02:24 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_parse_color(char *line, int *indln, t_color *color)
{
	if (!cub_set_int(line, indln, color->r))
		return (FALSE);
	if (line[(*indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(line[*indln]))
		return (FALSE);
	if (!cub_set_int(line, indln, color->g))
		return (FALSE);
	if (line[(*indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(line[*indln]))
		return (FALSE);
	if (!cub_set_int(line, indln, color->b))
		return (FALSE);
	if (*(color->r) < 0 || *(color->r) > 255 || *(color->g) < 0
		|| *(color->g) > 255 || *(color->b) < 0 || *(color->b) > 255)
		return (FALSE);
	*(color->argb) = cub_set_argb(*(color->a), *(color->r),
		*(color->g), *(color->b));
	return(TRUE);
}

t_bool	cub_parse_resolution(char *line, int *indln, t_game *game)
{
	t_resolution *resolution;

	resolution = game->screen->resolution;
	if (*(resolution->is))
		return (ft_error("the setting file has two or more declared \
resolution lines, you must need only one", line));
	if (!cub_set_int(line, indln, resolution->width))
		return (ft_error("incorrect resolution width line format", line));
	if (!ft_isspace(line[(*indln)++]))
		return (ft_error("incorrect resolution line format", line));
	if (!cub_set_int(line, indln, resolution->height))
		return (ft_error("incorrect resolution height line format", line));
	while (line[*indln])
		if (!ft_isspace(line[(*indln)++]))
			return (ft_error("incorrect resolution line format", line));
	return(cub_set_resolution(line, game->screen));
}
