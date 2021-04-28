/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mallocers_level.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:24:25 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/27 20:14:45 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_malloc_player(t_player **player)
{
	*player = (t_player *)malloc(sizeof(t_player));
	if (*player)
	{
		(*player)->position_x = 0;
		(*player)->position_y = 0;
		(*player)->orientation = 0;
		if (ft_malloc_double(1, &((*player)->position_x))
			&& ft_malloc_double(1, &((*player)->position_y))
			&& ft_malloc_double(1, &((*player)->orientation)))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	cub_malloc_color(t_color **color)
{
	*color = (t_color *)malloc(sizeof(t_color));
	if (*color)
	{
		(*color)->a = 0;
		(*color)->r = 0;
		(*color)->g = 0;
		(*color)->b = 0;
		(*color)->argb = 0;
		if (ft_malloc_int(1, &((*color)->a))
			&& ft_malloc_int(1, &((*color)->r))
			&& ft_malloc_int(1, &((*color)->g))
			&& ft_malloc_int(1, &((*color)->b))
			&& ft_malloc_int(1, &((*color)->argb)))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	cub_malloc_horizon(t_horizon **horizon)
{
	*horizon = (t_color *)malloc(sizeof(t_color));
	if (*horizon)
	{
		(*horizon)->is = 0;
		(*horizon)->color = 0;
		if (ft_malloc_t_bool(1, &((*horizon)->is))
			&& cub_malloc_color(&((*horizon)->color)))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	cub_malloc_level(t_level **level)
{
	*level = (t_level *)malloc(sizeof(t_level));
	if (!(*level))
	{
		(*level)->no = 0;
		(*level)->so = 0;
		(*level)->we = 0;
		(*level)->ea = 0;
		(*level)->sp = 0;
		(*level)->floor = 0;
		(*level)->ceiling = 0;
		(*level)->player = 0;
		(*level)->area = 0;
		if (cub_malloc_texture(&((*level)->no))
			&& cub_malloc_horizon(&((*level)->floor))
			&& cub_malloc_horizon(&((*level)->ceiling))
			&& cub_malloc_player(&((*level)->player))
			&& cub_malloc_area(&((*level)->area)))
			return (TRUE);
	}
	return (FALSE);
}
