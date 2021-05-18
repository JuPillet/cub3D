/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:10:31 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/17 23:01:28 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_set_map_color(char c, int *color)
{
	if (c == '1')
		*color = 0xFFFFFF;
	else if (c == '0')
		*color = 0xDDDDDD;
	else
		*color = 0xFBFBFB;
}

int	cub_set_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	cub_set_opposite(int argb)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = get_a(argb);
	r = get_r(argb);
	g = get_g(argb);
	b = get_b(argb);
	r = (0xFF << 16) - r;
	g = (0xFF << 8) - g;
	b = 0xFF - b;
	return (a | r | g | b);
}

int	cub_set_shade(double distance, int color)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = get_a(color) >> 24;
	r = get_r(color) >> 16;
	g = get_g(color) >> 8;
	b = get_b(color);
	r = r - (r * distance);
	g = g - (g * distance);
	b = b - (b * distance);
	return (cub_set_argb(a, r, g, b));
}

t_bool	cub_init_color(t_color *color)
{
	color->a = 0;
	color->r = 0;
	color->g = 0;
	color->b = 0;
	color->argb = 0;
	return (TRUE);
}
