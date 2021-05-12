/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:03:07 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 23:59:43 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

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
	return (TRUE);
}

t_bool	cub_set_texture(t_game *game, t_parser *parser,
	char *path, void **texture)
{
	int width;
	int height;

	parser->indln = 0;
	width = 64;
	height = 64;
	*texture = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	free(path);
	path = 0;
	if (!(*texture))
		return (cub_free_parser("program can't open texture",
				parser->line, parser));
	if (width != 64 || height != 64)
		return (cub_free_parser("wrong texture height or width must be 64 pixel",
				parser->line, parser));
	return (TRUE);
}

t_bool	cub_set_horizon(t_parser *parser, t_game *game)
{
	t_horizon *horizon;

	if (parser->line[--(parser->indln)] == 'F')
		horizon = game->level->floor;
	else
		horizon = game->level->ceiling;
	if (*(horizon->is))
	{
		if (parser->line[parser->indln] == 'F')
			return (ft_error("the setting file has two or more declared \
floor color , you must need only one", 0));
		else
			return (ft_error("the setting file has two or more declared \
ceiling color , you must need only one", 0));	
	}
	(parser->indln)++;
	if (!cub_parse_color(parser, horizon))
	{
		if (parser->line[parser->indln] == 'F')
			return (cub_free_parser("the setting file has a invalid floor color", parser->line, parser));
		else
			return (cub_free_parser("the setting file has a invalid ceiling color", parser->line, parser));
	}
	*(horizon->is) = TRUE;
	return (TRUE);
}
