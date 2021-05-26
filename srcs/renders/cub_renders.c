/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:46:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/27 00:14:14 by jpillet          ###   ########.fr       */
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
			0x00FF00);
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
				pix_y = -1;
				while (++pix_y < 16)
				{
					pix_x = -1;
					while (++pix_x < 16)
						if (game->level.area.map[map_y][map_x] != ' ')
							cub_set_my_mlx_pixel(game->screen.pic_screen,
								(map_x * 16) + pix_x, (map_y * 16) + pix_y, color);
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
	walls->h_wall = cub_dda_hrztl(game, &(game->level), walls);
	walls->t_agl *= -1;
	walls->v_wall = cub_dda_vrtcl(game, &(game->level), walls);
}

void	cub_render(t_game *game)
{
	int		pix_x;
	int		columns;
	t_walls	walls;

	//system("clear\n");
	walls.demi_fov = game->screen.resolution.r_demi_fov;
	pix_x = -1;
	while (++pix_x < game->screen.resolution.width)
	{
		walls.r_agl =  game->level.player.dir + walls.demi_fov ;
		if (walls.r_agl < 0)
			walls.r_agl =  game->deg.r360 + walls.r_agl;
		else if (walls.r_agl >= game->deg.r360)
			walls.r_agl = walls.r_agl - game->deg.r360 ;
		walls.c_agl = cos(walls.r_agl);
		walls.s_agl = sin(walls.r_agl);
		walls.t_agl = tan(walls.r_agl);
		walls.c_demi_fov = cos(walls.demi_fov);
		cub_render_dda(game, &walls);
		cub_render_closest_wall(game, &walls, pix_x);
		cub_fiat_lux(game, &walls, pix_x);
		//plot_line (game, game->level.player.pos_x / 4, game->level.player.pos_y / 4, walls.wall_x / 4, walls.wall_y / 4);
		//if ((int)(walls.r_agl * 10000) == (int)(game->level.player.dir * 10000))
		//{
		//	system("clear");
		//	printf("r_agl = %f pos_x = %f pos_y = %f p_dir = %f wall_x = %f wall_y = %f\n", walls.r_agl * 180/M_PI, game->level.player.pos_x, game->level.player.pos_y, game->level.player.dir * (180 / M_PI), walls.wall_x, walls.wall_y);
			//printf("r_index = %d r_agl = %f demi_fov = %f pos_x = %f pos_y = %f c_agl = %f s_agl = %f t_agl = %f c_adj = %f d_fov = %f\n\n", pix_x, walls.r_agl * 180/M_PI, walls.demi_fov * (180 / M_PI), game->level.player.pos_x, game->level.player.pos_y, walls.c_agl, walls.s_agl, walls.t_agl, walls.c_demi_fov, walls.demi_fov);
			//exit(cub_free_game(game));
			//printf("r_agl = %f pos_x = %f pos_y = %f p_dir = %f c_agl = %f s_agl = %f t_agl = %f c_adj = %f d_fov = %f\n", walls.r_agl * 180/M_PI, game->level.player.pos_x, game->level.player.pos_y, game->level.player.dir * (180 / M_PI), walls.c_agl, walls.s_agl, walls.t_agl, walls.c_demi_fov, walls.demi_fov);
		//}
		//walls.r_agl -= game->screen.resolution.r_o_s_pix;
		walls.demi_fov -= game->screen.resolution.r_o_s_pix;
	}
	//cub_map_render(game);
	//exit(cub_free_game(game));
}
