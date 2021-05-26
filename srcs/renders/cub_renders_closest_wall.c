/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_closest_wall.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:08:13 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/26 00:35:32 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_fiat_lux(t_game *game, t_walls *walls, int pix_x)
{
	int pix_y;
	int wall_top;
	int wall_end;
	int	argb;

	if (walls->ori_wall)
		argb = 0x663300;
	else
		argb = 0x808080;
	wall_top = game->screen.resolution.height_mdl - ((int)(walls->wall) / 2);
	wall_end = game->screen.resolution.height - wall_top;
	pix_y = 0;
	while (pix_y < wall_top)
		cub_set_my_mlx_pixel( game->screen.pic_screen, pix_x, pix_y++,
			game->level.ceiling.color.argb);
	while (pix_y < wall_end && pix_y < game->screen.resolution.height)
		cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y++, argb);
	while (pix_y < game->screen.resolution.height)
		cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y++,
			game->level.floor.color.argb);
}

void	cub_the_wall(t_game *game, t_walls *walls)
{
	if (!(walls->v_wall) || (walls->h_wall && walls->v_wall && walls->dh_wall <= walls->dv_wall))
	{
		walls->wall = walls->dh_wall;
		walls->wall_x = walls->hx_wall;
		walls->wall_y = walls->hy_wall;
		walls->ori_wall = TRUE;
	}
	else if (!(walls->h_wall) || (walls->h_wall && walls->v_wall && walls->dh_wall > walls->dv_wall))
	{
		walls->wall = walls->dv_wall;
		walls->wall_x = walls->vx_wall;
		walls->wall_y = walls->vy_wall;
		walls->ori_wall = FALSE;
	}
	//else if (walls->dh_wall == walls->dv_wall
	//	&& walls->t_agl < 1 && walls->t_agl > -1 )
	//	{
	//	
	//	}
}

void	cub_render_closest_wall(t_game *game, t_walls *walls, int pix_x)
{
	walls->dh_wall = sqrt(pow((game->level.player.pos_x - walls->hx_wall), 2)
			+ pow((game->level.player.pos_y - walls->hy_wall), 2));
	walls->dv_wall = sqrt(pow((game->level.player.pos_x - walls->vx_wall), 2)
			+ pow((game->level.player.pos_y - walls->vy_wall), 2));
	printf("h_wall_x = %f h_wall_y = %d v_wall_x = %d v_wll_y = %f h_wall_d = %f v_wall_d = %f\n", walls->hx_wall, walls->hy_wall, walls->vx_wall, walls->vy_wall, walls->dh_wall, walls->dv_wall);
	cub_the_wall(game, walls);
	walls->wall *= walls->c_demi_fov;
	walls->wall = (SIDE / walls->wall) * game->screen.resolution.dist_plan;
	//if (!(walls->ori_wall) && ((walls->r_agl * (180 / M_PI)) < 40 || (walls->r_agl * (180 / M_PI)) > 315))
	//	exit(cub_free_game(game));
}
