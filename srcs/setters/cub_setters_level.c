/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:03:07 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/20 01:59:17 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_set_player(int map_x, int map_y, char **map, t_game *game)
{
	if (map[map_y][map_x] == 'N' || map[map_y][map_x] == 'S'
		|| map[map_y][map_x] == 'W' || map[map_y][map_x] == 'E')
	{
		if (game->level.player.is)
			return (FALSE);
		else
		{
			game->level.player.pos_x = (map_x * SIDE) + 32;
			game->level.player.pos_y = (map_y * SIDE) + 32;
			if (map[map_y][map_x] == 'N')
				game->level.player.dir = M_PI_2;
			else if (map[map_y][map_x] == 'E')
				game->level.player.dir = 0;
			else if (map[map_y][map_x] == 'S')
				game->level.player.dir = game->deg.r270;
			else
				game->level.player.dir = M_PI;
			game->level.player.is = TRUE;
		}
		map[map_y][map_x] = '0';
	}
	return (TRUE);
}

t_bool	cub_search_player(char **map, t_game *game)
{
	int	map_y;
	int	map_x;

	map_y = -1;
	while (map[(++map_y)])
	{
		map_x = -1;
		while (map[map_y][(++map_x)])
			if (!cub_set_player(map_x, map_y, map, game))
				return (ft_error("the setting file has two or more declared \
player location in the map, you must need only one", 0));
	}
	if (!(game->level.player.is))
		return (ft_error("the setting file has no declared \
player location in the map", 0));
	return (TRUE);
}

t_bool	cub_set_horizon(t_parser *parser, t_game *game)
{
	t_horizon	*horizon;
	int			indln;

	indln = (parser->indln - 1);
	if (parser->line[indln] == 'F')
		horizon = &(game->level.floor);
	else
		horizon = &(game->level.ceiling);
	if (horizon->is)
	{
		if (parser->line[indln] == 'F')
			return (ft_error("need only one floor color", 0));
		return (ft_error("need only one ceiling color", 0));
	}
	if (!cub_parse_color(parser, &(horizon->color)))
	{
		if (parser->line[indln] == 'F')
			return (ft_error("invalid floor color", parser->line));
		return (ft_error("invalid ceiling color", parser->line));
	}
	horizon->is = TRUE;
	return (TRUE);
}

t_bool	cub_set_resolution(t_degree *degree, char *line,
	void *mlx, t_resolution *resolution)
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
	resolution->width_mdl = resolution->width / 2;
	resolution->height_mdl = resolution->height / 2;
	resolution->r_fov = FOV * degree->r1;
	resolution->r_demi_fov = resolution->r_fov / 2;
	resolution->r_pix =  resolution->r_fov / resolution->width;
	resolution->dist_plan = resolution->width_mdl / tan(resolution->r_demi_fov);
	resolution->is = TRUE;
	return (TRUE);
}
