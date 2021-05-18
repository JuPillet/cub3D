/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:46:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/18 17:54:35 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_ceiling_floor(t_game *game, int x, int y, t_bool cf)
{
	if (cf)
		cub_set_my_mlx_pixel(game->screen.pic_screen, x, y,
			game->level.ceiling.color.argb);
	else
		cub_set_my_mlx_pixel(game->screen.pic_screen, x, y,
			game->level.floor.color.argb);
}

void	cub_map_render(t_game *game)
{
	int	pix_y;
	int	pix_x;
	int	map_y;
	int	map_x;
	int	color;

	map_y = -1;
	while (game->level.area.map[++map_y])
	{
		map_x = -1;
		while (game->level.area.map[map_y][++map_x])
		{
			cub_set_map_color(game->level.area.map[map_y][map_x], &color);
			pix_y = -1;
			while (++pix_y < 16)
			{
				pix_x = -1;
				while (++pix_x < 16)
					if (game->level.area.map[map_y][map_x] != ' ')
						cub_set_my_mlx_pixel(game->screen.pic_screen,
							(map_x * 16) + pix_x, (map_y * 16) + pix_y, color);
			}
		}
	}
}

void	cub_render_dda(t_game *game, t_walls *walls)
{
	walls->t_agl = tan(walls->r_agl);
	walls->h_wall = cub_dda_hrztl(game, &(game->level), walls);
	walls->v_wall = cub_dda_vrtcl(game, &(game->level), walls);
}

void	cub_render(t_game *game)
{
	int		pix_x;
	int		columns;
	t_walls	walls;

	walls.r_agl = (game->level.player.dir + (
				game->screen.resolution.width_mdl
				* game->screen.resolution.r_o_s));
	pix_x = -1;
	walls.demi_fov = game->screen.resolution.demi_fov * game->deg.r1;
	while (++pix_x < game->screen.resolution.width)
	{
		if (walls.r_agl < 0)
			walls.r_agl = game->deg.r360 - walls.r_agl;
		else if (walls.r_agl > game->deg.r360)
			walls.r_agl = 0;
		walls.cs_adj = cos(walls.demi_fov);
		walls.h_wall = FALSE;
		walls.v_wall = FALSE;
		cub_render_dda(game, &walls);
		cub_render_closest_wall(game, &walls, pix_x);
		cub_fiat_lux(game, &walls, pix_x);
		walls.r_agl -= game->screen.resolution.r_o_s;
	//	walls.demi_fov -= game->screen.resolution.r_o_s;
	}
	cub_map_render(game);
}
