/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsers_screen_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:40:40 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/22 16:57:54 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"
t_bool	cub_next_color_value(t_parser *parser)
{
	while (parser->line[(parser->indln)] == ' '
		|| parser->line[(parser->indln)] == '	')
		parser->indln++;
	if (parser->line[(parser->indln)++] != ',')
		return (FALSE);
	return (TRUE);
}

t_bool	cub_parse_color(t_parser *parser, t_color *color)
{
	if (!cub_set_int(parser->line, &(parser->indln), &(color->r)))
		return (FALSE);
	if (!cub_next_color_value(parser))
		return (FALSE);
	if (!cub_set_int(parser->line, &(parser->indln), &(color->g)))
		return (FALSE);
	if (!cub_next_color_value(parser))
		return (FALSE);
	if (!cub_set_int(parser->line, &(parser->indln), &(color->b)))
		return (FALSE);
	while (ft_isspace(parser->line[(parser->indln)]))
		parser->indln++;
	if (parser->line[(parser->indln)])
		return (FALSE);
	if (color->r < 0 || color->r > 255 || color->g < 0
		|| color->g > 255 || color->b < 0 || color->b > 255)
		return (FALSE);
	color->argb = cub_set_argb(color->a, color->r, color->g, color->b);
	return (TRUE);
}

t_bool	cub_parse_resolution(t_parser *parser, t_game *game)
{
	t_resolution	*resolution;

	resolution = &(game->screen.resolution);
	if (resolution->is)
		return (ft_error("the setting file has two or more declared \
resolution lines, you must need only one", parser->line));
	if (!cub_set_int(parser->line, &(parser->indln), &(resolution->width)))
		return (ft_error("incorrect resolution width line format",
				parser->line));
	if (!ft_isspace(parser->line[(parser->indln)++]))
		return (ft_error("incorrect resolution line format", parser->line));
	if (!cub_set_int(parser->line, &(parser->indln), &(resolution->height)))
		return (ft_error("incorrect resolution height line format",
				parser->line));
	while (parser->line[parser->indln])
		if (!ft_isspace(parser->line[(parser->indln)++]))
			return (ft_error("incorrect resolution line format",
					parser->line));
	return (cub_set_resolution(&(game->deg), parser->line, resolution));
}
