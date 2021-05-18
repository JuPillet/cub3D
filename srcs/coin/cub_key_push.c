/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:41:19 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/18 04:01:45 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

/*
** Z = 0x007a || W = 0x0077
*/
int	cub_player_front_move(int key_code, t_game *game)
{
	char	**map;
	double	*position_x;
	double	*position_y;

	position_x = &(game->level.player.pos_x);
	position_y = &(game->level.player.pos_y);
	if (key_code == 0x007a)
	{
		game->level.player.pos_x += (7 * cos(
				game->level.player.dir));
		game->level.player.pos_y += (7 * sin(
				game->level.player.dir));
	}
	else if (key_code == 0x0073)
	{
		game->level.player.pos_x -= (7 * cos(
				game->level.player.dir));
		game->level.player.pos_y -= (7 * sin(
				game->level.player.dir));
	}
	return (0);
}

/*
** Q = 0x0071 // A = 0x0061
*/
int	cub_player_lateral_move(int key_code, t_game *game)
{
	char	**map;
	double	*position_x;
	double	*position_y;
	double	*lateral_delta_x;
	double	*lateral_delta_y;

	position_x = &(game->level.player.pos_x);
	position_y = &(game->level.player.pos_y);
//	lateral_delta_x = 
//	lateral_delta_y =
	map = game->level.area.map;
	if (key_code == 0x0071)
	{
//		game->level.player.pos_x += 7 * cos(
//			tan(game->level.player.dir));
//		game->level.player.pos_y += 7 * sin(
//			tan(game->level.player.dir));
		;
	}
	else if (key_code == 0x0064)
	{
//		game->level.player.pos_x -= 7 * cos(
//			tan(game->level.player.dir));
//		game->level.player.pos_y -= 7 * sin(
//			tan(game->level.player.dir));
		;
	}
	return (0);
}

int	cub_player_rotate_move(int key_code, t_game *game)
{
	if (key_code == 0xff51)
	{
		game->level.player.dir += 0.05;
		if (game->level.player.dir >= game->deg.d360)
			game->level.player.dir = (game->level.player.dir - game->deg.d360);
	}
	else if (key_code == 0xff53)
	{
		game->level.player.dir -= 0.05;
		if (game->level.player.dir <= 0)
			game->level.player.dir = (game->deg.d360 - game->level.player.dir);
	}
	return (0);
}

int	cub_key_push(int key_code, t_game *game)
{
	if (key_code == 0x007a || key_code == 0x0073)
		return (cub_player_front_move(key_code, game));
	if (key_code == 0x0071 || key_code == 0x0064)
		return (cub_player_lateral_move(key_code, game));
	if (key_code == 0xff51 || key_code == 0xff53)
		return (cub_player_rotate_move(key_code, game));
	if (key_code == 0xff1b)
		exit(cub_free_game(game));
	return (0);
}