/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:10:31 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/05 13:38:22 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_set_map_color(char **map, int map_x, int map_y, int *color)
{
	if (map[map_y][map_x] == '1')
		*color = 0x663300;
	else if (map[map_y][map_x] == '0')
		*color = 0xA0A0A0;
	else if (map[map_y][map_x] == '2')
		*color = 0x836260;
}

int	cub_set_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

t_bool	cub_init_color(t_color *color)
{
	color->a = 0;
	color->r = 0;
	color->g = 0;
	color->b = 0;
	color->argb = 0;
	return (TRUE);
}
