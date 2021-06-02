/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_modules.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:29:08 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/02 22:42:45 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_area(t_area area)
{
	int	indmap;

	indmap = 0;
	if (area.lines_length)
		free (area.lines_length);
	if (!area.map)
		return (TRUE);
	while (area.map[indmap])
		free(area.map[indmap++]);
	free(area.map);
	return (TRUE);
}

t_bool	cub_free_parser(t_parser *parser)
{
	if (parser->line)
	{
		free(parser->line);
		parser->line = 0;
	}
	if (parser->fd > 2)
	{
		close(parser->fd);
		parser->fd = 0;
	}
	return (TRUE);
}

t_bool	cub_free_texture(void *mlx, void *img)
{
	if (!img)
		return (FALSE);
	mlx_destroy_image(mlx, img);
	return (TRUE);
}

t_bool	cub_free_screen(void *mlx, void *screen)
{
	if (screen)
		mlx_destroy_image(mlx, screen);
	screen = 0;
	return (TRUE);
}

t_bool	cub_free_hash_array(t_game *game)
{
	if (game->hash_array)
		free(game->hash_array);
	game->hash_array = 0;
	return (TRUE);
}
