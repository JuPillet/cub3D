/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:16:27 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/27 14:06:20 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

static t_bool	cub_parser_map(t_parser *parser, t_game *game)
{
	int		malloc_line;
	t_bool	loop;

	malloc_line = 0;
	loop == TRUE;
	if (!cub_check_before_map(game))
		return (cub_free_fd("the setting file hasn't all prerequisite before \
map", parser));
	while (parser->eof == 1 && loop)
	{
		parser->indln = 0;
		while (parser->line[parser->indln] == ' '
			|| parser->line[parser->indln] == '\t')
			(parser->indln)++;
		if (!parser->line[parser->indln])
			loop = FALSE;
		else if (!cub_check_map(&malloc_line, parser))
			return (FALSE);
	}
	if (!cub_malloc_map_lines(malloc_line, game->level->area->map))
		return (FALSE);
}