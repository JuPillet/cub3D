/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:03:07 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/13 21:00:32 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_set_player(int map_x, int map_y, char **map, t_player *player)
{
	if (map[map_y][map_x] == 'N' || map[map_y][map_x] == 'S'
		|| map[map_y][map_x] == 'W' || map[map_y][map_x] == 'E')
	{
		if (player->is)
			return (FALSE);
		else
		{
			player->position_x = (map_x * 64) + 32;
			player->position_y = (map_y * 64) + 32;
			if (map[map_y][map_x] == 'N')
				player->orientation = M_PI_2;
			else if (map[map_y][map_x] == 'E')
				player->orientation = 0;
			else if (map[map_y][map_x] == 'S')
				player->orientation = M_PI_2 * 3;
			else
				player->orientation = M_PI;
			player->is = TRUE;
		}
	}
	return (TRUE);
}

t_bool	cub_search_player(char **map, t_player *player)
{
	int	map_y;
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
	if (!(player->is))
		return (ft_error("the setting file has no declared \
player location in the map", 0));
	return (TRUE);
}

t_bool	cub_set_horizon(t_parser *parser, t_game *game)
{
	t_horizon	*horizon;

	if (parser->line[--(parser->indln)] == 'F')
		horizon = &(game->level.floor);
	else
		horizon = &(game->level.ceiling);
	if (horizon->is)
	{
		if (parser->line[parser->indln] == 'F')
			return (ft_error("need only one floor color", 0));
		else
			return (ft_error("need only one ceiling color", 0));
	}
	(parser->indln)++;
	if (!cub_parse_color(parser, &(horizon->color)))
	{
		if (parser->line[parser->indln] == 'F')
			return (ft_error("invalid floor color", parser->line));
		else
			return (ft_error("invalid ceiling color", parser->line));
	}
	horizon->is = TRUE;
	return (TRUE);
}

t_bool	cub_set_resolution(char *line, void *mlx, t_resolution *resolution)
{
	int	width;
	int	height;

	if (resolution->width < 1 || resolution->height < 1)
		return (ft_error("resolution format to small, minimum format :\n\
- width : 1\n- height 1", line));
	mlx_get_screen_size(mlx, &width, &height);
	if (resolution->width > width)
		resolution->width = width;
	if (resolution->height > height)
		resolution->height = height;
	resolution->is = TRUE;
	return (TRUE);
}
