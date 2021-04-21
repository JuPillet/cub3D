/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:55:09 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/21 10:43:23 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

double	normalize_cube(t_coord coord)
{
	return(scalar_product_vector(coord, coord));
}

void	normalize(t_coord *coord)
{
	double	norm;
	
	norm = sqrt(normalize_cube(*coord));
	*(coord->x_coord) /= norm;
	*(coord->y_coord) /= norm;
	*(coord->z_coord) /= norm;
}

t_coord	get_normalized(t_coord coord)
{
	normalize(&coord);
	return (coord);
}

void	make_ray_direction(t_pov *pov)
{
	if (pov->screen->x_start < pov->screen.x_right)
		pov->ray.direction.x_coord = (pov->screen.x_start - pov->screen.x_left);
	else
		pov->ray.direction.x_coord = (pov->screen.x_start - pov->screen.x_right);
	if (pov->screen.y_start < pov->screen.y_down)
		pov->ray.direction.y_coord = (pov->screen.y_start - pov->screen.y_up);
	else
		pov->ray.direction.y_coord = (pov->screen.y_start - pov->screen.y_down);
	pov->ray.direction.z_coord = -(pov->screen.x_screen / pov->screen.z_center);
	normalize(&pov->ray.direction);
}

t_bool	intersection(t_pov *pov, t_sphere sphere)
{
	t_coord	intersection_vector;
	double	a;
	double	b;
	double	c;
	double	discreminant;
	double	test_sub_discreminant;
	double	test_add_discreminant;
	
	intersection_vector = vector_sub(pov->ray.origin, sphere.origin);
	a = 1;
	b = 2 * scalar_product_vector(pov->ray.direction, intersection_vector);
	c = normalize_cube(intersection_vector) - pow(sphere.radius, 2);
	discreminant = pow(b, 2) - (4 * a * c);
	test_add_discreminant = (-b + sqrt(discreminant) / (2 * a));
	if (test_add_discreminant < 0)
		return (FALSE);  
	test_sub_discreminant = (-b - sqrt(discreminant) / (2 * a));
	if (test_sub_discreminant > 0)
		pov->ray.intersection.value = test_sub_discreminant;
	else
		pov->ray.intersection.value = test_add_discreminant;
	pov->ray.intersection.position = vector_add(pov->ray.origin, 
		vector_mul(pov->ray.direction, pov->ray.intersection.value));
	pov->ray.intersection.normal = get_normalized(
		vector_sub(pov->ray.intersection.position, sphere.origin));
	return (TRUE);
}

