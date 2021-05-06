/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_fonctions_hash_array.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:03:42 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/06 18:32:16 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_set_key_hash_array(t_hash_array *array)
{
	ft_strlcpy(array[0].key, "NO", *(array[0].keylen) + 1);
	ft_strlcpy(array[1].key, "EA", *(array[1].keylen) + 1);
	ft_strlcpy(array[2].key, "SO", *(array[2].keylen) + 1);
	ft_strlcpy(array[3].key, "WE", *(array[3].keylen) + 1);
	ft_strlcpy(array[4].key, "R", *(array[4].keylen) + 1);
	ft_strlcpy(array[5].key, "S", *(array[5].keylen) + 1);
	ft_strlcpy(array[6].key, "C", *(array[6].keylen) + 1);
	ft_strlcpy(array[7].key, "F", *(array[7].keylen) + 1);
}

void	cub_set_keylen_hash_array(t_hash_array *array)
{
	*(array[0].keylen) = 2;
	*(array[1].keylen) = 2;
	*(array[2].keylen) = 2;
	*(array[3].keylen) = 2;
	*(array[4].keylen) = 1;
	*(array[5].keylen) = 1;
	*(array[6].keylen) = 1;
	*(array[7].keylen) = 1;
}

void	cub_set_pt_fonctions_hash_array(t_hash_array *array)
{
	*(array[0].pt_fonction) = &cub_parse_texture_north;
	*(array[1].pt_fonction) = &cub_parse_texture_east;
	*(array[2].pt_fonction) = &cub_parse_texture_south;
	*(array[3].pt_fonction) = &cub_parse_texture_west;
	*(array[4].pt_fonction) = &cub_parse_resolution;
	*(array[5].pt_fonction) = &cub_parse_texture_sprite;
	*(array[6].pt_fonction) = &cub_set_horizon;
	*(array[7].pt_fonction) = &cub_set_horizon;
}
