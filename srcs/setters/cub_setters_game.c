/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:29:22 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/25 23:40:44 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_init_hash_array(t_hash_array *hash_array)
{
	hash_array[0].key = "NO";
	hash_array[1].key = "EA";
	hash_array[2].key = "SO";
	hash_array[3].key = "WE";
	hash_array[4].key = "S";
	hash_array[5].key = "R";
	hash_array[6].key = "C";
	hash_array[7].key = "F";
	hash_array[0].keylen = 2;
	hash_array[1].keylen = 2;
	hash_array[2].keylen = 2;
	hash_array[3].keylen = 2;
	hash_array[4].keylen = 1;
	hash_array[5].keylen = 1;
	hash_array[6].keylen = 1;
	hash_array[7].keylen = 1;
	hash_array[0].pt_fonction = &cub_parse_texture_north;
	hash_array[1].pt_fonction = &cub_parse_texture_east;
	hash_array[2].pt_fonction = &cub_parse_texture_south;
	hash_array[3].pt_fonction = &cub_parse_texture_west;
	hash_array[4].pt_fonction = &cub_parse_texture_sprite;
	hash_array[5].pt_fonction = &cub_parse_resolution;
	hash_array[6].pt_fonction = &cub_set_horizon;
	hash_array[7].pt_fonction = &cub_set_horizon;
}

t_bool	cub_malloc_hash_array(t_game *game)
{
	int	indha;
	int	keylen;

	game->hash_array = (t_hash_array *)malloc(8 * sizeof(t_hash_array));
	if (!(game->hash_array))
		return (FALSE);
	cub_init_hash_array(game->hash_array);
	return (TRUE);
}

t_bool	cub_init_screen(t_game *game)
{
	game->screen.resolution.is = FALSE;
	game->screen.resolution.width = 0;
	game->screen.resolution.height = 0;
	game->screen.resolution.width_mdl = 0;
	game->screen.resolution.height_mdl = 0;
	game->screen.resolution.r_o_s_pix = 0;
	return (TRUE);
}

t_bool	cub_init_degree(t_degree *deg)
{
	deg->r1 = M_PI / 180;
	deg->r135 = M_PI_4 + M_PI_2;
	deg->r225 = deg->r135 + M_PI_2;
	deg->r270 = M_PI + M_PI_2;
	deg->r315 = deg->r225 + M_PI_2;
	deg->r360 = (M_PI * 2);
	return (TRUE);
}

t_bool	cub_init_level(t_game *game)
{
	game->level.no = 0;
	game->level.so = 0;
	game->level.we = 0;
	game->level.ea = 0;
	game->level.sp = 0;
	game->level.floor.is = FALSE;
	game->level.ceiling.is = FALSE;
	game->level.player.is = FALSE;
	game->level.player.dir = 0;
	game->level.player.pos_x = 0;
	game->level.player.pos_y = 0;
	cub_init_screen(game);
	cub_init_color(&(game->level.floor.color));
	cub_init_color(&(game->level.ceiling.color));
	game->level.area.map = 0;
	game->level.area.lines_length = 0;
	return (TRUE);
}

t_bool	cub_init_game(t_game *game)
{
	if (!(game))
		return (FALSE);
	game->hash_array = 0;
	game->parser.fd = -1;
	game->parser.line = 0;
	game->parser.indln = 0;
	game->parser.eof = 1;
	game->screen.mlx_screen = 0;
	game->screen.pic_screen.img = 0;
	game->screen.pic_screen.addr = 0;
	game->mlx = mlx_init();
	cub_init_degree(&(game->deg));
	cub_init_screen(game);
	cub_malloc_hash_array(game);
	cub_init_level(game);
	if (!(game->mlx) || !(game->hash_array))
		return (ft_error("cub3D didn't find the memory to load", 0));
	return (TRUE);
}
