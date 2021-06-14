/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_game_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:53:33 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/14 17:04:37 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_game(t_game *game)
{
	cub_free_hash_array(game);
	cub_free_parser(&(game->parser));
	if (game->screen.pic_scrn.img)
		mlx_destroy_image(game->mlx, game->screen.pic_scrn.img);
	if (game->screen.mlx_screen)
		mlx_destroy_window(game->mlx, game->screen.mlx_screen);
	cub_free_sprite(game->mlx, game->level.no);
	cub_free_sprite(game->mlx, game->level.ea);
	cub_free_sprite(game->mlx, game->level.so);
	cub_free_sprite(game->mlx, game->level.we);
	cub_free_sprite(game->mlx, game->level.sp);
	if (game->mlx)
		free(game->mlx);
	game->mlx = 0;
	cub_free_area(game->level.area);
	return (FALSE);
}
