/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:16:27 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/28 18:20:10 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_error_line(char *line)
{
	if (line)
		ft_free_char(&line);
	return (FALSE);
}

t_bool	cub_free_error_map(char **map, char *line, int lines)
{
	while (map[++lines])
		ft_free_char(&(map[lines]));
	return (cub_free_error_line(line));
}

t_bool	cub_parse_map(t_parser *parser, t_game *game,
	const char *file, int lines)
{
	char			*line;

	if (!cub_check_end_map(&(parser->line)))
	{
		line = ft_strdup(parser->line);
		if (!cub_get_setting_line(parser, file))
			return (cub_free_error_line(line));
		else if (!cub_parse_map(parser, game, file, (lines + 1)))
			return (cub_free_error_line(line));
		if (!cub_malloc_map_columns(&line,
				&(game->level.area.map[lines]),
				&(game->level.area.lines_length[lines])))
			return (cub_free_error_map(game->level.area.map, line, lines));
		if (line)
			ft_free_char(&line);
		if (lines == 0)
			return (cub_check_after_map(parser, file));
		return (TRUE);
	}
	return (cub_malloc_map_lines(game, lines));
}
