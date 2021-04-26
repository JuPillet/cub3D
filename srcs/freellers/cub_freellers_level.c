/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_level.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:24:25 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/26 23:13:38 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_player(t_player **player)
{
	if (!(*player))
		return (FALSE);
	ft_free_double(&((*player)->position_x));
	ft_free_double(&((*player)->position_y));
	ft_free_double(&((*player)->orientation));
	free(*player);
	*player = 0;
	return (TRUE);
}

t_bool	cub_free_color(t_color **color)
{
	
	if (!(*color))
		return (FALSE);
	ft_free_int(&((*color)->a));
	ft_free_int(&((*color)->r));
	ft_free_int(&((*color)->g));
	ft_free_int(&((*color)->b));
	ft_free_int(&((*color)->argb));
	free(*color);
	*color = 0;
	return (TRUE);
}

t_bool	cub_free_texture(t_texture **texture)
{
	
	if (!(*texture))
		return (FALSE);
	ft_free_t_bool(&((*texture)->is));
	ft_free_char(&((*texture)->path));
	free(*texture);
	*texture = 0;
	return (TRUE);
}

t_bool	cub_free_horizon(t_horizon **horizon)
{
	if (!(*horizon))
		return (FALSE);
	ft_free_t_bool(&((*horizon)->is));
	cub_free_color(&((*horizon)->color));
	free(*horizon);
	*horizon = 0;
	return (TRUE);
}

t_bool	cub_free_level(t_level **level)
{
	int	indmap;
	if (!(*level))
		return (FALSE);
	cub_free_texture(&((*level)->no));
	cub_free_texture(&((*level)->so));
	cub_free_texture(&((*level)->we));
	cub_free_texture(&((*level)->ea));
	cub_free_texture(&((*level)->sp));
	cub_free_horizon(&((*level)->floor));
	cub_free_horizon(&((*level)->ceiling));
	cub_free_player(&((*level)->player));
	cub_free_map(&((*level)->area));
	free(*level);
	*level = 0;
	return (TRUE);
}
