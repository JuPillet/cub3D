/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:23:01 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/28 11:44:20 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

/*
** AID
** parse NESWSP texture
*/

t_bool	cub_parser_texture_north(t_parser *parser, t_game *game)
{
	int copy;
	int path_len;
	char *path;

	if (game->level->no)
		return (cub_free_fd("two or more north texture declared, need only one",
				0, parser));
	path_len = 0;
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	copy = parser->indln;
	(parser->indln)--;
	while (parser->line[++(parser->indln)])
		path_len++;
	if (!ft_malloc_char((path_len) + 1, &path))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
		while (parser->line[copy])
			path[copy++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path));
}

t_bool	cub_parser_texture_east(t_parser *parser, t_game *game)
{
	int copy;
	int path_len;
	char *path;

	if (game->level->ea)
		return (cub_free_fd("two or more east texture declared, need only one",
				0, parser));
	path_len = 0;
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	copy = parser->indln;
	(parser->indln)--;
	while (parser->line[++(parser->indln)])
		path_len++;
	if (!ft_malloc_char((path_len) + 1, path))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
		while (parser->line[copy])
			path[copy++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path));
}

t_bool	cub_parser_texture_south(t_parser *parser, t_game *game)
{
	int copy;
	int path_len;
	char *path;

	if (game->level->so)
		return (cub_free_fd("two or more south texture declared, need only one",
				0, parser));
	path_len = 0;
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	copy = parser->indln;
	(parser->indln)--;
	while (parser->line[++(parser->indln)])
		path_len++;
	if (!ft_malloc_char((path_len) + 1, &path))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
		while (parser->line[copy])
			path[copy++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path));
}

t_bool	cub_parser_texture_west(t_parser *parser, t_game *game)
{
	int copy;
	int path_len;
	char *path;

	if (game->level->we)
		return (cub_free_fd("two or more west texture declared, need only one",
				0, parser));
	path_len = 0;
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	copy = parser->indln;
	(parser->indln)--;
	while (parser->line[++(parser->indln)])
		path_len++;
	if (!ft_malloc_char((path_len) + 1, &path))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
		while (parser->line[copy])
			path[copy++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path));
}

t_bool	cub_parser_texture_sprite(t_parser *parser, t_game *game)
{
	int copy;
	int path_len;
	char *path;

	if (game->level->sp)
		return (cub_free_fd("two or more sprite texture declared, \
need only one", 0, parser));
	path_len = 0;
	while (ft_isspace(parser->line[parser->indln]))
		(parser->indln)++;
	copy = parser->indln;
	(parser->indln)--;
	while (parser->line[++(parser->indln)])
		path_len++;
	if (!ft_malloc_char((path_len) + 1, &(path)))
		return (cub_free_fd("insufficient memory to initiate cub3D",
				0, parser));
		while (parser->line[copy])
			path[copy++] = parser->line[(parser->indln)++];
	return (cub_set_texture(game, parser, path));
}