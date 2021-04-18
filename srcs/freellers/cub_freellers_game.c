/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_freellers_game.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:53:33 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/18 00:20:17 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	mini_free_functions_pointer(t_pt_fnct **pt_function)
{
	if (!(*pt_function))
		return (FALSE);
	free(*pt_function);
	*pt_function = 0;
	return (TRUE);
}

t_bool	mini_free_fonctions_hash_array(t_hash_array **hash_array)
{
	int indha;

	if (!(*hash_array))
		return (FALSE);
	indha = 0;
	while (indha < 8)
	{
		ft_free_char(&((*hash_array)[indha].keylen));
		ft_free_char(&((*hash_array)[indha].key));
		mini_free_functions_pointer(
			&((*hash_array)[indha].pt_fonction));
		indha++;
	}
	free(*hash_array);
	*hash_array = 0;
	return (TRUE);
}

t_bool	mini_free_game(t_game **game)
{
	if (!(*game))
		return (FALSE);
	mini_free_fonctions_hash_array(&((*game)->hash_array));
	mini_free_screen(&((*game)->screen));
	mini_free_level(&((*game)->level));
	free(*game);
	*game = 0;
	return (TRUE);
}
