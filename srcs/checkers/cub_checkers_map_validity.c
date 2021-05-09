/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checkers_map_validity.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:50:35 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/09 02:01:56 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_check_out_map(t_area *area, int y, int x)
{
	char	**map;
	int		*lines_length;

	if (map[y][x] != ' ')
		return (FALSE);
	map = area->map;
	lines_length = area->lines_length;
	if(map[y][x + 1] && map[y][x + 1] != ' ' && map[y][x + 1] != '1')
		return (FALSE);
	if(map[y + 1] && x < lines_length[y + 1]
		&& map[y + 1][x] != ' ' && map[y + 1][x] != '1')
		return (FALSE);
	return (TRUE);
}

t_bool	cub_check_wall_map(t_area *area, int y, int x)
{
	char	**map;
	int		*lines_length;

	if (map[y][x] != '1')
		return (FALSE);
	map = area->map;
	lines_length = area->lines_length;
	if (map[y][x + 1] && map[y][x + 1] != ' ' && map[y][x + 1] != '0'
		&& map[y][x + 1] != '1' && map[y][x + 1] != '2'
		&& map[y][x + 1] != 'N' && map[y][x + 1] != 'E'
		&& map[y][x + 1] != 'S' && map[y][x + 1] != 'W')
		return (FALSE);
	if (map[y + 1] && x < lines_length[y + 1]
		&& map[y + 1][x] != ' ' && map[y + 1][x] != '0'
		&& map[y + 1][x] != '1' && map[y + 1][x] != '2'
		&& map[y + 1][x] != 'N' && map[y + 1][x] != 'E'
		&& map[y + 1][x] != 'S' && map[y + 1][x] != 'W')
		return (FALSE);
	return (TRUE);
}

t_bool	cub_check_in_map(t_level *level, int y, int x)
{
	char	**map;
	int		*lines_length;

	map = level->area->map;
	lines_length = level->area->lines_length;
	if (map[y][x] == '2' && !(level->sp))
		return (FALSE);
	if ((map[y][x] == '0' || map[y][x] == '2' || map[y][x] == 'N'
		|| map[y][x] == 'E' || map[y][x] == 'S' || map[y][x] == 'W'))
		return (FALSE);
	if (!y || !x || (y && (!(x < lines_length[y - 1])
	|| !(x < lines_length[y + 1]))))
		return (FALSE);
	if (map[y][x + 1] && map[y][x + 1] != '0'
		&& map[y][x + 1] != '1' && map[y][x + 1] != '2'
		&& map[y][x + 1] != 'N' && map[y][x + 1] != 'E'
		&& map[y][x + 1] != 'S' && map[y][x + 1] != 'W')
		return (FALSE);
	if (map[y + 1][x] != '0' && map[y + 1][x] != '1' && map[y + 1][x] != '2'
		&& map[y + 1][x] != 'N' && map[y + 1][x] != 'E' && map[y + 1][x] != 'S'
		&& map[y + 1][x] != 'W')
		return (FALSE);
	return (TRUE);
}

t_bool	cub_check_map(t_level *level)
{
	int		x;
	int		y;
	char	**map;

	map = level->area->map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (!cub_check_out_map(level->area, y, x)
				&& !cub_check_wall_map(level->area, y, x)
				&& !cub_check_in_map(level, y, x))
				return (ft_error("invalid map\n'\t'- authorized character to ma\
ke map : ' ' '0' '1' '2' 'N' 'E' 'S' 'W' or\n'\t'- a breach in the wall (map no\
t close)\n'\t'- character '2' used but no sprite declarated", 0));
	}
	return (TRUE);
}
