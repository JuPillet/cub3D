/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:46:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/16 20:32:35 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_ceiling_floor(t_game *game, int x, int y, t_bool cf)
{
	if (cf)
		cub_set_my_mlx_pixel(game->screen.pic_scrn, x, y,
			game->level.ceiling.color.argb);
	else
		cub_set_my_mlx_pixel(game->screen.pic_scrn, x, y,
			game->level.floor.color.argb);
}

void	cub_render_dda(t_game *game, t_textures *txtrs)
{
	txtrs->h_wall = FALSE;
	txtrs->v_wall = FALSE;
	txtrs->h_wall = cub_dda_hrztl(game, &(game->level), txtrs);
	txtrs->t_agl *= -1;
	txtrs->v_wall = cub_dda_vrtcl(game, &(game->level), txtrs);
}

void	cub_render_walls(t_game *game)
{
	int			pix_x;
	t_textures	txtrs;

	txtrs.demi_fov = game->screen.resolution.r_demi_fov;
	pix_x = -1;
	while (++pix_x < game->screen.resolution.width)
	{
		txtrs.r_agl = game->level.player.dir + txtrs.demi_fov ;
		if (txtrs.r_agl < 0)
			txtrs.r_agl = game->deg.r360 + txtrs.r_agl;
		else if (txtrs.r_agl >= game->deg.r360)
			txtrs.r_agl = txtrs.r_agl - game->deg.r360 ;
		txtrs.c_agl = cos(txtrs.r_agl);
		txtrs.s_agl = sin(txtrs.r_agl);
		txtrs.t_agl = tan(txtrs.r_agl);
		txtrs.c_demi_fov = cos(txtrs.demi_fov);
		cub_render_dda(game, &txtrs);
		cub_render_closest_wall(game, &txtrs, pix_x);
		cub_fiat_lux(game, &txtrs, pix_x);
		txtrs.demi_fov -= game->screen.resolution.r_o_s_pix;
	}
}
