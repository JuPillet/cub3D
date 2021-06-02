/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:17:52 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/02 17:44:28 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_coin(t_game *game)
{
	cub_set_mlx_screen(game);
	if (game->save)
	{
		cub_render(game);
		if (!(cub_bmp_init(game)))
			ft_error("cub3D failed to create the cub_save.bmp:", 0);
		else 
		{
			printf("cub3D succeed to create cub_save.bmp, ");
			printf("you found it in the folder : \"./bmp_save/\"\n");
		}
	}
	else
	{
		mlx_loop_hook(game->mlx, &cub_set_image_to_window, game);
		mlx_hook(game->screen.mlx_screen, 2, (1L << 0), &cub_key_push, game);
		mlx_hook(game->screen.mlx_screen, 3, (1L << 1), &cub_key_release, game);
		mlx_loop(game->mlx);
	}
	return (TRUE);
}
