/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_renders_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:53:52 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/22 16:48:15 by jpillet          ###   ########.fr       */
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

t_bool	cub_dda_check_vrtcl_wall(t_game *game, t_textures *txtrs,
	int *map_y, int *map_x)
{
	t_sprite	*sprite;

	sprite = game->level.area.sprite;
	if (game->level.area.map[*map_y][*map_x] == '2')
	{
		while (((sprite->pos_y + 1 - (SIDE / 2)) / SIDE != *map_y)
			|| ((sprite->pos_x + 1 - (SIDE / 2)) / SIDE != *map_x))
			sprite++;
		sprite->visible = TRUE;
	}
	else if (game->level.area.map[*map_y][*map_x] == '1')
		return (TRUE);
	txtrs->vx_wall += txtrs->check_x;
	*map_x = (int)(txtrs->vx_wall / SIDE);
	if (txtrs->c_agl == -1 || txtrs->c_agl == 1)
		return (FALSE);
	txtrs->vy_wall += txtrs->check_y;
	*map_y = (int)(txtrs->vy_wall / SIDE);
	return (FALSE);
}

t_bool	cub_dda_vrtcl(t_game *game, t_level *lvl, t_textures *txtrs)
{
	int	map_y;
	int	map_x;

	if (txtrs->s_agl == -1 || txtrs->s_agl == 1)
		return (FALSE);
	if (txtrs->c_agl < 0)
		txtrs->vx_wall = (SIDE * (int)(lvl->player.pos_x / SIDE)) - 0.000000001;
	else
		txtrs->vx_wall = (SIDE * (int)(lvl->player.pos_x / SIDE)) + SIDE;
	txtrs->check_x = SIDE;
	if (txtrs->c_agl < 0)
		txtrs->check_x *= -1;
	txtrs->vy_wall = lvl->player.pos_y;
	if (txtrs->c_agl != -1 && txtrs->c_agl != 1)
		txtrs->vy_wall -= ((lvl->player.pos_x - txtrs->vx_wall) * txtrs->t_agl);
	txtrs->check_y = SIDE * txtrs->t_agl;
	if (txtrs->c_agl < 0)
		txtrs->check_y *= -1;
	map_y = (int)(txtrs->vy_wall / SIDE);
	map_x = (int)(txtrs->vx_wall / SIDE);
	while (cub_dda_check_map(&(lvl->area), map_y, map_x))
		if (cub_dda_check_vrtcl_wall(game, txtrs, &map_y, &map_x))
			return (TRUE);
	return (FALSE);
}

t_bool	cub_dda_check_hrztl_wall(t_game *game, t_textures *txtrs,
	int *map_y, int *map_x)
{
	t_sprite	*sprite;

	sprite = game->level.area.sprite;
	if (game->level.area.map[*map_y][*map_x] == '2')
	{
		while ((((sprite->pos_y + 1) - (SIDE / 2)) / SIDE != *map_y)
			|| (((sprite->pos_x + 1) - (SIDE / 2)) / SIDE != *map_x))
			sprite++;
		sprite->visible = TRUE;
	}
	else if (game->level.area.map[*map_y][*map_x] == '1')
		return (TRUE);
	txtrs->hy_wall += txtrs->check_y;
	*map_y = (int)(txtrs->hy_wall / SIDE);
	if (txtrs->s_agl == -1 || txtrs->s_agl == 1)
		return (FALSE);
	txtrs->hx_wall += txtrs->check_x;
	*map_x = (int)(txtrs->hx_wall / SIDE);
	return (FALSE);
}

t_bool	cub_dda_hrztl(t_game *game, t_level *lvl, t_textures *txtrs)
{
	int	map_y;
	int	map_x;

	if (txtrs->c_agl == -1 || txtrs->c_agl == 1)
		return (FALSE);
	if (txtrs->s_agl > 0)
		txtrs->hy_wall = (SIDE * (int)(lvl->player.pos_y / SIDE)) - 0.000000001;
	else
		txtrs->hy_wall = (SIDE * (int)(lvl->player.pos_y / SIDE)) + SIDE;
	txtrs->check_y = SIDE;
	if (txtrs->s_agl > 0)
		txtrs->check_y *= -1;
	txtrs->hx_wall = lvl->player.pos_x;
	if (txtrs->s_agl != -1 && txtrs->s_agl != 1)
		txtrs->hx_wall += ((lvl->player.pos_y - txtrs->hy_wall) / txtrs->t_agl);
	txtrs->check_x = SIDE / txtrs->t_agl;
	if (txtrs->s_agl < 0)
		txtrs->check_x *= -1 ;
	map_y = (int)(txtrs->hy_wall / SIDE);
	map_x = (int)(txtrs->hx_wall / SIDE);
	while (cub_dda_check_map(&(lvl->area), map_y, map_x))
		if (cub_dda_check_hrztl_wall(game, txtrs, &map_y, &map_x))
			return (TRUE);
	return (FALSE);
}
