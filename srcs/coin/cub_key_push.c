/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_key_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:41:19 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/24 16:57:32 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int	cub_player_front_move(int key_code, t_game *game)
{
	char	**map;
	double	*p_x;
	double	*p_y;
	double	o_s_x;
	double	o_s_y;

	map = game->level.area.map;
	p_x = &(game->level.player.pos_x);
	p_y = &(game->level.player.pos_y);
	o_s_x = 7 * cos(game->level.player.dir);
	o_s_y = 7 * sin(game->level.player.dir);
	if (key_code == K_W	&& map[((int)(*p_y - o_s_y) / SIDE)]
		[((int)(*p_x - o_s_x) / SIDE)] == '0')
	{
		*p_x += o_s_x;
		*p_y -= o_s_y;
	}
	else if (key_code == K_S && map[((int)(*p_y + o_s_y) / SIDE)]
		[((int)(*p_x + o_s_x) / SIDE)] == '0')
	{
		*p_x -= o_s_x;
		*p_y += o_s_y;
	}
	return (0);
}

int	cub_player_lateral_move(int key_code, t_game *game)
{
	char	**map;
	double	*p_x;
	double	*p_y;
	double	o_s_x;
	double	o_s_y;

	map = game->level.area.map;
	p_x = &(game->level.player.pos_x);
	p_y = &(game->level.player.pos_y);
	o_s_x = 7 * sin(game->level.player.dir);
	o_s_y = 7 * cos(game->level.player.dir);
	if (key_code == K_A && map[((int)(*p_y - o_s_y) / SIDE)]
		[((int)(*p_x - o_s_x) / SIDE)] == '0')
	{
		*p_x -= o_s_x;
		*p_y -= o_s_y;
	}
	else if (key_code == K_D && map[((int)(*p_y + o_s_y) / SIDE)]
		[((int)(*p_x + o_s_x) / SIDE)] == '0')
	{
		*p_x += o_s_x;
		*p_y += o_s_y;
	}
	return (0);
}

int	cub_player_rotate_move(int key_code, t_game *game)
{
	if (key_code == K_A_L)
	{
		game->level.player.dir += 0.025;
		if (game->level.player.dir >= game->deg.r360)
			game->level.player.dir = game->level.player.dir - game->deg.r360;
	}
	else if (key_code == K_A_R)
	{
		game->level.player.dir -= 0.025;
		if (game->level.player.dir < 0)
			game->level.player.dir = (M_PI * 2) + game->level.player.dir;
	}
	return (0);
}

int	cub_key_push(int key_code, t_game *game)
{
	if (key_code == K_W || key_code == K_S)
		return (cub_player_front_move(key_code, game));
	if (key_code == K_A || key_code == K_D)
		return (cub_player_lateral_move(key_code, game));
	if (key_code == K_A_L || key_code == K_A_R)
		return (cub_player_rotate_move(key_code, game));
	if (key_code == K_ESC)
		exit(cub_free_game(game));
	return (0);
}