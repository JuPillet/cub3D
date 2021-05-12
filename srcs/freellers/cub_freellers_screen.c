/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_freellers_screen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:02:00 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 15:45:35 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_free_pic_screen(void *mlx, t_img_data **pic_screen)
{
	if (!(*pic_screen))
		return (FALSE);
	if ((*pic_screen)->img)
	{
		mlx_destroy_image(mlx, (*pic_screen)->img);
		(*pic_screen)->img = 0;
	}
	(*pic_screen)->addr = 0;
	(*pic_screen)->bits_per_pixel = 0;
	(*pic_screen)->line_length = 0;
	(*pic_screen)->endian = 0;
	free(*pic_screen);
	return (TRUE);
}

t_bool	cub_free_resolution(t_resolution **resolution)
{
	if (!(*resolution))
		return (FALSE);
	ft_free_t_bool(&((*resolution)->is));
	ft_free_int(&((*resolution)->width));
	ft_free_int(&((*resolution)->height));
	ft_free_int(&((*resolution)->pixel_x));
	ft_free_int(&((*resolution)->pixel_y));
	ft_free_double(&((*resolution)->fov));
	free(*resolution);
	*resolution = 0;
	return (TRUE);
}

t_bool	cub_free_screen(void *mlx, t_screen **screen)
{
	if (!(*screen))
		return (FALSE);
	cub_free_resolution(&((*screen)->resolution));
	cub_free_pic_screen(mlx, &((*screen)->pic_screen));
	if ((*screen)->mlx_screen)
		mlx_destroy_window(mlx, (*screen)->mlx_screen);
	free(*screen);
	*screen = 0;
	return(TRUE);
}
