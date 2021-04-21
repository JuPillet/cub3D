/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mallocers_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:26:04 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/21 21:06:38 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_malloc_map_column(char *line, int indln, int column, char *linemap)
{
	int	tabulation;

	while (line[indln])
	{
		if (line[indln] != ' ' && line[indln] != '\t' && line[indln] != '0'
			&& line[indln] != '1' && line[indln] != '2' && !line[indln] != 'N'
			&& line[indln] != 'S' && line[indln] != 'E' && line[indln] != 'W')
			return (FALSE);
		if (line[indln++] == '\t')
			column += (4 - (column % 4));
		else
			column++;
	}
	if (!ft_malloc_char(column + 1, &linemap))
		return (ft_error("program didn't find memory to load", 0));
	cub_set_map_column(line, linemap);
	return (TRUE);
}