/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsers_informs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:40:40 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/20 14:13:58 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

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
	if (*(resolution->width) < 256	|| *(resolution->height) < 144)
		return (ft_error("resolution format to small, cubmum format :\n\
- width : 256\n- height 144", line));
	cub_set_screen(pov->screen);
	*(resolution->is) = TRUE;
	return (TRUE);
}
