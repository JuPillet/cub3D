/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:10:31 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/22 10:31:15 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int		cub_set_argb(int a, int r, int g, int b)
{
	return(a << 24 | r << 16 | g << 8 | b);
}

int		cub_set_opposite(int argb)
{
	int a;
	int r;
	int g;
	int b;

	a = get_a(argb);
	r = get_r(argb);
	g = get_g(argb);
	b = get_b(argb);
	r = (0xFF << 16) - r;
	g = (0xFF << 8) - g;
	b = 0xFF - b;
	return (a | r | g | b);
}

int		cub_set_shade(double distance, int color)
{
	int a;
	int r;
	int g;
	int b;

	a = get_a(color) >> 24;
	r = get_r(color) >> 16;
	g = get_g(color) >> 8;
	b = get_b(color);
	r = r - (r * distance);
	g = g - (g * distance);
	b = b - (b * distance);
	return (cub_set_argb(a, r, g, b));
}

void	cub_set_my_mlx_pixel(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * (*data->line_length)
		+ x * ((*data->bits_per_pixel) / 8));
	*(unsigned int*)dst = color;
}

t_bool	cub_set_horizon(char *line, int *indln, t_horizon *horizon)
{
	if (*(horizon->is))
	{
		if (line[*indln] == 'F')
			return (ft_error("the setting file has two or more declared \
floor color , you must need only one", 0));
			else
		return (ft_error("the setting file has two or more declared \
ceiling color , you must need only one", 0));	
	}
	if (!cub_parse_color(line, indln, horizon->color))
	{
		if (line[*indln] == 'F')
			return (ft_error("the setting file has a invalid floor color", line));
		else
			return (ft_error("the setting file has a invalid ceiling color", line));
	}
	*(horizon->is) = TRUE;
	return (TRUE);
}
