/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:16:27 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/28 18:20:10 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_parser_map(t_parser *parser, t_game *game)
{
	int		malloc_lines;
	t_bool	loop;

	malloc_lines = 0;
	loop == TRUE;
	if (!cub_check_before_map(game))
		return (cub_free_fd("the setting file hasn't all prerequisite before \
map", 0, parser));
	while (parser->eof == 1 && loop)
	{
		parser->indln = 0;
		while (parser->line[parser->indln] == ' '
			|| parser->line[parser->indln] == '\t')
			(parser->indln)++;
		if (!parser->line[parser->indln])
			loop = FALSE;
		else if (!cub_check_map(game->level->area))
			return (FALSE);
	}
	if (!cub_malloc_map_lines(parser, game, malloc_lines))
		return (FALSE);
}