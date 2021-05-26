/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:53:52 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/27 00:47:26 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_dda_check_map(t_area *area, int map_y, int map_x)
{
	if ((map_y >= 0 && map_y < area->map_height) && (map_x >= 0 
		&& map_x < area->lines_length[map_y]))
		return (TRUE);
	return (FALSE);
}

t_bool	cub_dda_check_vrtcl_wall(t_game *game, t_walls *walls,
	int *map_y, int *map_x)
{
	//printf("check_x %f\n", walls->check_x);
	//printf("check_y %f\n", walls->check_y);
	//printf("v_wall_x %d\n", walls->vx_wall);
	//printf("v_wall_y %f\n", walls->vy_wall);
	//printf("pos_y %f\n", game->level.player.pos_y);
	//printf("t_agl %f\n", walls->t_agl);
	//printf("map_x %d\n", *map_x);
	//printf("map_y %d\n", *map_y);
	if (game->level.area.map[*map_y][*map_x] == '1')
		return (TRUE);
	walls->vx_wall += walls->check_x;
	*map_x = (int)(walls->vx_wall / SIDE);
	if (walls->c_agl == -1 || walls->c_agl == 1)
		return(FALSE);
	walls->vy_wall += walls->check_y;
	*map_y = (int)(walls->vy_wall / SIDE);
	return (FALSE);
}

t_bool	cub_dda_vrtcl(t_game *game, t_level *lvl, t_walls *walls)
{
	int	map_y;
	int	map_x;
	
	if (walls->s_agl == -1 || walls->s_agl == 1)
		return (FALSE);
	if (walls->c_agl < 0)
		walls->vx_wall = (SIDE * (int)(lvl->player.pos_x / SIDE)) - 1;
	else
		walls->vx_wall = (SIDE * (int)(lvl->player.pos_x / SIDE)) + SIDE;
	walls->check_x = SIDE;
	if (walls->c_agl < 0)
		walls->check_x *= -1;
	walls->vy_wall = lvl->player.pos_y;
	if (walls->c_agl != -1 && walls->c_agl != 1)
		walls->vy_wall -= ((lvl->player.pos_x - walls->vx_wall) * walls->t_agl);
	walls->check_y = SIDE * walls->t_agl;
	if (walls->c_agl < 0)
		walls->check_y *= -1;
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
	if (walls->s_agl == -1 || walls->s_agl == 1)
		return (FALSE);
	walls->hx_wall += walls->check_x;
	*map_x = (int)(walls->hx_wall / SIDE);
	return (FALSE);
}

t_bool	cub_dda_hrztl(t_game *game, t_level *lvl, t_walls *walls)
{
	int	map_y;
	int	map_x;

	if (walls->c_agl == -1 || walls->c_agl == 1)
		return (FALSE);
	if (walls->s_agl > 0)
		walls->hy_wall = (int)(SIDE * (int)(lvl->player.pos_y / SIDE)) - 1;
	else
		walls->hy_wall = (int)(SIDE * (int)(lvl->player.pos_y / SIDE)) + SIDE;
	walls->check_y = SIDE;
	if (walls->s_agl > 0)
		walls->check_y *= -1;
	walls->hx_wall = lvl->player.pos_x;
	if (walls->s_agl != -1 && walls->s_agl != 1)
		walls->hx_wall += ((lvl->player.pos_y - walls->hy_wall) / walls->t_agl);
	walls->check_x = SIDE / walls->t_agl;
	if (walls->s_agl < 0)
		walls->check_x *= -1 ;
	map_y = (int)(walls->hy_wall / SIDE);
	map_x = (int)(walls->hx_wall / SIDE);
	while (cub_dda_check_map(&(lvl->area), map_y, map_x))
		if (cub_dda_check_hrztl_wall(game, walls, &map_y, &map_x))
			return (TRUE);
	return (FALSE);
}
