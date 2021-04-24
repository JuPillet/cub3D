/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:35:06 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/24 15:04:22 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_check_player(char **map, t_player *player)
{
	int		location_x;
	int		location_y;

	location_x = (int)((*(player->position_x) - 32) / 64);
	location_y = (int)((*(player->position_y) - 32) / 64);
	if (location_x == 0 || location_x > 33554430
		|| location_y == 0 || location_y > 33554430)
		return (FALSE);
	if (map[location_y - 1][location_x] == ' '
		|| map[location_y + 1][location_x] == ' '
		|| map[location_y][location_x - 1] == ' '
		|| map[location_y][location_x + 1] == ' ')
		return (FALSE);
	return (TRUE);
}

t_bool	cub_set_player(int map_x, int map_y, char **map, t_player *player)
{
	if (map[map_y][map_x] == 'N' || map[map_y][map_x] == 'S'
		|| map[map_y][map_x] == 'W' || map[map_y][map_x] == 'E')
	{
		if (*(player->is))
			return (FALSE);
		else
		{
			*(player->position_x) = (map_x * 64) + 32;
			*(player->position_y) = (map_y * 64) + 32;
			if (map[map_y][map_x] == 'N')
				*(player->orientation) = M_PI_2;
			else if (map[map_y][map_x] == 'E')
				*(player->orientation) = 0;
			else if (map[map_y][map_x] == 'S')
				*(player->orientation) = M_PI_2 * 3;
			else
				*(player->orientation) = M_PI;
			*(player->is) = TRUE;
		}
	}
	return (TRUE);
}

t_bool	cub_search_player(char **map, t_player *player)
{
	int map_y;
	int	map_x;

	map_y = -1;
	while (map[(++map_y)])
	{
		map_x = -1;
		while (map[map_y][(++map_x)])
			if (!cub_set_player(map_x, map_y, map, player))
				return (ft_error("the setting file has two or more declared \
player location in the map, you must need only one", 0));
	}
	if (!(*(player->is)))
		return (ft_error("the setting file has no declared \
player location in the map", 0));
	if (!cub_check_player(map, player));
		return (ft_error("the setting file has a wrong declared \
player location in the map", 0));
	return (TRUE);
}

t_bool	cub_set_resolution(char *line, t_screen *screen)
{
	int	*width;
	int *height;
	
	if (*(screen->resolution->width) < 1 || *(screen->resolution->height) < 1)
		return (ft_error("resolution format to small, minimum format :\n\
- width : 1\n- height 1", line));
	mlx_get_screen_size(screen->mlx, width, height);
	if (*(screen->resolution->width) > width)
		*(screen->resolution->width) = width;
	if (*(screen->resolution->height) > height)
		*(screen->resolution->height) = height;
	*(screen->resolution->is) = TRUE;
	return (TRUE);
}

void	cub_set_map_column(char *line, char *linemap)
{
	int	indln;
	int	column;
	int	tabulation;

	indln = 0;
	column = 0;
	while (linemap[++indln])
	{
		tabulation = 4 - (column % 4);
		if (line[indln] == '\t')
			while (tabulation--)
				linemap[column++] = ' ';
		else
			linemap[column++] = line[indln];
	}
	linemap[column] = '\0';
}