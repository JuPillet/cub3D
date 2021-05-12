/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mallocers_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:26:04 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/13 00:01:52 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_malloc_map_columns(t_parser *parser, char **line_map, int *columns)
{
	int		tabulation;
	char	*line;
	int		indln;

	line = parser->line_map;
	indln = parser->indln;
	while (line[indln])
	{
		if (line[indln] != ' ' && line[indln] != '\t' && line[indln] != '0'
			&& line[indln] != '1' && line[indln] != '2' && line[indln] != 'N'
			&& line[indln] != 'S' && line[indln] != 'E' && line[indln] != 'W')
			return (cub_free_parser("cub3D stopped working because invalid characte\
r is in the map", line, parser));
		if (line[indln++] == '\t')
			(*columns) += (4 - (*columns) % 4);
		else
			(*columns)++;
	}
	if (!ft_malloc_char((*columns) + 1, line_map))
		return (cub_free_parser("program didn't find memory to load", 0, parser));
	cub_set_map_columns(line, line_map);
	return (TRUE);
}

t_bool	cub_malloc_map_lines(t_parser *parser, t_game *game,
	int malloc_lines, const char *file)
{
	int		indclmn;
	char	**map;
	int		*lines_length;

	map = (char **)malloc((malloc_lines + 1) * sizeof(char *));
	if (!(map))
		return (cub_free_parser("program didn't find memory to load", 0, parser));
	if (!ft_malloc_int(malloc_lines + 1, &lines_length))
		return (cub_free_parser("program didn't find memory to load", 0, parser));
	indclmn = 0;
	while (malloc_lines--)
	{
		if (cub_malloc_map_columns(parser, &(map[indclmn]), (lines_length + indclmn))
			&& cub_get_setting_line(parser, file) != -1)
			indclmn++;
		else
			return (FALSE);
	}
	game->level->area->map = map;
	game->level->area->lines_length = lines_length;
	if (!cub_check_after_map(parser))
		return (cub_free_parser("the setting file has non white space \
line after his declaration", 0, parser));
	return (cub_check_map(game->level));
}

t_bool	cub_malloc_area(t_area **area)
{
	*area = (t_area *)malloc(sizeof(t_area));
	if (!(*area))
		return(ft_error("program didn't find memory to load", 0));
	(*area)->lines_length = 0;
	(*area)->map = 0;
	return (TRUE);
}