/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:47:56 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/05 19:33:59 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

/*
** WIP
** parse game
** -
** -
*/

t_bool	cub_dispacher_fnct(int indpf, t_parser *parser, t_game *game)
{
	t_pt_fnct	fnct;

	fnct = *(game->hash_array[indpf].pt_fonction);
	parser->indln = *(game->hash_array[indpf].keylen);
	return (fnct(parser, game));
}

t_bool	cub_dispatcher(const char *file, t_parser *parser, t_game *game)
{
	int				indpf;
	char			*line;
	int				indln;

	line = parser->line;
	indln = parser->indln;
	while (line[indln] == ' ' || line[indln] == '\t')
		indln++;
	if (!(line[indln]))
		return (TRUE);
	indpf = -1;
	if (cub_check_start_map(line, indln))
		return (FALSE);
	while (++indpf < 8)
		if (!ft_strncmp(game->hash_array[indpf].key,
				(parser->line + parser->indln),
				*(game->hash_array[indpf].keylen)))
			return (cub_dispacher_fnct(indpf, parser, game));
	parser->eof = -1;
	return (FALSE);
}

t_bool	cub_parser(const char *file, t_game *game)
{
	t_parser	parser;
	t_bool		loop;

	if (!cub_setter_parser(file, &parser))
		return (FALSE);
	game->screen->mlx = mlx_init();
	parser.eof = 1;
	loop = TRUE;
	while (parser.eof == 1 && loop == TRUE)
	{
		if (!cub_get_setting_line(&parser, file))
			return (FALSE);
		loop = cub_dispatcher(file, &parser, game);
	}
	if (parser.eof = -1)
		return (cub_free_fd("unknown element line", parser.line, &parser));		
	return (cub_parse_map(&parser, game));
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
