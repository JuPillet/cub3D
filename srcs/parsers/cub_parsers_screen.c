/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsers_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 21:40:40 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 17:35:51 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_parse_color(t_parser *parser, t_horizon *horizon)
{
	t_color	*color;

	color = horizon->color;
	if (!cub_set_int(parser->line, &(parser->indln), color->r))
		return (FALSE);
	if (parser->line[(parser->indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(parser->line[parser->indln]))
		return (FALSE);
	if (!cub_set_int(parser->line, &(parser->indln), color->g))
		return (FALSE);
	if (parser->line[(parser->indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(parser->line[parser->indln]))
		return (FALSE);
	if (!cub_set_int(parser->line, &(parser->indln), color->b))
		return (FALSE);
	if (*(color->r) < 0 || *(color->r) > 255 || *(color->g) < 0
		|| *(color->g) > 255 || *(color->b) < 0 || *(color->b) > 255)
		return (FALSE);
	*(color->argb) = cub_set_argb(*(color->a), *(color->r),
		*(color->g), *(color->b));
	return(TRUE);
}

t_bool	cub_parse_resolution(t_parser *parser, t_game *game)
{
	t_resolution *resolution;

	resolution = game->screen->resolution;
	if (*(resolution->is))
		return (ft_error("the setting file has two or more declared \
resolution lines, you must need only one", parser->line));
	if (!cub_set_int(parser->line, &(parser->indln), resolution->width))
		return (ft_error("incorrect resolution width line format",
				parser->line));
	if (!ft_isspace(parser->line[(parser->indln)++]))
		return (ft_error("incorrect resolution line format", parser->line));
	if (!cub_set_int(parser->line, &(parser->indln), resolution->height))
		return (ft_error("incorrect resolution height line format",
				parser->line));
	while (parser->line[parser->indln])
		if (!ft_isspace(parser->line[(parser->indln)++]))
			return (ft_error("incorrect resolution line format",
					parser->line));
	return(cub_set_resolution(parser->line, game->mlx, game->screen));
}
