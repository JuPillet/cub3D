/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:48:57 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/21 10:46:49 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_map(char ***map)
{
	int	indmap;

	if (!(*map))
		return (FALSE);
	indmap = 0;
	while ((*map)[indmap] != 0)
		ft_free_char(&((*map)[indmap]));
	free(*map);
	*map = 0;
}