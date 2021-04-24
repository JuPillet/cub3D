/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checkers_map_column.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:50:35 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/24 17:27:07 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

static t_bool	cub_check_map_column_outdoor(char **line, int *indclmn)
{
	if((line[*indclmn][indln] == ' ' || line[*indclmn][indln] == '\t')
		&& line[(*indclmn)  + 1][indln] && line[(*indclmn)  + 1][*indln] != ' '
		&& [(*indclmn)  + 1][*indln] != '\t' && line[(*indln) + 1] != '1')
		return (FALSE);
	return (TRUE);
}

static t_bool	cub_check_map_column_wall(char *line, int *indln)
{
	if (line[*indln] == '1' && line[(*indln) + 1] && line[(*indln) + 1] != ' '
		&& line[(*indln) + 1] != '\t' && line[(*indln) + 1] != '0'
		&& line[(*indln) + 1] != '1' && line[(*indln) + 1] != '2'
		&& line[(*indln) + 1] != 'N' && line[(*indln) + 1] != 'E'
		&& line[(*indln) + 1] != 'S' && line[(*indln) + 1] != 'W')
		return (FALSE);
	return (TRUE);
}

static t_bool	cub_check_map_column_indoor(char *line, int *indln)
{
	if((line[*indln] == '0' || line[*indln] == '2' || line[*indln] == 'N'
		|| line[*indln] == 'E' || line[*indln] == 'S' || line[*indln] == 'W')
		&& line[(*indln) + 1] && line[(*indln) + 1] != '0'
		&& line[(*indln) + 1] != '1' && line[(*indln) + 1] != '2'
		&& line[(*indln) + 1] != 'N' && line[(*indln) + 1] != 'E'
		&& line[(*indln) + 1] != 'S' && line[(*indln) + 1] != 'W')
		return (FALSE);
	return (TRUE);
}

t_bool	cub_check_map_column(char *line, int *indln)
{
	(*indln)--;
	while (line[++(*indln)])
	{
		if (line[*indln] != ' ' && line[*indln] != '\t' && line[(*indln) + 1]
			&& line[*indln] != '0' && line[*indln] != '1' && line[*indln] != '2'
			&& line[*indln] != 'N' && line[*indln] != 'E' && line[*indln] != 'S'
			&& line[*indln] != 'W')
			return (FALSE);
		if (!cub_check_map_line_outdoor(line, indln)
			&& !cub_check_map_line_wall(line, indln)
			&& !cub_check_map_line_indoor(line, indln))
			return (FALSE);
	}
	return (TRUE);
}
