/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:48:57 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 23:53:51 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_map(char **map)
{
	int	indmap;

	indmap = 0;
	if (!map)
		return (FALSE);
	while (map[indmap])
	{
		free(map[indmap]);
		map[indmap] = 0;
		indmap++;
	}
	free(map);
}

t_bool	cub_free_area(t_area **area)
{

	if (!(*area))
		return (FALSE);
	cub_free_map((*area)->map);
	(*area)->map = 0;
	free((*area)->lines_length);
	(*area)->lines_length = 0;
	free(*area);
	*area = 0;
	return (TRUE);
}
