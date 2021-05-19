/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_closest_wall.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:08:13 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/19 02:22:54 by jpillet          ###   ########.fr       */
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
	pix_y = -1;
	while (++pix_y < wall_top)
		cub_set_my_mlx_pixel( game->screen.pic_screen, pix_x, pix_y,
			game->level.ceiling.color.argb);
	while (++pix_y < wall_end && pix_y < game->screen.resolution.height)
		cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y, argb);
	while (++pix_y < game->screen.resolution.height)
		cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y,
			game->level.floor.color.argb);
}

void	cub_the_wall(t_game *game, t_walls *walls,
	double h_wall, double v_wall)
{
	if ((walls->h_wall && !(walls->v_wall))
			|| (walls->h_wall && walls->v_wall
					&& walls->h_wall < walls->v_wall))
	{
		walls->wall = h_wall;
		walls->ori_wall = TRUE;
	}
	else if ((!(walls->h_wall) && walls->v_wall)
			|| (walls->h_wall && walls->v_wall
					&& walls->h_wall > walls->v_wall))
	{
		walls->wall = v_wall;
		walls->ori_wall = FALSE;
	}
	else if (walls->h_wall == walls->v_wall
		&& ((walls->r_agl > game->deg.r45 && walls->r_agl <= game->deg.r135)
		|| (walls->r_agl > game->deg.r225 && walls->r_agl <= game->deg.r315)))
	{
		walls->wall = h_wall;
		walls->ori_wall = TRUE;
	}
	else
	{
		walls->wall = v_wall;
		walls->ori_wall = FALSE;
	}
}

void	cub_render_closest_wall(t_game *game, t_walls *walls, int pix_x)
{
	double	h_wall;
	double	v_wall;

	h_wall = sqrt(pow((game->level.player.pos_x - walls->hx_wall), 2)
			+ pow((game->level.player.pos_y - walls->hy_wall), 2));
	v_wall = sqrt(pow((game->level.player.pos_x - walls->vx_wall), 2)
			+ pow((game->level.player.pos_y - walls->vy_wall), 2));
	cub_the_wall(game, walls, h_wall, v_wall);
	walls->wall *= (walls->c_adj);
	walls->wall = game->screen.resolution.dist_plan / walls->wall;
}
