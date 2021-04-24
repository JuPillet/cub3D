/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checkers_map_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:53:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/24 21:13:20 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

static t_bool	cub_check_map_line_outdoor(char *line, int *indln)
{
	if((line[*indln] == ' ' || line[*indln] == '\t')
		&& line[(*indln) + 1] && line[(*indln) + 1] != ' '
		&& line[(*indln) + 1] != '\t' && line[(*indln) + 1] != '1')
		return (FALSE);
	return (TRUE);
}

static t_bool	cub_check_map_line_wall(char *line, int *indln)
{
	if (line[*indln] == '1' && line[(*indln) + 1] && line[(*indln) + 1] != ' '
		&& line[(*indln) + 1] != '\t' && line[(*indln) + 1] != '0'
		&& line[(*indln) + 1] != '1' && line[(*indln) + 1] != '2'
		&& line[(*indln) + 1] != 'N' && line[(*indln) + 1] != 'E'
		&& line[(*indln) + 1] != 'S' && line[(*indln) + 1] != 'W')
		return (FALSE);
	return (TRUE);
}

static t_bool	cub_check_map_line_indoor(char *line, int *indln)
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

t_bool	cub_check_map_line(char *line, int *indln)
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
