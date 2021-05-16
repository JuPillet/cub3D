/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:46:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/16 04:17:40 by jpillet          ###   ########.fr       */
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
	int pix_x;
	int	map_y;
	int	map_x;
	int color;
	
	map_y = -1;
	while (game->level.area.map[++map_y])
	{
		map_x = -1;
		while (game->level.area.map[map_y][++map_x])
		{
			if (game->level.area.map[map_y][map_x] == '1')
				color = 0xFFFFFF;
			else if (game->level.area.map[map_y][map_x] == '0')
				color = 0xDDDDDD;
			else
				color = 0xFBFBFB;
			pix_y = -1;
			while (++pix_y < 16)
			{
				pix_x = -1;
				while (++pix_x < 16)
				{
					if (game->level.area.map[map_y][map_x] != ' ')
						cub_set_my_mlx_pixel(game->screen.pic_screen,
							(map_x * 16) + pix_x, (map_y * 16) + pix_y, color);
				}
			}
		}
	}
}

t_bool	cub_dda_hrztl(t_level *lvl, t_walls *walls)
{
	double	wall_x;
	double	check_x;
	double	wall_y;
	double	check_y;

	static	int nbc;

	nbc++;

	if (walls->r_agl == M_PI || walls->r_agl == 0)
		return (FALSE);
	check_y = SIDE / 25;
	if (walls->r_agl < M_PI && walls->r_agl > 0)
		check_y = -check_y;
	if (walls->r_agl < M_PI && walls->r_agl > 0)
		wall_y = (int)(lvl->player.pos_y / SIDE) * SIDE - 1;
	else
		wall_y = (int)(lvl->player.pos_y / SIDE) * SIDE + SIDE;
	check_x = (SIDE / walls->t_agl) / 25;
	wall_x = lvl->player.pos_x + (lvl->player.pos_y - wall_y) / walls->t_agl;
	while (/*(int)(wall_y / SIDE) >= 0 && (int)(wall_x / SIDE) >= 0 &&
		lvl->area.map[(int)(wall_y / SIDE)] &&
		(int)(wall_x / SIDE) < lvl->area.lines_length[(int)(wall_y / SIDE)]
		&&*/ lvl->area.map[(int)(wall_y) / SIDE][(int)(wall_x) / SIDE] != '1')
	{
		wall_y += (check_y / 2);
		wall_x += (check_x / 2);
	}
	walls->h_wall_x = wall_x;
	walls->h_wall_y = wall_y;
	if (nbc == 83)
		nbc = 83;
	return (TRUE);
}

t_bool	cub_dda_vrtcl(t_level *lvl, t_walls *walls)
{
	double	wall_y;
	double	check_y;
	double	wall_x;
	double	check_x;
	
	static	int nbc;

	nbc++;
	
	if (walls->r_agl == M_PI_2 || walls->r_agl == M_PI_2 * 3)
		return (FALSE);
	check_x = SIDE / 25;
	if (walls->r_agl > M_PI_2 && walls->r_agl < M_PI_2 * 3)
		check_x = -SIDE;
	if (walls->r_agl > M_PI_2 && walls->r_agl < M_PI_2 * 3)
		wall_x = (int)(lvl->player.pos_x / SIDE) * SIDE - 1;
	else
		wall_x = (int)(lvl->player.pos_x / SIDE) * SIDE + SIDE;
	check_y = (SIDE * walls->t_agl) / 25;
	wall_y = lvl->player.pos_y + (lvl->player.pos_x - wall_x) * walls->t_agl;
	while (/*(int)(wall_y / SIDE) >= 0 && (int)(wall_x / SIDE) >= 0 &&
		lvl->area.map[(int)(wall_y / SIDE)] &&
		(int)(wall_x / SIDE) < lvl->area.lines_length[(int)(wall_y / SIDE)]
		&&*/ lvl->area.map[(int)(wall_y) / SIDE][(int)(wall_x) / SIDE] != '1')
	{
		wall_y += check_y;
		wall_x += check_x;
	}
	walls->v_wall_x = wall_x;
	walls->v_wall_y = wall_y;
	return (TRUE);
}

void	cub_render(t_game *game)
{
	int		pix_y;
	int		pix_x;
	t_walls	walls;
	double	pi2;

	pi2 = game->screen.resolution.pi_2;
	walls.r_agl = (game->level.player.dir + (
			game->screen.resolution.width_mdl *
			game->screen.resolution.r_o_s));
	pix_x = -1;
	while (++pix_x < game->screen.resolution.width)
	{
		if (walls.r_agl > pi2)
			walls.r_agl = walls.r_agl - pi2;
		else if (walls.r_agl < 0)
			walls.r_agl = pi2 - walls.r_agl;
		walls.t_agl = tan(walls.r_agl);
		walls.c_agl = cos(walls.r_agl);
		walls.h_wall = cub_dda_hrztl(&(game->level), &walls);
		walls.v_wall = cub_dda_vrtcl(&(game->level), &walls);
//		if (walls.h_wall && walls.v_wall)
//		{
//			if (abs(game->level.player.pos_x - walls.h_wall_x) / walls.c_agl < abs(game->level.player.pos_x - walls.v_wall_x) / walls.c_agl)
//
//			else
//
//		}
//		else if (walls.h_wall)
//		
//		else
//		
		walls.r_agl -= game->screen.resolution.r_o_s;
	}
	cub_map_render(game);
}