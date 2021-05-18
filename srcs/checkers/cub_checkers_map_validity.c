/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checkers_map_validity.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:50:35 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/18 00:12:36 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_check_out_map(t_area area, int y, int x)
{
	char	**map;
	int		*lines_length;

	map = area.map;
	lines_length = area.lines_length;
	if (map[y][x] != ' ')
		return (FALSE);
	if (map[y][x + 1] && map[y][x + 1] != ' ' && map[y][x + 1] != '1')
		return (ft_error("map not closed", 0));
	if (map[y + 1] && x < lines_length[y + 1]
		&& map[y + 1][x] != ' ' && map[y + 1][x] != '1')
		return (ft_error("map not closed", 0));
	return (TRUE);
}

t_bool	cub_check_wall_map(t_area area, int y, int x)
{
	char	**map;
	int		*lines_length;

	map = area.map;
	lines_length = area.lines_length;
	if (map[y][x] != '1')
		return (FALSE);
	if (map[y][x + 1] && map[y][x + 1] != ' ' && map[y][x + 1] != '0'
		&& map[y][x + 1] != '1' && map[y][x + 1] != '2'
		&& map[y][x + 1] != 'N' && map[y][x + 1] != 'E'
		&& map[y][x + 1] != 'S' && map[y][x + 1] != 'W')
		return (ft_error("map not closed", map[y]));
	if (map[y + 1] && x < lines_length[y + 1]
		&& map[y + 1][x] != ' ' && map[y + 1][x] != '0'
		&& map[y + 1][x] != '1' && map[y + 1][x] != '2'
		&& map[y + 1][x] != 'N' && map[y + 1][x] != 'E'
		&& map[y + 1][x] != 'S' && map[y + 1][x] != 'W')
		return (ft_error("map not closed", 0));
	return (TRUE);
}

t_bool	cub_check_in_map(t_level level, int y, int x)
{
	char	**map;
	int		*lines_length;

	map = level.area.map;
	lines_length = level.area.lines_length;
	if ((map[y][x] != '0' && map[y][x] != '2' && map[y][x] != 'N'
		&& map[y][x] != 'E' && map[y][x] != 'S' && map[y][x] != 'W'))
		return (FALSE);
	if (map[y][x] == '2' && !(level.sp))
		return (ft_error("value '2' used but sprite undeclared", map[y]));
	if (!y || !x || (y && (!(x < lines_length[y - 1])
				|| !(x < lines_length[y + 1]))))
		return (ft_error("map not closed or player isn't in the map", map[y]));
	if (!(map[y][x + 1]) || (map[y][x + 1] && map[y][x + 1] != '0'
		&& map[y][x + 1] != '1' && map[y][x + 1] != '2'
		&& map[y][x + 1] != 'N' && map[y][x + 1] != 'E'
		&& map[y][x + 1] != 'S' && map[y][x + 1] != 'W'))
		return (ft_error("map not closed or player isn't in the map", map[y]));
	if (map[y + 1][x] != '0' && map[y + 1][x] != '1' && map[y + 1][x] != '2'
		&& map[y + 1][x] != 'N' && map[y + 1][x] != 'E' && map[y + 1][x] != 'S'
		&& map[y + 1][x] != 'W')
		return (ft_error("map not closed or player isn't in the map", map[y]));
	return (TRUE);
}

t_bool	cub_check_map(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = game->level.area.map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (!cub_check_out_map(game->level.area, y, x)
				&& !cub_check_wall_map(game->level.area, y, x)
				&& !cub_check_in_map(game->level, y, x))
				return (FALSE);
	}
	return (cub_search_player(map, game));
}
