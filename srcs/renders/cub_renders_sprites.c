/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:49:17 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/21 18:09:50 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_print_sprite(t_game *game, t_sprite *sprt, int start)
{
	int		pix_y;
	int		argb;
	double	sprt_y;

	while (++start < game->screen.resolution.width && sprt->sprite_x <= (SIDE - 1))
	{
		if (sprt->distance < game->level.area.dist_walls[start])
		{
			pix_y = sprt->top;
			sprt_y = sprt->sprite_y;
			if (pix_y < 0)
				pix_y = 0;
			pix_y -= 1;
			while (++pix_y < game->screen.resolution.height && sprt_y <= SIDE)
			{
				argb = cub_get_texture_sprite(game->level.sp.addr, sprt, sprt_y);
				if (argb)
					cub_set_my_mlx_pixel(game->screen.pic_scrn, start, pix_y, argb);
				sprt_y += sprt->pix_o_s;
			}
		}
		sprt->sprite_x += sprt->pix_o_s;
	}
}

void	cub_init_print_sprite(t_game *game, t_sprite *sprt, int *start)
{
	system("clear");
	printf("r360 : %f\n", game->deg.r360);
	sprt->r_a_sprite = atan2((game->level.player.pos_y - sprt->pos_y),
		(sprt->pos_x - game->level.player.pos_x));
	printf("r_a_sprt : %f\n", sprt->r_a_sprite);
	printf("player_dir : %f\n", game->level.player.dir);
	printf("demi_fov : %f\n", game->screen.resolution.r_demi_fov);
	sprt->r_x_sprite = (game->level.player.dir - sprt->r_a_sprite
			+ game->screen.resolution.r_demi_fov);
	printf("r_x_sprt : %f\n", sprt->r_x_sprite);
	if (sprt->r_x_sprite >= M_PI)
		sprt->r_x_sprite = sprt->r_x_sprite - game->deg.r360;
	printf("r_x_sprt : %f\n", sprt->r_x_sprite);
	(*start) = (int)(sprt->r_x_sprite / game->screen.resolution.r_o_s_pix);
	printf("start : %i\n", *start);
	printf("demi_height : %f\n", sprt->demi_height);
	(*start) -= (int)(sprt->demi_height);
	printf("start : %i\n", *start);
	sprt->pix_o_s = SIDE / sprt->height;
	sprt->sprite_x = 0;
	if (*start < 0)
	{
		sprt->sprite_x = -((*start) * sprt->pix_o_s);
		*start = 0;
	}
	printf("sprt_x : %f\n", sprt->sprite_x);
	*start -= 1;
	sprt->sprite_y = 0;
	if (sprt->top < 0)
		sprt->sprite_y = -(sprt->top * sprt->pix_o_s);
}

void	cub_pre_init_print_sprite(t_game *game, t_sprite *sprt)
{
	sprt->height = (SIDE / sprt->distance) * game->screen.resolution.dist_plan;
	sprt->demi_height = (sprt->height / 2);
	sprt->top = game->screen.resolution.height_mdl - sprt->demi_height;
}

void	cub_render_sprites(t_game *game)
{
	int	crnt_sprite;
	int	start;
	t_sprite *sprt;
	
	sprt = game->level.area.sprite;
	crnt_sprite = -1;
	while (++crnt_sprite < game->level.area.nb_sprite)
	{
		if (sprt[crnt_sprite].visible)
		{
			cub_pre_init_print_sprite(game, &(sprt[crnt_sprite]));
			cub_init_print_sprite(game, &(sprt[crnt_sprite]), &start);
			cub_print_sprite(game, &(sprt[crnt_sprite]), start);
		}
		sprt[crnt_sprite].visible = FALSE;
	}
}