/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mallocers_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:26:04 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/16 23:01:13 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_set_map_columns(char *line, char **line_map)
{
	int	indln;
	int	column;
	int	tabulation;

	indln = 0;
	column = 0;
	while (line[indln])
	{
		tabulation = 4 - (column % 4);
		if (line[indln] == '\t')
			while (tabulation--)
				(*line_map)[column++] = ' ';
		else
			(*line_map)[column++] = line[indln];
		indln++;
	}
	(*line_map)[column] = '\0';
}

t_bool	cub_malloc_map_columns(char *line, char **line_map, int *columns)
{
	int		tabulation;
	int		indln;

	indln = 0;
	while (line[indln])
	{
		if (line[indln] != ' ' && line[indln] != '\t' && line[indln] != '0'
			&& line[indln] != '1' && line[indln] != '2' && line[indln] != 'N'
			&& line[indln] != 'S' && line[indln] != 'E' && line[indln] != 'W')
			return (ft_error("cub3D stopped working because invalid characte\
r is in the map", line));
		if (line[indln++] == '\t')
			(*columns) += (4 - (*columns) % 4);
		else
			(*columns)++;
	}
	if (!ft_malloc_char((*columns) + 1, line_map))
		return (ft_error("program didn't find memory to load", 0));
	cub_set_map_columns(line, line_map);
	return (TRUE);
}

t_bool	cub_malloc_map_lines(t_game *game, char **line, int lines)
{
	ft_free_char(line);
	game->level.area.map = (char **)malloc((lines + 1) * sizeof(char *));
	game->level.area.lines_length = (int *)malloc((lines + 1) * sizeof(int));
	game->level.area.map_height = lines;
	if (!(game->level.area.map) || !(game->level.area.lines_length))
		return (ft_error("program didn't find memory to load", 0));
	while (lines)
	{
		game->level.area.map[lines] = 0;
		game->level.area.lines_length[lines--] = 0;
	}
	game->level.area.map[lines] = 0;
	game->level.area.lines_length[lines] = 0;
	return (TRUE);
}

t_bool	cub_malloc_area(t_area **area)
{
	*area = (t_area *)malloc(sizeof(t_area));
	if (!(*area))
		return (ft_error("program didn't find memory to load", 0));
	(*area)->lines_length = 0;
	(*area)->map = 0;
	return (TRUE);
}
