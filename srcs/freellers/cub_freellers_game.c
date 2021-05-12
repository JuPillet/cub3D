/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:53:33 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 23:58:42 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_parser(char *msg, const char *msg2, t_parser *parser)
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
	return (FALSE);
}


t_bool	cub_free_functions_pointer(t_pt_fnct **pt_function)
{
	if (!(*pt_function))
		return (FALSE);
	free(*pt_function);
	*pt_function = 0;
	return (TRUE);
}

t_bool	cub_free_fonctions_hash_array(t_hash_array **hash_array)
{
	int indha;

	if (!(*hash_array))
		return (FALSE);
	indha = 0;
	while (indha < 8)
	{
		ft_free_char(&((*hash_array)[indha].keylen));
		ft_free_char(&((*hash_array)[indha].key));
		cub_free_functions_pointer(
			&((*hash_array)[indha].pt_fonction));
		indha++;
	}
	free(*hash_array);
	*hash_array = 0;
	return (TRUE);
}

t_bool	cub_free_game(t_game **game)
{
	if (!(*game))
		return (FALSE);
	cub_free_fonctions_hash_array(&((*game)->hash_array));
	cub_free_level((*game)->mlx, &((*game)->level));
	cub_free_screen((*game)->mlx, &((*game)->screen));
	ft_free_t_bool(&((*game)->save));
	if((*game)->mlx)
		mlx_destroy_display((*game)->mlx);
	free(*game);
	*game = 0;
	exit(0);
	return (TRUE);
}
