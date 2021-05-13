/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:53:33 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/14 01:04:40 by jpillet          ###   ########.fr       */
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

t_bool	cub_free_sprite(void *mlx, void *img)
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
	return (TRUE);
}

t_bool	cub_free_hash_array(t_game *game)
{
	if (game->hash_array)
		free(game->hash_array);
	game->hash_array = 0;
}

t_bool	cub_free_game(t_game **game)
{
	if (!(*game))
		return (FALSE);
	cub_free_hash_array(*game);
	cub_free_parser(&((*game)->parser));
	if ((*game)->screen.pic_screen.img)
		mlx_destroy_image((*game)->mlx, (*game)->screen.pic_screen.img);
	if ((*game)->screen.mlx_screen)
		mlx_destroy_window((*game)->mlx, (*game)->screen.mlx_screen);
	cub_free_sprite((*game)->mlx, (*game)->level.no);
	cub_free_sprite((*game)->mlx, (*game)->level.ea);
	cub_free_sprite((*game)->mlx, (*game)->level.so);
	cub_free_sprite((*game)->mlx, (*game)->level.we);
	cub_free_sprite((*game)->mlx, (*game)->level.sp);
	if ((*game)->mlx)
		mlx_destroy_display((*game)->mlx);
	cub_free_area((*game)->level.area);
	free(*game);
	(*game) = 0;
	return (FALSE);
}
