/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_get_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:10:37 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/21 10:44:27 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

int		get_a(int argb)
{
	return (argb & (0xFF << 24));
}

int		get_r(int argb)
{
	return (argb & (0xFF << 16));
}

int		get_g(int argb)
{
	return (argb & (0xFF << 8));
}

int		get_b(int argb)
{
	return (argb & 0xFF);
}
