/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:47:56 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/21 23:29:53 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_check_parser(int eof, t_bool check, t_game *game)
{
	t_resolution *resolution;
	t_texture	*no;
	t_texture	*so;
	t_texture	*we;
	t_texture	*ea;
	t_texture	*sp;
	t_horizon	*flour;
	t_horizon	*ceiling;
	t_player	*player;
	
	resolution = game->screen->resolution;
	no = game->level->no;
	so = game->level->so;
	we = game->level->we;
	ea = game->level->ea;
	flour = game->level->flour;
	ceiling = game->level->ceiling;
	player = game->level->player;
	if (eof == 1 && check == TRUE && (!(*(resolution->is)) || !(*(no->is))
		|| !(*(so->is)) || !(*(we->is)) || !(*(ea->is))))
		return(FALSE);
	return (TRUE);
}

t_bool	cub_dispatcher(const char *file, char *line, t_game *game)
{
	int				indln;
	int				indpf;
	t_pt_fnct		fnct;

	indln = 0;
	while (line[indln] == ' ' || line[indln] == '\t')
		indln++;
	if (!(line[indln]))
		return (TRUE);
	indpf = -1;
	while (++indpf < 13)
	{
		if (!ft_strncmp(game->hash_array[indpf].key,
			(line + indln), *(game->hash_array[indpf].keylen)))
		{
			fnct = *(game->hash_array[indpf].pt_fonction);
			indln = *(game->hash_array[indpf].keylen);
			return(fnct(line, &indln, game));
		}
	}
	return (ft_error("corrupted file or unknown element line", file));
}

t_bool	cub_parser(const char *file, t_game *game)
{
	t_parser	parser;
	t_bool		check;
	parser.fd = open(file, O_RDONLY);
	parser.fd_map = open(file, O_RDONLY);
	if (parser.fd > 2 && parser.fd_map > 2 && parser.fd_map != parser.fd)
	{
		game->screen->mlx = mlx_init();
		parser.eof = 1;
		check = TRUE;
		while(cub_check_parser(parser.eof, check, game))
		{
			parser.eof = get_next_line(parser.fd, &(parser.line));
			check = ft_gnl_status(parser.eof, parser.line, parser.fd, file);
			if (check)
				check = cub_dispatcher(file, parser.line, game);
			if (parser.line > 0)
				free(parser.line);
			parser.line = 0;
		}
	}
	else
		return(ft_error("the program failed to open", file));
	return (cub_parse_map(parser, game));
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