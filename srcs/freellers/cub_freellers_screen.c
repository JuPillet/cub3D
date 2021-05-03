/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:02:00 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/03 17:19:10 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_resolution(t_resolution **resolution)
{
	if (!(*resolution))
		return (FALSE);
	ft_malloc_t_bool(1, &((*resolution)->is));
	ft_malloc_int(1, &((*resolution)->width));
	ft_malloc_int(1, &((*resolution)->height));
	ft_malloc_int(1, &((*resolution)->pixel_x));
	ft_malloc_int(1, &((*resolution)->pixel_y));
	ft_malloc_double(1, &((*resolution)->fov));
	free(*resolution);
	*resolution = 0;
	return (TRUE);
}

t_bool	cub_free_screen(t_screen **screen)
{
	if (!(*screen))
		return (FALSE);
	cub_free_resolution(&((*screen)->resolution));
	mlx_destroy_image((*screen)->mlx, (*screen)->pic_screen->img);
	mlx_destroy_window((*screen)->mlx, (*screen)->mlx_screen);
	free(*screen);
	*screen = 0;
	return(TRUE);
}
