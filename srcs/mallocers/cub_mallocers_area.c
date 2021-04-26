/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mallocers_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:26:04 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/26 22:43:37 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_malloc_map_columns(char *line, int indln, int column, char *linemap)
{
	int	tabulation;

	while (line[indln])
	{
		if (line[indln] != ' ' && line[indln] != '\t' && line[indln] != '0'
			&& line[indln] != '1' && line[indln] != '2' && !line[indln] != 'N'
			&& line[indln] != 'S' && line[indln] != 'E' && line[indln] != 'W')
			return (FALSE);
		if (line[indln++] == '\t')
			column += (4 - (column % 4));
		else
			column++;
	}
	if (!ft_malloc_char(column + 1, &linemap))
		return (cub_free_fd("program didn't find memory to load", 0));
	cub_set_map_column(line, linemap);
	return (TRUE);
}

t_bool	cub_malloc_map_lines(t_parser *parser, t_game *game, int malloc_lines)
{
	if (!cub_check_after_map(parser))
		return (cub_free_fd("the setting file has non white space \
line after his declaration", parser));
if (!ft_malloc_char(malloc_lines + 1, &(game->level->area->map)))
		return (cub_free_fd("insufficient memory to initiate cub3D", 0));
	if (!ft_malloc_int(malloc_lines + 1, &(game->level->area->lines_length)))
		return (cub_free_fd("program didn't find memory to load", 0));
	return (TRUE);
}

t_bool	cub_malloc_area(t_area **area)
{
	*area = (t_area *)malloc(sizeof(t_area));
	if (*area)
	{
		(*area)->lines_length = 0;
		(*area)->map = 0;
	}
}