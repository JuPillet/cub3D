/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mallocers_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:26:04 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/09 22:26:40 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_malloc_map_columns(t_parser *parser, t_game *game)
{
	int		tabulation;
	char	*line;
	int		indln;
	int		columns;

	line = parser->line;
	indln = parser->indln;
	columns = 0;
	while (line[indln])
	{
		if (line[indln] != ' ' && line[indln] != '\t' && line[indln] != '0'
			&& line[indln] != '1' && line[indln] != '2' && !line[indln] != 'N'
			&& line[indln] != 'S' && line[indln] != 'E' && line[indln] != 'W')
			return (FALSE);
		if (line[indln++] == '\t')
			columns += (4 - (columns % 4));  
		else
			columns++;
	}
	if (!ft_malloc_char(columns + 1, game))
		return (cub_free_fd("program didn't find memory to load", 0, parser));
	cub_set_map_columns(line, linemap);
	return (TRUE);
}

t_bool	cub_malloc_map_lines(t_parser *parser, t_game *game, int malloc_lines)
{
	if (!cub_check_after_map(parser))
		return (cub_free_fd("the setting file has non white space \
line after his declaration", 0, parser));
	game->level->area->map = (char **)malloc(
		(malloc_lines + 1) * sizeof(char *));
	if (!(game->level->area->map))
		return (cub_free_fd("insufficient memory to initiate cub3D", 0, parser));
	if (!ft_malloc_int(malloc_lines + 1, &(game->level->area->lines_length)))
		return (cub_free_fd("program didn't find memory to load", 0, parser));
	close(parser->fd);
	free(parser->line);
	if (!cub_malloc_map_columns(parser, game))
		return (FALSE);
}

t_bool	cub_malloc_area(t_area **area)
{
	*area = (t_area *)malloc(sizeof(t_area));
	if (!(*area))
		return(ft_error("insufficient memory to initiate cub3D", 0));
	(*area)->lines_length = 0;
	(*area)->map = 0;
	return (TRUE);
}