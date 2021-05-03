/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_level.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:24:25 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/01 14:46:20 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

/*
** AID
*/

t_bool	cub_free_player(t_player **player)
{
	if (!(*player))
		return (FALSE);
	ft_free_t_bool(&((*player)->is));
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

t_bool	cub_free_level(void *mlx, t_level **level)
{
	int	indmap;
	if (!(*level))
		return (FALSE);
	mlx_destroy_image(mlx ,(*level)->no);
	mlx_destroy_image(mlx, (*level)->so);
	mlx_destroy_image(mlx, (*level)->we);
	mlx_destroy_image(mlx, (*level)->ea);
	mlx_destroy_image(mlx, (*level)->sp);
	cub_free_horizon(&((*level)->floor));
	cub_free_horizon(&((*level)->ceiling));
	cub_free_player(&((*level)->player));
	cub_free_area(&((*level)->area));
	free(*level);
	*level = 0;
	return (TRUE);
}
