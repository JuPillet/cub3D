/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mallocers_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:26:04 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/03 20:53:39 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_malloc_sprite(t_game *game)
{
	int	map_y;
	int	map_x;

	game->level.area.nb_sprite = 0;
	map_y = -1;
	while (game->level.area.map[++(map_y)])
	{
		map_x = -1;
		while (game->level.area.map[map_y][++(map_x)])
			if (game->level.area.map[map_y][map_x] == '2')
				game->level.area.nb_sprite++;
	}
	game->level.area.sprite = (t_sprite *)malloc(
		game->level.area.nb_sprite * sizeof(t_sprite));
	if (!(game->level.area.sprite))
		return (ft_error("cub3D didn't find the memory to load", 0));
	return (cub_set_sprite(game));
}

t_bool	cub_set_map_columns(char **line, char **line_map)
{
	int	indln;
	int	column;
	int	tabulation;

	indln = 0;
	column = 0;
	while ((*line)[indln])
	{
		tabulation = 4 - (column % 4);
		if ((*line)[indln] == '\t')
			while (tabulation--)
				(*line_map)[column++] = ' ';
		else
			(*line_map)[column++] = (*line)[indln];
		indln++;
	}
	(*line_map)[column] = '\0';
	ft_free_char(line);
	return (TRUE);
}

t_bool	cub_malloc_map_columns(char **line, char **line_map, int *columns)
{
	int	tabulation;
	int	indln;

	indln = 0;
	while ((*line)[indln])
	{
		if ((*line)[indln] != ' ' && (*line)[indln] != '\t'
				&& (*line)[indln] != '0' && (*line)[indln] != '1'
				&& (*line)[indln] != '2' && (*line)[indln] != 'N'
				&& (*line)[indln] != 'S' && (*line)[indln] != 'E'
				&& (*line)[indln] != 'W')
		{
			ft_error("invalid map character", (*line));
			ft_free_char(line);
			return (FALSE);
		}
		if ((*line)[indln++] == '\t')
			(*columns) += (4 - (*columns) % 4);
		else
			(*columns)++;
	}
	if (ft_malloc_char((*columns) + 1, line_map))
		return (cub_set_map_columns(line, line_map));
	ft_free_char(line);
	return (ft_error("program didn't find memory to load", 0));
}

t_bool	cub_malloc_map_lines(t_game *game, int lines)
{
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
