/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:47:56 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/25 14:34:08 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_dispacher_fnct(int indpf, t_parser *parser, t_game *game)
{
	t_pt_fnct	fnct;

	fnct = game->hash_array[indpf].pt_fonction;
	parser->indln += game->hash_array[indpf].keylen;
	if (!(fnct(parser, game)))
	{
		parser->eof = -1;
		return (FALSE);
	}
	return (TRUE);
}

t_bool	cub_dispatcher(const char *file, t_parser *parser, t_game *game)
{
	int				indpf;
	char			*line;
	int				indln;

	line = parser->line;
	indln = 0;
	while (line[indln] == ' ' || line[indln] == '\t')
		indln++;
	if (!(line[indln]))
		return (TRUE);
	if (cub_check_start_map(line, indln))
		return (FALSE);
	indpf = -1;
	parser->indln = indln;
	while (++indpf < 8)
		if (!ft_strncmp(game->hash_array[indpf].key,
				(parser->line + indln),
				game->hash_array[indpf].keylen))
			return (cub_dispacher_fnct(indpf, parser, game));
	parser->eof = -1;
	return (TRUE);
}

t_bool	cub_parser(const char *file, t_game *game)
{
	t_bool		loop;

	if (!cub_set_parser(file, &(game->parser)))
		return (FALSE);
	game->parser.eof = 1;
	loop = TRUE;
	while (game->parser.eof == 1 && loop == TRUE)
	{
		if (!cub_get_setting_line(&(game->parser), file))
			return (FALSE);
		loop = cub_dispatcher(file, &(game->parser), game);
	}
	if (game->parser.eof == -1 && loop == FALSE)
		return (FALSE);
	if (game->parser.eof == -1 && loop == TRUE)
		return (ft_error("unknown element line", game->parser.line));
	if (!(game->parser.eof))
		return (ft_error("setting file need a map", 0));
	if (!cub_check_before_map(game))
		return (ft_error("setting file hasn't all prerequisite before map", 0));
	if (!cub_parse_map(&(game->parser), game, file, 0))
		return (FALSE);
	return (cub_check_map(game));
}

t_bool	cub_norm_file(const char *file, t_game *game)
{
	int	indfl;

	indfl = 0;
	while (file[indfl])
		indfl++;
	if (indfl > 3 && (file[--indfl] == 'b' || file[indfl] == 'B')
		&& (file[--indfl] == 'u' || file[indfl] == 'U')
		&& (file[--indfl] == 'c' || file[indfl] == 'C')
		&& file[--indfl] == '.')
		return (cub_parser(file, game));
	return (ft_error("wrong extension name", file));
}
