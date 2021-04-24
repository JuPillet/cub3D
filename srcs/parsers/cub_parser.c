/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:47:56 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/24 20:40:37 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

static t_bool	cub_dispacher_fnct(t_parser *parser, int indpf, t_game *game)
{
	t_pt_fnct	fnct;

	fnct = *(game->hash_array[indpf].pt_fonction);
	parser->indln = *(game->hash_array[indpf].keylen);
	return (fnct(parser->line, &(parser->indln), game));
}

static t_bool	cub_dispatcher(const char *file, t_parser *parser, t_game *game)
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
	if (cub_check_map(line, indln))
		return (FALSE);
	while (++indpf < 13)
		if (!ft_strncmp(game->hash_array[indpf].key,
				(parser->line + parser->indln),
				*(game->hash_array[indpf].keylen)))
			return (cub_dispacher_fnct(parser, indpf, game));
	return (ft_error("corrupted file or unknown element line", file));
}

static void	cub_parser_init(const char *file, t_parser *parser)
{
	parser->fd = open(file, O_RDONLY);
	parser->fd_map = open(file, O_RDONLY);
	parser->checked_map = FALSE;
}

t_bool	cub_parser(const char *file, t_game *game)
{
	t_parser	parser;
	t_bool		loop;

	cub_parser_init(file, &parser);
	if (parser.fd > 2 && parser.fd_map > parser.fd
		&& parser.fd_map != parser.fd)
	{
		game->screen->mlx = mlx_init();
		parser.eof = 1;
		loop = TRUE;
		while (parser.eof == 1 && loop == TRUE)
		{
			if (parser.line > 0)
				free(parser.line);
			parser.line = 0;
			parser.eof = get_next_line(parser.fd, &(parser.line));
			parser.eof = get_next_line(parser.fd_map, &(parser.line_map));
			loop = ft_gnl_status(parser.eof, parser.line, parser.fd, file);
			if (loop)
				loop = cub_dispatcher(file, parser.line, game);
		}
	}
	else
		return (ft_error("the program failed to open", file));
	return (cub_parse_map_line(&parser, game));
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
