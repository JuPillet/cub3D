/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checkers_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:43:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/22 14:43:13 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_check_after_map(t_parser *parser, const char *file)
{
	t_bool	loop;

	loop = TRUE;
	while (loop && parser->eof == 1)
	{
		loop = cub_get_setting_line(parser, file);
		while (parser->line[parser->indln])
			if (!ft_isspace(parser->line[parser->indln++]))
				return (ft_error("map isn't the last setting \
in the settings file", file));
	}
	if (parser->eof == -1)
		return (ft_error("cub3D failed to read the setting file after \
the map", parser->line));
	return (TRUE);
}

t_bool	cub_check_end_map(char **line)
{
	int	indline;

	indline = 0;
	while ((*line)[indline] == ' ' || (*line)[indline] == '\t')
		indline++;
	if ((*line)[indline])
		return (FALSE);
	ft_free_char(line);
	return (TRUE);
}

t_bool	cub_check_before_map(t_game *game)
{
	if (game->screen.resolution.is && game->level.sp.img
		&& game->level.no.img && game->level.ea.img
		&& game->level.so.img && game->level.we.img
		&& game->level.ceiling.is && game->level.floor.is)
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
