/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:48:57 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/26 23:37:45 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_fd(char *msg, const char *file, t_parser *parser)
{
	if (parser->line)
		free(parser->line);
	if (parser->line_map)
		free(parser->line_map);
	if (parser->fd > 2)
		close(parser->fd);
	if (parser->fd_map > 2)
		close(parser->fd_map);
	return(ft_error(msg, file));
}

t_bool	cub_free_area(char ***area)
{
	int	indmap;

	if (!(*area))
		return (FALSE);
	indmap = 0;
	while ((*area)[indmap] != 0)
		ft_free_char(&((*area)[indmap]));
	free(*area);
	*area = 0;
}