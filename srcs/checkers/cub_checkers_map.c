/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checkers_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:43:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 23:55:55 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_check_after_map(t_parser *parser)
{
	t_bool	loop;

	loop = TRUE;
	while (parser->eof != -1 && (parser->eof == 1 || loop))
	{
		while (parser->line[parser->indln])
			if (!ft_isspace(parser->line[(parser->indln)++]))
				return (FALSE);
		if (parser->line)
			free(parser->line);
		parser->line = 0;
		parser->indln = 0;
		if (parser->eof)
			parser->eof = get_next_line(parser->fd, &(parser->line));
		else
			loop = FALSE;
	}
	if (parser->eof == -1)
		return (cub_free_parser("cub3D failed to read the setting file after \
		the map", 0, parser));
	return (TRUE);
}

t_bool	cub_check_end_map(t_parser *parser)
{
	char *line_map;
	int indline;
	
	line_map = parser->line_map;
	indline = 0;
	while (line_map[indline] == ' ' || line_map[indline] == '\t')
		indline++;
	if (!line_map[indline])
		return (TRUE);
	return (FALSE);
}

t_bool	cub_check_before_map(t_game *game)
{
	if (*(game->screen->resolution->is) && game->level->no
		&& game->level->so && game->level->we
		&& game->level->ea && game->level->floor
		&& *(game->level->ceiling->is) && *(game->level->floor->is))
		return (TRUE);
	return (FALSE);
}

t_bool	cub_check_start_map(char *line, int indln)
{
	if (line[indln] == '0' || line[indln] == '1' || line[indln] == '2'
		|| (line[indln] == 'N' && (line[indln + 1] == '0'
				|| line[indln + 1] == '1' || line[indln + 1] == '2'))
		|| (line[indln] == 'E' && (line[indln + 1] == '0'
				|| line[indln + 1] == '1' || line[indln + 1] == '2'))
		|| (line[indln] == 'S' && (line[indln + 1] == '0'
				|| line[indln + 1] == '1' || line[indln + 1] == '2'))
		|| (line[indln] == 'W' && (line[indln + 1] == '0'
				|| line[indln + 1] == '1' || line[indln + 1] == '2')))
		return (TRUE);
	return (FALSE);
}
