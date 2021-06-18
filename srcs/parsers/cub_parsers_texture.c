/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsers_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:51:28 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/02 22:58:32 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_parse_texture_north(t_parser *parser, t_game *game)
{
	int		path_len;
	char	*path;
	char	*line;

	line = parser->line;
	if (game->level.no.img)
		return (ft_error("setting file need only one north texture", 0));
	while (ft_isspace(line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (line[(parser->indln) + path_len] && !ft_isspace(line[parser->indln]))
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (ft_error("insufficient memory to initiate cub3D", 0));
	path_len = 0;
	while (line[(parser->indln)] && !ft_isspace(line[parser->indln]))
		path[path_len++] = parser->line[(parser->indln)++];
	while (line[(parser->indln)] && ft_isspace(line[parser->indln]))
		(parser->indln)++;
	if (line[(parser->indln)])
	{
		ft_free_char(&path);
		return (ft_error("invalid north texture line", parser->line));
	}
	return (cub_set_texture(game, parser, path, &(game->level.no)));
}

t_bool	cub_parse_texture_east(t_parser *parser, t_game *game)
{
	int		path_len;
	char	*path;
	char	*line;

	line = parser->line;
	if (game->level.ea.img)
		return (ft_error("setting file need only one east texture", 0));
	while (ft_isspace(line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (line[(parser->indln) + path_len] && !ft_isspace(line[parser->indln]))
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (ft_error("insufficient memory to initiate cub3D", 0));
	path_len = 0;
	while (line[(parser->indln)] && !ft_isspace(line[parser->indln]))
		path[path_len++] = line[(parser->indln)++];
	while (line[(parser->indln)] && ft_isspace(line[parser->indln]))
		(parser->indln)++;
	if (line[(parser->indln)])
	{
		ft_free_char(&path);
		return (ft_error("invalid east texture line", parser->line));
	}
	return (cub_set_texture(game, parser, path, &(game->level.ea)));
}

t_bool	cub_parse_texture_south(t_parser *parser, t_game *game)
{
	int		path_len;
	char	*path;
	char	*line;

	line = parser->line;
	if (game->level.so.img)
		return (ft_error("setting file need only one south texture", 0));
	while (ft_isspace(line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (line[(parser->indln) + path_len] && !ft_isspace(line[parser->indln]))
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (ft_error("insufficient memory to initiate cub3D", 0));
	path_len = 0;
	while (line[(parser->indln)] && !ft_isspace(line[parser->indln]))
		path[path_len++] = parser->line[(parser->indln)++];
	while (line[(parser->indln)] && ft_isspace(line[parser->indln]))
		(parser->indln)++;
	if (line[(parser->indln)])
	{
		ft_free_char(&path);
		return (ft_error("invalid south texture line", parser->line));
	}
	return (cub_set_texture(game, parser, path, &(game->level.so)));
}

t_bool	cub_parse_texture_west(t_parser *parser, t_game *game)
{
	int		path_len;
	char	*path;
	char	*line;

	line = parser->line;
	if (game->level.we.img)
		return (ft_error("setting file need only one west texture", 0));
	while (ft_isspace(line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (line[(parser->indln) + path_len] && !ft_isspace(line[parser->indln]))
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (ft_error("insufficient memory to initiate cub3D", 0));
	path_len = 0;
	while (line[(parser->indln)] && !ft_isspace(line[parser->indln]))
		path[path_len++] = parser->line[(parser->indln)++];
	while (line[(parser->indln)] && ft_isspace(line[parser->indln]))
		(parser->indln)++;
	if (line[(parser->indln)])
	{
		ft_free_char(&path);
		return (ft_error("invalid west texture  line", parser->line));
	}
	return (cub_set_texture(game, parser, path, &(game->level.we)));
}

t_bool	cub_parse_texture_sprite(t_parser *parser, t_game *game)
{
	int		path_len;
	char	*path;
	char	*line;

	line = parser->line;
	if (game->level.sp.img)
		return (ft_error("setting file need only one sprite texture", 0));
	while (ft_isspace(line[parser->indln]))
		(parser->indln)++;
	path_len = 0;
	while (line[(parser->indln) + path_len] && !ft_isspace(line[parser->indln]))
		path_len++;
	if (!ft_malloc_char(path_len + 1, &path))
		return (ft_error("insufficient memory to initiate cub3D", 0));
	path_len = 0;
	while (line[(parser->indln)] && !ft_isspace(line[parser->indln]))
		path[path_len++] = parser->line[(parser->indln)++];
	while (line[(parser->indln)] && ft_isspace(line[parser->indln]))
		(parser->indln)++;
	if (line[(parser->indln)])
	{
		ft_free_char(&path);
		return (ft_error("invalid sprite texture line", parser->line));
	}
	return (cub_set_texture(game, parser, path, &(game->level.sp)));
}
