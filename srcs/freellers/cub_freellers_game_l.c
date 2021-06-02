/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_game_l.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:53:33 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/02 22:43:01 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_game(t_game *game)
{
	cub_free_hash_array(game);
	cub_free_parser(&(game->parser));
	if (game->screen.pic_screen.img)
		mlx_destroy_image(game->mlx, game->screen.pic_screen.img);
	if (game->screen.mlx_screen)
		mlx_destroy_window(game->mlx, game->screen.mlx_screen);
	cub_free_texture(game->mlx, game->level.no.img);
	cub_free_texture(game->mlx, game->level.ea.img);
	cub_free_texture(game->mlx, game->level.so.img);
	cub_free_texture(game->mlx, game->level.we.img);
	cub_free_texture(game->mlx, game->level.sp.img);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	game->mlx = 0;
	cub_free_area(game->level.area);
	return (FALSE);
}
