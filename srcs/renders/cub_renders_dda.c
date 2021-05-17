/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:53:52 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/17 00:10:16 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_dda_check_vrtcl_wall(t_area *area, t_walls *walls, int map_y, int map_x)
{
	if (area->map[map_y][map_x] == '1')
	{
		walls->v_wall = TRUE;
		return (TRUE);
	}
	walls->v_wall_y += walls->check_y;
	walls->v_wall_x += walls->check_x;
	return (FALSE);
}

t_bool	cub_dda_check_map(t_area *area, int map_y, int map_x)
{
	if (map_y >= 0 && map_x >= 0 && map_y < area->map_height
		&& map_x < area->lines_length[map_y])
		return (TRUE);
	return (FALSE);
}

t_bool	cub_dda_vrtcl(t_level *lvl, t_walls *walls)
{
	int map_y;
	int map_x;
	
	if (walls->r_agl == M_PI_2 || walls->r_agl == M_PI_2 * 3)
		return (FALSE);
	walls->check_x = SIDE;
	if (walls->r_agl > M_PI_2 && walls->r_agl < M_PI_2 * 3)
		walls->check_x = -(walls->check_x);
	if (walls->r_agl > M_PI_2 && walls->r_agl < M_PI_2 * 3)
		walls->v_wall_x = (int)(lvl->player.pos_x / SIDE) * SIDE - 1;
	else
		walls->v_wall_x = (int)(lvl->player.pos_x / SIDE) * SIDE + SIDE;
	walls->check_y = SIDE * walls->t_agl;
	walls->v_wall_y = lvl->player.pos_y + (lvl->player.pos_x - walls->v_wall_x) * walls->t_agl;
	while (TRUE)
	{
		map_y = (int)(walls->h_wall_y / SIDE);
		map_x = (int)(walls->h_wall_x / SIDE);
		if (!cub_dda_check_map(&(lvl->area), map_y, map_x))
			return (FALSE);
		if (cub_dda_check_vrtcl_wall(&(lvl->area), walls, map_y, map_x))
			return (TRUE);
	}
}

t_bool	cub_dda_check_hrztl_wall(t_area *area, t_walls *walls, int map_y, int map_x)
{
	if (area->map[map_y][map_x] == '1')
	{
		walls->h_wall = TRUE;
		return (TRUE);
	}
	walls->h_wall_y += walls->check_y;
	walls->h_wall_x += walls->check_x;
	return (FALSE);
}

t_bool	cub_dda_hrztl(t_level *lvl, t_walls *walls)
{
	int map_y;
	int map_x;

	if (walls->r_agl == M_PI || walls->r_agl == 0)
		return (FALSE);
	walls->check_y = SIDE;
	if (walls->r_agl < M_PI && walls->r_agl > 0)
		walls->check_y = -(walls->check_y);
	if (walls->r_agl < M_PI && walls->r_agl > 0)
		walls->h_wall_y = (int)(lvl->player.pos_y / SIDE) * SIDE - 1;
	else
		walls->h_wall_y = (int)(lvl->player.pos_y / SIDE) * SIDE + SIDE;
	walls->check_x = SIDE / walls->t_agl;
	walls->h_wall_x = lvl->player.pos_x + (lvl->player.pos_y - walls->h_wall_y) / walls->t_agl;
	while (TRUE)
	{
		map_y = (int)(walls->h_wall_y / SIDE);
		map_x = (int)(walls->h_wall_x / SIDE);
		if (!cub_dda_check_map(&(lvl->area), map_y, map_x))
			return (FALSE);
		if (cub_dda_check_hrztl_wall(&(lvl->area), walls, map_y, map_x))
			return (TRUE);
	}
}
