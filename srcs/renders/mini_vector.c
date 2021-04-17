/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:35:37 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/13 15:23:58 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "miniRT.h"

t_coord	vector_add(t_coord a, t_coord b)
{
	t_coord	vector;
	
	*(vector.x_coord) = *(a.x_coord) + *(b.x_coord);
	*(vector.y_coord) = *(a.y_coord) + *(b.y_coord);
	*(vector.z_coord) = *(a.z_coord) + *(b.z_coord);
	return (vector);
}

t_coord	vector_sub(t_coord a, t_coord b)
{
	t_coord	vector;
	
	*(vector.x_coord) = *(a.x_coord) - *(b.x_coord);
	*(vector.y_coord) = *(a.y_coord) - *(b.y_coord);
	*(vector.z_coord) = *(a.z_coord) - *(b.z_coord);
	return (vector);
}

t_coord	vector_mul(t_coord a, double b)
{
	t_coord	vector;
	
	*(vector.x_coord) = *(a.x_coord) * b;
	*(vector.y_coord) = *(a.y_coord) * b;
	*(vector.z_coord) = *(a.z_coord) * b;
	return (vector);
}

t_coord	vector_div(t_coord a, double b)
{
	t_coord	vector;
	
	*(vector.x_coord) = *(a.x_coord) / b;
	*(vector.y_coord) = *(a.y_coord) / b;
	*(vector.z_coord) = *(a.z_coord) / b;
	return (vector);
}

double	scalar_product_vector(t_coord a, t_coord b)
{
	t_coord	coord_cube;

	*(coord_cube.x_coord) = *(a.x_coord) * (*(b.x_coord));
	*(coord_cube.y_coord) = *(a.y_coord) * (*(b.y_coord));
	*(coord_cube.z_coord) = *(a.z_coord) * (*(b.z_coord));
	return (*(coord_cube.x_coord)
			+ *(coord_cube.y_coord)
			+ *(coord_cube.z_coord));
}
