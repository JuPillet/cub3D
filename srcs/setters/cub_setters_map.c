/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:35:06 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/17 19:59:49 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_set_map_column(char *line, int indln, int column, char *linemap)
{
	int	tabulation;

	while (line[indln])
	{
		if (!ft_isspace(line[indln]) && line[indln] != '0'&& line[indln] != '1'
			&& line[indln] != '2' && !line[indln] != 'N' && line[indln] != 'S'
			&& line[indln] != 'E' && line[indln] != 'W')
			return (FALSE);
		if (line[indln++] == '\t')
			column += 4;
		else
			column++;
	}
	ft_malloc_char(column + 1, &linemap);
	linemap[column] = '\0';
	while (indln--)
	{
		tabulation = 4;
		if (line[indln] == '\t')
			while (tabulation--)
				linemap[column--] = '0';
		else
			linemap[column] = line[indln];
	}
}