/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:23:01 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/28 23:39:05 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

/*
** AID
** parse NESWSP texture
*/

t_bool	cub_parse_texture_north(t_parser *parser, t_game *game)
{
	int path_len;
	char *path;

	if (game->level->no)
		return (cub_free_fd("two or more north texture declared, need only one",
				0, parser));
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (parser->line[(parser->indln) + path_len])
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
	path_len = 0;
	while (parser->line[(parser->indln)])
		path[path_len++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path, &(game->level->no)));
}

t_bool	cub_parse_texture_east(t_parser *parser, t_game *game)
{
	int path_len;
	char *path;

	if (game->level->ea)
		return (cub_free_fd("two or more east texture declared, need only one",
				0, parser));
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (parser->line[(parser->indln) + path_len])
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
	path_len = 0;
	while (parser->line[(parser->indln)])
		path[path_len++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path, &(game->level->ea)));
}

t_bool	cub_parse_texture_south(t_parser *parser, t_game *game)
{
	int path_len;
	char *path;

	if (game->level->so)
		return (cub_free_fd("two or more south texture declared, need only one",
				0, parser));
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (parser->line[(parser->indln) + path_len])
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
	path_len = 0;
	while (parser->line[(parser->indln)])
		path[path_len++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path, &(game->level->so)));
}

t_bool	cub_parse_texture_west(t_parser *parser, t_game *game)
{
	int path_len;
	char *path;

	if (game->level->we)
		return (cub_free_fd("two or more west texture declared, need only one",
				0, parser));
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (parser->line[(parser->indln) + path_len])
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
	path_len = 0;
	while (parser->line[(parser->indln)])
		path[path_len++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path, &(game->level->we)));
}

t_bool	cub_parse_texture_sprite(t_parser *parser, t_game *game)
{
	int path_len;
	char *path;

	if (game->level->sp)
		return (cub_free_fd("two or more sprite texture declared, \
need only one", 0, parser));
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (parser->line[(parser->indln) + path_len])
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
	path_len = 0;
	while (parser->line[(parser->indln)])
		path[path_len++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path, &(game->level->sp)));
}