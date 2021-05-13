/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_getters_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:52:19 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/14 00:22:08 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_get_setting_line(t_parser *parser, const char *file)
{
	if (parser->line)
		free(parser->line);
	parser->line = 0;
	parser->eof = get_next_line(parser->fd, &(parser->line));
	if (parser->eof == -1)
		return (ft_error("the program failed to read the configuration file",
				file));
	return (ft_gnl_status(parser->eof, file));
}
