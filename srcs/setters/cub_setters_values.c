/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:50:08 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/18 14:18:21 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool		mini_set_int(char *line, int *indln, int *value)
{
	while (ft_isspace(line[*indln]))
		(*indln)++;
	if (!ft_isdigit(line[*indln])
		&& !(ft_issigned(line[*indln]) && ft_isdigit(line[(*indln) + 1])))
		return(FALSE);
	*value = ft_atoi((line + (*indln)));
	if (ft_issigned(line[*indln]))
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	return (TRUE);
}

t_bool	mini_set_double(char *line, int *indln, double *value)
{
	while (ft_isspace(line[*indln]))
		(*indln)++;
	if (!ft_isdigit(line[*indln])
		&& !(ft_issigned(line[*indln]) && ft_isdigit(line[(*indln) + 1])))
		return(FALSE);
	*value = ft_atof((line + (*indln)));
	if (ft_issigned(line[*indln]))
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	if (line[*indln] == '.')
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	return (TRUE);
}

void	mini_set_mlx(t_pov *pov)
{
	pov->screen->mlx = mlx_init();
	pov->screen->mlx_screen = mlx_new_window(pov->screen->mlx,
	*(pov->screen->resolution->x), *(pov->screen->resolution->y), "LOUIS XIV");
	pov->screen->pic_screen->img = mlx_new_image(pov->screen->mlx,
	*(pov->screen->resolution->x), *(pov->screen->resolution->y));
	pov->screen->pic_screen->addr = mlx_get_data_addr(
			pov->screen->pic_screen->img,
			pov->screen->pic_screen->bits_per_pixel,
			pov->screen->pic_screen->line_length,
			pov->screen->pic_screen->endian);
}