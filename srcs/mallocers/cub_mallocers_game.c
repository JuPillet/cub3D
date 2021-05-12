/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mallocers_game.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:53:33 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 22:29:14 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_malloc_functions_pointer(t_pt_fnct **pt_function)
{
	*pt_function = (t_pt_fnct *)malloc(sizeof(t_pt_fnct));
	if (!(*pt_function))
		return (ft_error("insufficient memory to initiate cub3D", 0));
	return (TRUE);
}

void	cub_zero_init_hash_array(t_hash_array **hash_array)
{
	int indha;

	indha = -1;
	while (++indha < 8)
	{
		(*hash_array)[indha].keylen = 0;
		(*hash_array)[indha].key = 0;
		(*hash_array)[indha].pt_fonction = 0;
	}
}

t_bool	cub_malloc_fonctions_hash_array(t_hash_array **hash_array)
{
	int	indha;
	int	keylen;

	*hash_array = (t_hash_array *)malloc(8 * sizeof(t_hash_array));
	if (!(*hash_array))
		return (FALSE);
	cub_zero_init_hash_array(hash_array);
	indha = -1;
	while (++indha < 8)
	{
		if (indha < 4)
			keylen = 2;
		else
			keylen = 1;
		if (!ft_malloc_char(1, &((*hash_array)[indha].keylen))
			|| !ft_malloc_char(keylen + 1, &((*hash_array)[indha].key))
			|| !cub_malloc_functions_pointer(
				&((*hash_array)[indha].pt_fonction)))
			return (ft_error("insufficient memory to initiate cub3D", 0));
	}
	cub_set_keylen_hash_array(*hash_array);
	cub_set_key_hash_array(*hash_array);
	cub_set_pt_fonctions_hash_array(*hash_array);
	return (TRUE);
}

t_bool	cub_malloc_game(t_game **game)
{
	(*game) = (t_game *)malloc(sizeof(t_game));
	if (*game)
	{
		(*game)->hash_array = 0;
		(*game)->mlx = 0;
		(*game)->screen = 0;
		(*game)->level = 0;
		(*game)->save = 0;
		if (cub_malloc_fonctions_hash_array(&((*game)->hash_array))
			&& cub_set_mlx(&((*game)->mlx))
			&& cub_malloc_screen(&((*game)->screen))
			&& cub_malloc_level(&((*game)->level))
			&& ft_malloc_t_bool(1, &((*game)->save)))
			return (TRUE);
	}
	return (ft_error("insufficient memory to initiate cub3D", 0));
}
