/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:17:52 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 20:51:02 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int	cub_key_push(int key_code, t_game *game)
{
	if (key_code == 0xff1b)
		cub_free_game(&game);
}

t_bool	cub_coin(t_game *game)
{
	cub_set_mlx_screen(game);
	cub_set_image_to_window(game->mlx, game->screen);
	mlx_hook(game->screen->mlx_screen, 2, (1L<<0), &cub_key_push, game);
	mlx_loop(game->mlx);
	return (TRUE);
}
