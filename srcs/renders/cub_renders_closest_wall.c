/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_closest_wall.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:08:13 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/07 21:55:54 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_fiat_lux(t_game *game, t_textures *txtrs, int pix_x)
{
	int	pix_y;
	int	texture_top;
	int	texture_end;
	int	argb;

	texture_top = game->screen.resolution.height_mdl - ((int)(txtrs->wall) / 2);
	texture_end = game->screen.resolution.height - texture_top;
	pix_y = 0;
	while (pix_y < texture_top)
		cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y++,
			game->level.ceiling.color.argb);
	txtrs->texture_y = (pix_y - game->screen.resolution.height_mdl
		+ (txtrs->wall / 2)) * txtrs->texture_y_o_s;
	while (pix_y < texture_end && pix_y < game->screen.resolution.height)
	{	
		cub_get_texture(&(game->level), txtrs);
		cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y++, argb);
		txtrs->texture_y += txtrs->texture_y_o_s;
	}
	while (pix_y < game->screen.resolution.height)
		cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y++,
			game->level.floor.color.argb);
}

char	cub_the_wall(t_game *game, t_textures *txtrs)
{
	if (!(txtrs->v_wall) || (txtrs->h_wall && txtrs->v_wall
			&& txtrs->dh_wall < txtrs->dv_wall))
	{
		txtrs->wall = txtrs->dh_wall;
		txtrs->wall_x = txtrs->hx_wall;
		txtrs->wall_y = txtrs->hy_wall;
		if (txtrs->s_agl < 0)
			return ('N');
		return ('S');
	}
	txtrs->wall = txtrs->dv_wall;
	txtrs->wall_x = txtrs->vx_wall;
	txtrs->wall_y = txtrs->vy_wall;
	if (txtrs->c_agl > 0)
		return ('E');
	return ('W');
}

void	cub_render_closest_wall(t_game *game, t_textures *txtrs, int pix_x)
{
	if (txtrs->h_wall)
		txtrs->dh_wall = sqrt(
				pow((game->level.player.pos_x - txtrs->hx_wall), 2)
				+ pow((game->level.player.pos_y - txtrs->hy_wall), 2));
	if (txtrs->v_wall)
		txtrs->dv_wall = sqrt(
				pow((game->level.player.pos_x - txtrs->vx_wall), 2)
				+ pow((game->level.player.pos_y - txtrs->vy_wall), 2));
	txtrs->ori_wall = cub_the_wall(game, txtrs);
	txtrs->wall *= txtrs->c_demi_fov;
	txtrs->wall = (SIDE / txtrs->wall) * game->screen.resolution.dist_plan;
	if (txtrs->ori_wall == 'N' || txtrs->ori_wall == 'S')
		txtrs->texture_x = (int)(txtrs->wall_x) % SIDE;
	else
		txtrs->texture_x = (int)(txtrs->wall_y) % SIDE;
	txtrs->texture_y_o_s = (SIDE / txtrs->wall);
}
