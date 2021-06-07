/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:49:17 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/07 23:27:53 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_print_sprite(t_game *game, t_sprite *sprt, int pix_x)
{
	int	pix_y;
	int	pix_stop;
	int	argb;

	if (pix_x < -1)
		pix_x = -1;
	pix_stop = pix_x + (int)(game->level.area.sprite->height);
	while (++(pix_x) < game->screen.resolution.width && (pix_x) < pix_stop)
	{
		pix_y = game->screen.resolution.height_mdl;
		while (++pix_y < game->screen.resolution.height && (pix_y) < sprt->end)
		{
			if (argb)
				cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y, argb);
			txtrs->r_sprite += game->screen.resolution.r_o_s_pix;
		}
	}
}

void	cub_init_print_sprite(t_game *game, t_sprite *sprt, int *pix_x)
{
	sprt->height = (SIDE / sprt->distance)
		* game->screen.resolution.dist_plan;
	sprt->top = game->screen.resolution.height_mdl
		- ((int)(sprt->height) / 2);
	sprt->end = game->screen.resolution.height - (sprt->top);
	sprt->r_x_sprite = atan2((sprt->pos_x - game->level.player.pos_x),
	(sprt->pos_y - game->level.player.pos_y));
	if (sprt->r_x_sprite > game->deg.r360)
		sprt->r_x_sprite -= game->deg.r360;
	else if (sprt->r_x_sprite < 0)
		sprt->r_x_sprite = game->deg.r360 + sprt->r_x_sprite;
	sprt->r_x_sprite = game->level.player.dir - sprt->r_x_sprite
		+ game->screen.resolution.r_demi_fov;
	(*pix_x) = sprt->r_x_sprite / game->screen.resolution.r_o_s_pix;
	(*pix_x) -= (int)(sprt->height / 2);
}

void	cub_render_sprites(t_game *game)
{
	int	crnt_sprite;
	int	pix_x;
	t_sprite *sprt;
	
	sprt = &(game->level.area.sprite);
	sprt--;
	crnt_sprite = -1;
	while (++crnt_sprite < game->level.area.nb_sprite)
	{
		if ((++sprt)->visible)
		{
			cub_init_print_sprite(game, sprt, &pix_x);
			cub_print_sprite(game, sprt, pix_x);
		}
	}
}