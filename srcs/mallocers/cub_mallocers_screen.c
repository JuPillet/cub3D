/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mallocers_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:19:08 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 00:20:43 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_malloc_resolution(t_resolution **resolution)
{
	*resolution = (t_resolution *)malloc(sizeof(t_resolution));
	if (*resolution)
	{
		(*resolution)->is = 0;
		(*resolution)->width = 0;
		(*resolution)->height = 0;
		(*resolution)->pixel_x = 0;
		(*resolution)->pixel_y = 0;
		(*resolution)->fov = 0;
		if (ft_malloc_t_bool(1, &((*resolution)->is))
			&& ft_malloc_int(1, &((*resolution)->width))
			&& ft_malloc_int(1, &((*resolution)->height))
			&& ft_malloc_int(1, &((*resolution)->pixel_x))
			&& ft_malloc_int(1, &((*resolution)->pixel_y))
			&& ft_malloc_double(1, &((*resolution)->fov)))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	cub_malloc_screen(t_screen	**screen)
{
	*screen = (t_screen *)malloc(sizeof(t_screen));
	if (*screen)
	{
		(*screen)->resolution = 0;
		(*screen)->mlx = 0;
		(*screen)->mlx_screen = 0;
		(*screen)->pic_screen = 0;
		if (cub_malloc_resolution(&((*screen)->resolution)))
			return (TRUE);
	}
	return (FALSE);
}
