/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:47:56 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/18 01:04:32 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	mini_dispatcher(const char *file, char *line, t_pov *pov)
{
	int				indln;
	int				indpf;
	t_pt_fnct		fnct;

	indln = 0;
	while (ft_isspace(line[indln]))
		indln++;
	if (!(line[indln]))
		return (TRUE);
	indpf = -1;
	while (++indpf < 13)
	{
		if (!ft_strncmp(pov->hash_array[indpf].key,
			(line + indln), *(pov->hash_array[indpf].keylen)))
		{
			fnct = *(pov->hash_array[indpf].pt_fonction);
			indln = *(pov->hash_array[indpf].keylen);
			return(fnct(line, &indln, pov));
		}
	}
	return (ft_error("corrupted file or unknown element line", file));
}

t_bool	mini_parser(const char *file, t_pov *pov)
{
	t_parser	parser;
	t_bool		check;
	parser.fd = open(file, O_RDONLY);
	if (parser.fd > 2)
	{
		*(pov->screen->resolution->is) = FALSE;
		*(pov->scene->a_light->is) = FALSE;
		parser.eof = 1;
		check = TRUE;
		while(parser.eof == 1 && check == TRUE)
		{
			parser.eof = get_next_line(parser.fd, &(parser.line));
			check = ft_gnl_status(parser.eof, parser.line, parser.fd, file);
			if (check)
				check = mini_dispatcher(file, parser.line, pov);
			if (parser.line > 0)
				free(parser.line);
			parser.line = 0;
		}
	}
	else
		return(ft_error("the program failed to open", file));
	close(parser.fd);
	return (TRUE);
}

t_bool	mini_norm_file(const char *file, t_pov *pov)
{
	int	indfl;

	indfl = 0;
	while (file[indfl])
		indfl++;
	if (indfl > 2 && (file[--indfl] == 't' || file[indfl] == 'T') && 
		(file[--indfl] == 'r' || file[indfl] == 'R') && 
			file[--indfl] == '.')
		return (mini_parser(file, pov));
	return (ft_error("wrong extension name", file));
}