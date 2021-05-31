/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:17:52 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/31 21:53:20 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_coin(t_game *game)
{
	cub_set_mlx_screen(game);
	mlx_loop_hook(game->mlx, &cub_set_image_to_window, game);
	mlx_hook(game->screen.mlx_screen, 2, (1L << 0), &cub_key_push, game);
	mlx_hook(game->screen.mlx_screen, 3, (1L << 1), &cub_key_release, game);
	mlx_loop(game->mlx);
	return (TRUE);
}
