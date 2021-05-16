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

t_bool	cub_parse_map(t_parser *parser, t_game *game, const char *file, int lines)
{
	char			*line;
	t_bool			check;

	check = TRUE;
	line = ft_strdup(parser->line);
	check = cub_get_setting_line(parser, file);
	if (check && parser->eof == 1 && !(cub_check_end_map(line)))
		check = cub_parse_map(parser, game, file, (lines + 1));
	else if (check)
		return(cub_malloc_map_lines(game, &line, lines));
	if (check)
		check = cub_malloc_map_columns(line,
				&(game->level.area.map[lines]),
				&(game->level.area.lines_length[lines]));
	if (line)
		ft_free_char(&line);
	if (check && lines == 0)
		check = cub_check_after_map(parser, file);
	if (!check)
		while (game->level.area.map[++lines])
			ft_free_char(&(game->level.area.map[lines]));
	return (check);
}
