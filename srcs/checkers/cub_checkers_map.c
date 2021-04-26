/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_checkers_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:43:49 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/26 17:27:13 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_check_after_map(t_parser *parser)
{
	while (parser->eof == 1)
	{
		parser->indln = -1;
		while (parser->line[++(parser->indln)])
			if (!ft_isspace(parser->line[parser->indln]))
				return (FALSE);
		free(parser->line);
		parser->eof = get_next_line(parser->fd, &(parser->line));
	}
}

t_bool	cub_check_durring_map(int *malloc_line, t_parser *parser)
{
	if (cub_check_map_line(parser->line, parser->indln))
	{
		malloc_line++;
		free(parser->line);
		parser->eof = get_next_line(parser->fd, &(parser->line));
		return (TRUE);
	}
	return (cub_free_fd("the setting file has an invalid map format", parser));
}

t_bool	cub_check_before_map(t_game *game)
{
	if (*(game->screen->resolution->is) && *(game->level->no->is)
		&& *(game->level->so->is) && *(game->level->we->is)
		&& *(game->level->ea->is) && *(game->level->floor->is)
		&& *(game->level->ceiling->is) && *(game->level->player->is))
		return (FALSE);
	return (TRUE);
}

t_bool	cub_check_start_map(char *line, int indln)
{
	if (line[indln] == '0' || line[indln] == '1' || line[indln] == '2'
		|| (line[indln] == 'N' && (line[indln + 1] == '0'
				|| line[indln + 1] == '1' || line[indln + 1] == '2'))
		|| (line[indln] == 'E' && (line[indln + 1] == '0'
				|| line[indln + 1] == '1' || line[indln + 1] == '2'))
		|| (line[indln] == 'S' && (line[indln + 1] == '0'
				|| line[indln + 1] == '1' || line[indln + 1] == '2'))
		|| (line[indln] == 'W' && (line[indln + 1] == '0'
				|| line[indln + 1] == '1' || line[indln + 1] == '2')))
		return (TRUE);
	return (FALSE);
}
