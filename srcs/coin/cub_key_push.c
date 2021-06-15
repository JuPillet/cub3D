/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:41:19 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/15 18:01:53 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int	cub_player_front_move(t_game *game)
{
	char	**map;
	double	*p_x;
	double	*p_y;
	double	o_s_x;
	double	o_s_y;

	map = game->level.area.map;
	p_x = &(game->level.player.pos_x);
	p_y = &(game->level.player.pos_y);
	o_s_x = 5 * cos(game->level.player.dir);
	o_s_y = 5 * sin(game->level.player.dir);
	if (game->keys.z && map[((int)(*p_y - o_s_y) / SIDE)]
		[((int)(*p_x + o_s_x) / SIDE)] != '1')
	{
		*p_x += o_s_x;
		*p_y -= o_s_y;
	}
	else if (game->keys.s && map[((int)(*p_y + o_s_y) / SIDE)]
		[((int)(*p_x - o_s_x) / SIDE)] != '1')
	{
		*p_x -= o_s_x;
		*p_y += o_s_y;
	}
	return (0);
}

int	cub_player_lateral_move(t_game *game)
{
	char	**map;
	double	*p_x;
	double	*p_y;
	double	o_s_x;
	double	o_s_y;

	map = game->level.area.map;
	p_x = &(game->level.player.pos_x);
	p_y = &(game->level.player.pos_y);
	o_s_x = 5 * sin(game->level.player.dir);
	o_s_y = 5 * cos(game->level.player.dir);
	if (game->keys.q && map[((int)(*p_y - o_s_y) / SIDE)]
		[((int)(*p_x - o_s_x) / SIDE)] != '1')
	{
			*p_x -= o_s_x;
			*p_y -= o_s_y;
	}
	else if (game->keys.d && map[((int)(*p_y + o_s_y) / SIDE)]
		[((int)(*p_x + o_s_x) / SIDE)] != '1')
	{
		*p_x += o_s_x;
		*p_y += o_s_y;
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