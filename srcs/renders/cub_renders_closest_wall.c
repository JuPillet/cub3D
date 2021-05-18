/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_closest_wall.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:08:13 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/18 04:28:15 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_fiat_lux(t_game *game, t_walls *walls, int pix_x)
{
	int pix_y;
	int wall_top;
	int wall_end;

	wall_top = game->screen.resolution.height_mdl - ((int)(walls->wall) / 2);
	wall_end = game->screen.resolution.height - wall_top;
	pix_y = -1;
	while (++pix_y < wall_top)
		cub_set_my_mlx_pixel( game->screen.pic_screen, pix_x, pix_y,
			game->level.ceiling.color.argb);
	while (++pix_y < wall_end)
	{
		if ((walls->r_agl > game->deg.d45 && walls->r_agl < game->deg.d135)
			|| (walls->r_agl > game->deg.d225 && walls->r_agl < game->deg.d315))
			cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y,
				0x00CC66);
		else
			cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y,
				0x808080);
	}
	while (++pix_y < game->screen.resolution.height)
		cub_set_my_mlx_pixel(game->screen.pic_screen, pix_x, pix_y,
			game->level.floor.color.argb);
}

void	cub_the_wall(t_game *game, t_walls *walls,
	double h_wall, double v_wall)
{
	if (!(walls->v_wall))
		walls->wall = h_wall;
	else if (!(walls->h_wall))
		walls->wall = v_wall;
	else if (walls->h_wall < walls->v_wall)
		walls->wall = h_wall;
	else if (walls->h_wall > walls->v_wall)
		walls->wall = v_wall;
	else if (walls->h_wall == walls->v_wall && ((game->level.player.dir
			> game->deg.d45 && game->level.player.dir < game->deg.d135)
		|| (game->level.player.dir > game->deg.d225 && game->level.player.dir
			< game->deg.d315)))
		walls->wall = h_wall;
	else
		walls->wall = v_wall;
}

void	cub_render_closest_wall(t_game *game, t_walls *walls, int pix_x)
{
	double	h_wall;
	double	v_wall;
	
	h_wall = sqrt(pow((game->level.player.pos_x - walls->hx_wall), 2)
			+ pow((game->level.player.pos_y - walls->hy_wall), 2));
	v_wall = sqrt(pow((game->level.player.pos_x - walls->hx_wall), 2)
			+ pow((game->level.player.pos_y - walls->hy_wall), 2));
	//if ((walls->r_agl > game->deg.d45 && walls->r_agl < game->deg.d135)
	//	|| (walls->r_agl > game->deg.d225 && walls->r_agl < game->deg.d315))
	//{
	//	h_wall = abs(game->level.player.pos_y - walls->hy_wall) / walls->cs_agl;
	//	v_wall = abs(game->level.player.pos_y - walls->vy_wall) / walls->cs_agl;
	//}
	//else
	//{
	//	h_wall = abs(game->level.player.pos_x - walls->hx_wall) / walls->cs_agl;
	//	v_wall = abs(game->level.player.pos_x - walls->vx_wall) / walls->cs_agl;
	//}
	cub_the_wall(game, walls, h_wall, v_wall);
	walls->wall *= game->screen.resolution.cos_demi_fov;
	walls->wall = (SIDE / walls->wall) * (game->screen.resolution.plan_dist);
	cub_fiat_lux(game, walls, pix_x);
}
