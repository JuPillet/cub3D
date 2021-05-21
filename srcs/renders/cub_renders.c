/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:46:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/21 04:42:25 by jpillet          ###   ########.fr       */
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

void	plot_line (t_game *game, int x0, int y0, int x1, int y1)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
 
  while (TRUE)
  {
    cub_set_my_mlx_pixel(game->screen.pic_screen, x0, y0,
			game->level.floor.color.argb);
    if (x0 == x1 && y0 == y1)
		break;
    e2 = 2 * err;
    if (e2 >= dy)
	{
		err += dy;
		x0 += sx;
	 } /* e_xy+e_x > 0 */
    if (e2 <= dx)
	{
		err += dx;
		y0 += sy;
	} /* e_xy+e_y < 0 */
  }
}

void	cub_map_render(t_game *game)
{
	int	pix_y;
	int	pix_x;
	int	map_y;
	int	map_x;
	int	color;

	map_y = 0;
	while (game->level.area.map[map_y])
	{
		map_x = 0;
		while (game->level.area.map[map_y][map_x])
		{
			cub_set_map_color(game->level.area.map, map_x, map_y, &color);
			pix_y = 0;
			//while (++pix_y < 16)
			while (pix_y < SIDE)
			{
				pix_x = 0;
				//while (++pix_x < 16)
				while (pix_x < SIDE)
				{
					//if (((int)(game->level.player.pos_x) / 64) == map_x && ((int)(game->level.player.pos_y) / 64) == map_y
					//	&& (((((int)(game->level.player.pos_x) % 64) / 4) == pix_x && (((int)(game->level.player.pos_y) % 64) / 4) == pix_y)))
					//	cub_set_my_mlx_pixel(game->screen.pic_screen,
					//		(map_x * 32) + pix_x, (map_y * 16) + pix_y, 0x000000);
					//else if (game->level.area.map[map_y][map_x] != ' ')
					//	cub_set_my_mlx_pixel(game->screen.pic_screen,
					//		(map_x * 16) + pix_x, (map_y * 16) + pix_y, color);
					//if (((int)(game->level.player.pos_x) / 64) == map_x && ((int)(game->level.player.pos_y) / 64) == map_y
					//	&& ((int)(game->level.player.pos_x) % 64 == pix_x && ((int)(game->level.player.pos_y) % 64) == pix_y))
					//	cub_set_my_mlx_pixel(game->screen.pic_screen,
					//		map_x + pix_x, map_y + pix_y, 0x000000);
					//else if (game->level.area.map[map_y][map_x] != ' ')
					cub_set_my_mlx_pixel(game->screen.pic_screen,
						(map_x * SIDE) + pix_x, (map_y * SIDE) + pix_y, color);
					pix_x++;
				}
				pix_y++;
			}
			map_x++;
		}
		map_y++;
	}
}

void	cub_render_dda(t_game *game, t_walls *walls)
{
	walls->h_wall = FALSE;
	walls->v_wall = FALSE;
	walls->c_agl = cos(walls->r_agl);
	walls->s_agl = sin(walls->r_agl);
	walls->t_agl = tan(walls->r_agl);
	walls->c_fov = cos(walls->demi_fov);
	walls->h_wall = cub_dda_hrztl(game, &(game->level), walls);
	walls->v_wall = cub_dda_vrtcl(game, &(game->level), walls);
}

void	cub_render(t_game *game)
{
	int		pix_x;
	int		columns;
	t_walls	walls;

	walls.demi_fov = game->screen.resolution.r_demi_fov;
	walls.r_agl =  game->level.player.dir + walls.demi_fov;
	pix_x = 0;
	cub_map_render(game);
	while (walls.demi_fov > -(game->screen.resolution.r_demi_fov))
	{
		if (walls.r_agl < 0)
			walls.r_agl = 360 + walls.r_agl;
		else if (walls.r_agl > M_PI * 2)
			walls.r_agl = walls.r_agl - 360;
		cub_render_dda(game, &walls);
		cub_render_closest_wall(game, &walls, pix_x);
		cub_fiat_lux(game, &walls, pix_x);
		if ((int)(walls.r_agl * 10000) == (int)(game->level.player.dir * 10000))
		{
		//	plot_line (game, game->level.player.pos_x, game->level.player.pos_y, walls.wall_x, walls.wall_y);
			system("clear");
			printf("pos_x = %f pos_y = %f p_dir = %f c_agl = %f s_agl = %f t_agl = %f c_adj = %f d_fov = %f\n", game->level.player.pos_x, game->level.player.pos_y, game->level.player.dir, walls.c_agl, walls.s_agl, walls.t_agl, walls.c_fov, walls.demi_fov);
		}
		walls.r_agl -= game->screen.resolution.r_pix;
		walls.demi_fov -= game->screen.resolution.r_pix;
		pix_x++;
	}
}
