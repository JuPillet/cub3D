/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_adders_informs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:14:36 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/15 18:07:27 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include "miniRT.h"

t_bool	mini_adder_camera(char *line, int *indln, t_pov *pov)
{
	t_camera	*new_camera;

	if (!mini_malloc_camera(&new_camera))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!(pov->scene->camera))
	{
		new_camera->p_camera = new_camera;
		new_camera->n_camera = new_camera;
		pov->scene->camera = new_camera;
	}
	else
	{
		new_camera->p_camera = pov->scene->camera->p_camera;
		new_camera->n_camera = pov->scene->camera;
		new_camera->p_camera->n_camera = new_camera;
		pov->scene->camera->p_camera = new_camera;
	}
    if (mini_parse_camera(line, indln, new_camera))
		return (TRUE);
	return (FALSE);
}

t_bool	mini_adder_light(char *line, int *indln, t_pov *pov)
{
	t_light *new_light;

	if (!mini_malloc_light(&new_light))
		return (ft_error("insufficient memory for add new scene element", 0));
	if (!pov->scene->light)
	{
		pov->scene->light = new_light;
		new_light->p_light = new_light;
		new_light->n_light = new_light;
	}
	else
	{
		new_light->p_light = pov->scene->light->p_light;
		new_light->n_light = pov->scene->light;
		new_light->p_light->n_light = new_light;
		pov->scene->light->p_light = new_light;
	}
    if (mini_parse_light(line, indln, new_light))
		return (TRUE);
	return (FALSE);
}
