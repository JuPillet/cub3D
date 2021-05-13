/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:50:08 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/13 19:37:40 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_set_parser(const char *file, t_parser *parser)
{
	parser->fd = open(file, O_RDONLY);
	parser->line = 0;
	if (parser->fd != -1)
		return (TRUE);
	return (ft_error("cub3D failed to open", file));
}

t_bool	cub_set_int(char *line, int *indln, int *value)
{
	while (line[*indln] == ' ' || line[*indln] == '\t')
		(*indln)++;
	if (!ft_isdigit(line[*indln])
		&& !(ft_issigned(line[*indln]) && ft_isdigit(line[(*indln) + 1])))
		return (FALSE);
	*value = ft_atoi((line + (*indln)));
	if (ft_issigned(line[*indln]))
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	return (TRUE);
}

t_bool	cub_set_double(char *line, int *indln, double *value)
{
	while (line[*indln] != ' ' || line[*indln] == '\t')
		(*indln)++;
	if (!ft_isdigit(line[*indln])
		&& (!ft_issigned(line[*indln]) || !ft_isdigit(line[(*indln) + 1])))
		return (FALSE);
	*value = ft_atof((line + (*indln)));
	if (ft_issigned(line[*indln]))
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	if (line[*indln] == '.')
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	return (TRUE);
}
