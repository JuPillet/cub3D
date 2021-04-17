/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_fonctions_hash_array.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:03:42 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/17 18:11:46 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_set_key_hash_array(t_hash_array *array)
{
	ft_strlcpy(array[0].key, "NO", *(array[1].keylen) + 1);
	ft_strlcpy(array[1].key, "SO", *(array[4].keylen) + 1);
	ft_strlcpy(array[2].key, "WE", *(array[4].keylen) + 1);
	ft_strlcpy(array[3].key, "EA", *(array[2].keylen) + 1);
	ft_strlcpy(array[4].key, "R", *(array[0].keylen) + 1);
	ft_strlcpy(array[5].key, "S", *(array[0].keylen) + 1);
	ft_strlcpy(array[6].key, "F", *(array[3].keylen) + 1);
	ft_strlcpy(array[7].key, "C", *(array[5].keylen) + 1);
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
	*(array[0].pt_fonction) = &cub_parse_resolution;
	*(array[1].pt_fonction) = &cub_parse_north;
	*(array[2].pt_fonction) = &cub_parse_south;
	*(array[3].pt_fonction) = &cub_parse_west;
	*(array[4].pt_fonction) = &cub_parse_east;
	*(array[5].pt_fonction) = &cub_parse_sprite;
	*(array[6].pt_fonction) = &cub_parse_flour;
	*(array[7].pt_fonction) = &cub_parse_ceiling;
}
