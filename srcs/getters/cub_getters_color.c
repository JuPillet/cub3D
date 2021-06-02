/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_getters_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:10:37 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/03 00:03:19 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int	cub_get_texture(t_level *level, t_walls *walls)
{
	if (walls->ori_wall == 'N')
		return (*(((int *)(level->no.addr))
			+ ((int)(walls->texture_y) * SIDE)
			+ walls->texture_x));
	else if (walls->ori_wall == 'E')
		return (*(((int *)(level->ea.addr))
			+ ((int)(walls->texture_y) * SIDE)
			+ walls->texture_x));
	else if (walls->ori_wall == 'S')
		return (*(((int *)(level->so.addr))
			+ ((int)(walls->texture_y) * SIDE)
			+ walls->texture_x));
	else
		return (*(((int *)(level->we.addr))
			+ ((int)(walls->texture_y) * SIDE)
			+ walls->texture_x));
}

int	get_a(int argb)
{
	return (argb & (0xFF << 24));
}

int	get_r(int argb)
{
	return (argb & (0xFF << 16));
}

int	get_g(int argb)
{
	return (argb & (0xFF << 8));
}

int	get_b(int argb)
{
	return (argb & 0xFF);
}
