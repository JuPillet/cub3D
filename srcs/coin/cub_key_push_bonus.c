/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key_push_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:41:19 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/22 15:34:57 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int	cub_player_front_move(t_game *game, double o_s_x, double o_s_y)
{
	char	**map;
	int		iter;

	map = game->level.area.map;
	if (game->keys.s)
		o_s_x *= -1;
	if (game->keys.s)
		o_s_y *= -1;
	iter = 5;
	while (iter--)
	{
		if (map[((int)(game->level.player.pos_y - (2 * o_s_y)) / SIDE)]
			[((int)(game->level.player.pos_x) / SIDE)] == '0')
			game->level.player.pos_y -= o_s_y;
		if (map[((int)(game->level.player.pos_y) / SIDE)]
			[((int)(game->level.player.pos_x + (2 * o_s_x)) / SIDE)] == '0')
			game->level.player.pos_x += o_s_x;
	}
	return (0);
}

int	cub_player_lateral_move(t_game *game, double o_s_x, double o_s_y)
{
	char	**map;
	int		iter;

	map = game->level.area.map;
	if (game->keys.q)
		o_s_x *= -1;
	if (game->keys.q)
		o_s_y *= -1;
	iter = 5;
	while (iter--)
	{
		if (map[((int)(game->level.player.pos_y + (2 * o_s_y)) / SIDE)]
			[((int)(game->level.player.pos_x) / SIDE)] == '0')
			game->level.player.pos_y += o_s_y;
		if (map[((int)(game->level.player.pos_y) / SIDE)]
			[((int)(game->level.player.pos_x + (2 * o_s_x)) / SIDE)] == '0')
			game->level.player.pos_x += o_s_x;
	}
	return (0);
}

int	cub_player_rotate_move(t_game *game)
{
	if (game->keys.a_l)
	{
		game->level.player.dir += 0.025;
		if (game->level.player.dir >= game->deg.r360)
			game->level.player.dir = game->level.player.dir - game->deg.r360;
	}
	else if (game->keys.a_r)
	{
		game->level.player.dir -= 0.025;
		if (game->level.player.dir < 0)
			game->level.player.dir = game->deg.r360 - fmod(game->level.player.dir, game->deg.r1);
	}
	return (0);
}

int	cub_key_push(int key_code, t_game *game)
{
	if (key_code == K_W)
		game->keys.z = TRUE;
	if (key_code == K_S)
		game->keys.s = TRUE;
	if (key_code == K_A)
		game->keys.q = TRUE;
	if (key_code == K_D)
		game->keys.d = TRUE;
	if (key_code == K_A_L)
		game->keys.a_l = TRUE;
	if (key_code == K_A_R)
		game->keys.a_r = TRUE;
	if (key_code == K_ESC)
		exit(cub_free_game(game));
	return (0);
}

int	cub_key_release(int key_code, t_game *game)
{
	if (key_code == K_W)
		game->keys.z = FALSE;
	if (key_code == K_S)
		game->keys.s = FALSE;
	if (key_code == K_A)
		game->keys.q = FALSE;
	if (key_code == K_D)
		game->keys.d = FALSE;
	if (key_code == K_A_L)
		game->keys.a_l = FALSE;
	if (key_code == K_A_R)
		game->keys.a_r = FALSE;
	return (0);
}