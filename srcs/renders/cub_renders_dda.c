/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:53:52 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/20 02:47:21 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_dda_check_map(t_area *area, int map_y, int map_x)
{
	if (map_y >= 0 && map_x >= 0 && map_y < area->map_height
		&& map_x < area->lines_length[map_y])
		return (TRUE);
	return (FALSE);
}

t_bool	cub_dda_check_vrtcl_wall(t_game *game, t_walls *walls,
	int *map_y, int *map_x)
{
	if (game->level.area.map[*map_y][*map_x] == '1')
		return (TRUE);
	walls->vx_wall += walls->check_x;
	*map_x = (int)(walls->vx_wall / SIDE);
	walls->vy_wall += walls->check_y;
	*map_y = (int)(walls->vy_wall / SIDE);
	return (FALSE);
}

t_bool	cub_dda_vrtcl(t_game *game, t_level *lvl, t_walls *walls)
{
	int	map_y;
	int	map_x;

	walls->vx_wall = (SIDE * (int)(lvl->player.pos_x / SIDE));
	if (walls->r_agl > M_PI_2 && walls->r_agl < game->deg.r270)
		 walls->vx_wall -= 1;
	else
		walls->vx_wall += SIDE;
	walls->check_x = SIDE;
	if (walls->r_agl > M_PI_2 && walls->r_agl < game->deg.r270)
	walls->check_x = -(walls->check_x);
	walls->check_y = SIDE * walls->t_agl;
	walls->vy_wall = lvl->player.pos_y;
	walls->vy_wall += (lvl->player.pos_x - walls->vx_wall) * walls->t_agl;
	map_y = (int)(walls->vy_wall / SIDE);
	map_x = (int)(walls->vx_wall / SIDE);
	while (cub_dda_check_map(&(lvl->area), map_y, map_x))
		if (cub_dda_check_vrtcl_wall(game, walls, &map_y, &map_x))
			return (TRUE);
	return (FALSE);
}

t_bool	cub_dda_check_hrztl_wall(t_game *game, t_walls *walls,
	int *map_y, int *map_x)
{
	if (game->level.area.map[*map_y][*map_x] == '1')
		return (TRUE);
	walls->hy_wall += walls->check_y;
	*map_y = (int)(walls->hy_wall / SIDE);
	walls->hx_wall += walls->check_x;
	*map_x = (int)(walls->hx_wall / SIDE);
	return (FALSE);
}

t_bool	cub_dda_hrztl(t_game *game, t_level *lvl, t_walls *walls)
{
	int	map_y;
	int	map_x;

	walls->hy_wall = (SIDE * (int)(lvl->player.pos_y / SIDE)) ;
	if (walls->r_agl < M_PI && walls->r_agl > 0)
		walls->hy_wall -= 1;
	else
		walls->hy_wall += SIDE;
	walls->check_y = SIDE;
	if (walls->r_agl < M_PI && walls->r_agl > 0)
		walls->check_y = -(walls->check_y);
	walls->hx_wall = lvl->player.pos_x;
	walls->hx_wall += ((lvl->player.pos_y - walls->hy_wall) / walls->t_agl);
	walls->check_x = SIDE / walls->t_agl;
	map_y = (int)(walls->hy_wall / SIDE);
	map_x = (int)(walls->hx_wall / SIDE);
	while (cub_dda_check_map(&(lvl->area), map_y, map_x))
		if (cub_dda_check_hrztl_wall(game, walls, &map_y, &map_x))
			return (TRUE);
	return (FALSE);
}
