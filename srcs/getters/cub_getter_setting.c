/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_getter_setting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:40:10 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/27 20:02:10 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_get_setting_line(t_parser *parser, const char *file)
{
	if (parser->line > 0)
		free(parser->line);
	parser->line = 0;
	if (parser->line_map > 0)
		free(parser->line_map);
	parser->line_map = 0;
	parser->eof = get_next_line(parser->fd, &(parser->line));
	if (!parser->eof)
		return (cub_free_fd("the program failed to read the configuration file",
				file, parser));
	parser->eof = get_next_line(parser->fd_map, &(parser->line_map));
	if (!parser->eof)
		return (cub_free_fd("the program failed to read the configuration file",
				file, parser));
	return (ft_gnl_status(parser->eof, parser->line, parser->fd, file));
}