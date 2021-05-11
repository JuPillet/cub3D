/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_area.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:48:57 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/11 19:37:53 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_fd(char *msg, const char *msg2, t_parser *parser)
{
	if (parser->line)
		free(parser->line);
	parser->line = 0;
	if (parser->line_map)
		free(parser->line_map);
	parser->line_map = 0;
	if (parser->fd > 2)
		close(parser->fd);
	parser->fd = 0;
	if (parser->fd_map > 2)
		close(parser->fd_map);
	parser->fd_map = 0;
	if (msg)
		return(ft_error(msg, msg2));
	return (TRUE);
}

t_bool	cub_free_area(t_area **area)
{
	int	indmap;

	if (!(*area))
		return (FALSE);
	indmap = 0;
	while (((*area)->map)[indmap])
	{
		ft_free_char(&(((*area)->map)[indmap]));
		((*area)->map[indmap]) = 0;
	}
	free((*area)->map);
	(*area)->map = 0;
	free((*area)->lines_length);
	(*area)->lines_length = 0;
	*area = 0;
}