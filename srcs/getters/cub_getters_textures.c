/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_getters_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:10:37 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/16 15:39:51 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int	cub_get_texture_sprite(char *addr, t_sprite *sprt, double sprt_y)
{
	return (*(((int *)(addr))
		+ ((int)(sprt_y) * SIDE)
		+ ((int)(sprt->sprite_x))));
}

int	cub_get_texture_wall(t_level *level, t_textures *txtrs)
{
	if (txtrs->ori_wall == 'N')
		return (*(((int *)(level->no.addr))
			+ ((int)(txtrs->texture_y) * SIDE)
			+ txtrs->texture_x));
	else if (txtrs->ori_wall == 'E')
		return (*(((int *)(level->ea.addr))
			+ ((int)(txtrs->texture_y) * SIDE)
			+ txtrs->texture_x));
	else if (txtrs->ori_wall == 'S')
		return (*(((int *)(level->so.addr))
			+ ((int)(txtrs->texture_y) * SIDE)
			+ txtrs->texture_x));
	else
		return (*(((int *)(level->we.addr))
			+ ((int)(txtrs->texture_y) * SIDE)
			+ txtrs->texture_x));
}