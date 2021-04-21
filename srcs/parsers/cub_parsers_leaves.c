/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsers_leaves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:33:12 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/21 17:54:33 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool cub_check_orientation(t_player *player)
{
	if (*(orientation->x_coord) < -1 || *(orientation->x_coord) > 1
		|| *(orientation->y_coord) < -1 || *(orientation->y_coord) > 1
		|| *(orientation->z_coord) < -1 || *(orientation->z_coord) > 1)
		return (FALSE);
	return (TRUE);
}

t_bool	cub_parse_color(char *line, int *indln, t_color *color)
{
	if (!cub_set_int(line, indln, color->r))
		return (FALSE);
	if (line[(*indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(line[*indln]))
		return (FALSE);
	if (!cub_set_int(line, indln, color->g))
		return (FALSE);
	if (line[(*indln)++] != ',')
		return (FALSE);
	if (!ft_isdigit(line[*indln]))
		return (FALSE);
	if (!cub_set_int(line, indln, color->b))
		return (FALSE);
	if (*(color->r) < 0 || *(color->r) > 255 || *(color->g) < 0
		|| *(color->g) > 255 || *(color->b) < 0 || *(color->b) > 255)
		return (FALSE);
	*(color->a) = 0;
	*(color->argb) = cub_set_argb(*(color->a), *(color->r),
		*(color->g), *(color->b));
	return(TRUE);
}
