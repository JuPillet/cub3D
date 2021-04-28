/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checkers_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:33:55 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/28 11:34:12 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_check_player(char **map, t_player *player)
{
	int		location_x;
	int		location_y;

	location_x = (int)((*(player->position_x) - 32) / 64);
	location_y = (int)((*(player->position_y) - 32) / 64);
	if (map[location_y - 1][location_x] != ' '
		&& map[location_y + 1][location_x] != ' '
		&& map[location_y][location_x - 1] != ' '
		&& map[location_y][location_x + 1] != ' ')
		return (FALSE);
	return (TRUE);
}