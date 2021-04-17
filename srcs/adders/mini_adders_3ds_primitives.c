/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_adders_3ds_primitives.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:26:19 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/16 18:33:12 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "miniRT.h"

t_bool	mini_adder_sphere(char *line, int *indln, t_pov *pov)
{
	t_sphere	*new_sphere;

	if (!mini_malloc_sphere(&new_sphere))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->sphere)
	{
		pov->scene->sphere = new_sphere;
		new_sphere->p_sphere = new_sphere;
		new_sphere->n_sphere = new_sphere;
	}
	else
	{
		new_sphere->p_sphere = pov->scene->sphere->p_sphere;
		new_sphere->n_sphere = pov->scene->sphere;
		new_sphere->p_sphere->n_sphere = new_sphere;
		pov->scene->sphere->p_sphere = new_sphere;
	}
	if (mini_parse_sphere(line, indln, new_sphere))
		return (TRUE);
	return (FALSE);
}

t_bool	mini_adder_cylender(char *line, int *indln, t_pov *pov)
{
	t_cylender	*new_cylender;
	
	if (!mini_malloc_cylender(&new_cylender))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->cylender)
	{
		pov->scene->cylender = new_cylender;
		new_cylender->p_cylender = new_cylender;
		new_cylender->n_cylender = new_cylender;
	}
	else
	{
		new_cylender->p_cylender = pov->scene->cylender->p_cylender;
		new_cylender->n_cylender = pov->scene->cylender;
		new_cylender->p_cylender->n_cylender = new_cylender;
		pov->scene->cylender->p_cylender = new_cylender;
	}
	if (mini_parse_cylender(line, indln, new_cylender))
		return (TRUE);
	return (FALSE);
}

t_bool	mini_adder_cube(char *line, int *indln, t_pov *pov)
{
	t_cube	*new_cube;

	if (!mini_malloc_cube(&new_cube))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->cube)
	{
		pov->scene->cube = new_cube;
		new_cube->p_cube = new_cube;
		new_cube->n_cube = new_cube;
	}
	else
	{
		new_cube->p_cube = pov->scene->cube->p_cube;
		new_cube->n_cube = pov->scene->cube;
		new_cube->p_cube->n_cube = new_cube;
		pov->scene->cube->p_cube = new_cube;
	}
	if (mini_parse_cube(line, indln, new_cube))
		return (TRUE);
	return (FALSE);
}

t_bool	mini_adder_pyramid(char *line, int *indln, t_pov *pov)
{
	t_pyramid	*new_pyramid;

	if (!mini_malloc_pyramid(&new_pyramid))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->pyramid)
	{
		pov->scene->pyramid = new_pyramid;
		new_pyramid->p_pyramid = new_pyramid;
		new_pyramid->n_pyramid = new_pyramid;
	}
	else
	{
		new_pyramid->p_pyramid = pov->scene->pyramid->p_pyramid;
		new_pyramid->n_pyramid = pov->scene->pyramid;
		new_pyramid->p_pyramid->n_pyramid = new_pyramid;
		pov->scene->pyramid->p_pyramid = new_pyramid;
	}
	if (mini_parse_pyramid(line, indln, new_pyramid))
		return (TRUE);
	return (FALSE);
}

t_bool	mini_adder_cone(char *line, int *indln, t_pov *pov)
{
	t_cone	*new_cone;

	if (!mini_malloc_cone(&new_cone))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->cone)
	{
		pov->scene->cone = new_cone;
		new_cone->p_cone = new_cone;
		new_cone->n_cone = new_cone;
	}
	else
	{
		new_cone->p_cone = pov->scene->cone->p_cone;
		new_cone->n_cone = pov->scene->cone;
		new_cone->p_cone->n_cone = new_cone;
		pov->scene->cone->p_cone = new_cone;
	}
	if (mini_parse_cone(line, indln, new_cone))
		return (TRUE);
	return (FALSE);
}
