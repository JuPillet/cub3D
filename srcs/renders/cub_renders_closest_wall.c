/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_closest_wall.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:08:13 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/16 19:37:44 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_render_closest_wall(t_game *game, t_walls walls, double pix_x)
{
	double	h_wall;
	double	v_wall;
	double	the_wall;
	
	if (walls.h_wall)
		h_wall = abs(game->level.player.pos_x - walls.h_wall_x) / walls.c_agl;
	if (walls.v_wall)
		v_wall = abs(game->level.player.pos_x - walls.v_wall_x) / walls.c_agl;
	if (!walls.v_wall || h_wall < v_wall)
		the_wall = h_wall;
	else
		the_wall = v_wall;
	if (pix_x < game->screen.resolution.width_mdl)
		the_wall *= game->screen.resolution.cos_demi_fov;
	the_wall = (SIDE / the_wall) * (game->screen.resolution.plan_dist);
	the_wall = the_wall;
}