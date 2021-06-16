/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:50:08 by jpillet           #+#    #+#             */
/*   Updated: 2021/06/16 19:07:55 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

void	cub_sort_sprite(t_level *level)
{
	int			crnt_sprite;
	int			next_sprites;
	t_sprite	sprite;

	crnt_sprite = -1;
	while (++(crnt_sprite) < (level->area.nb_sprite - 1))
	{
		next_sprites = crnt_sprite;
		while (++(next_sprites) < level->area.nb_sprite)
		{
			if (level->area.sprite[crnt_sprite].distance
				< level->area.sprite[next_sprites].distance)
			{
				sprite = level->area.sprite[crnt_sprite];
				level->area.sprite[crnt_sprite] = level->area.sprite[
					next_sprites];
				level->area.sprite[next_sprites] = sprite;
			}
		}
	}
}

void	cub_set_distance_sprite(t_level *level)
{
	double		dif_y;
	double		dif_x;
	int			sprite;

	sprite = -1;
	while (++(sprite) < level->area.nb_sprite)
	{
		dif_y = level->area.sprite[sprite].pos_y - level->player.pos_y;
		dif_x = level->area.sprite[sprite].pos_x - level->player.pos_x;
		level->area.sprite[sprite].distance = sqrt((dif_y * dif_y)
				+ (dif_x * dif_x));
		level->area.sprite[sprite].visible = FALSE;
	}
	cub_sort_sprite(level);
}

t_bool	cub_set_parser(const char *file, t_parser *parser)
{
	parser->fd = open(file, O_RDONLY);
	parser->line = 0;
	if (parser->fd != -1)
		return (TRUE);
	return (ft_error("cub3D failed to open", file));
}

t_bool	cub_set_int(char *line, int *indln, int *value)
{
	while (line[*indln] == ' ' || line[*indln] == '\t')
		(*indln)++;
	if (!ft_isdigit(line[*indln])
		&& !(ft_issigned(line[*indln]) && ft_isdigit(line[(*indln) + 1])))
		return (FALSE);
	*value = ft_atoi((line + (*indln)));
	if (ft_issigned(line[*indln]))
		(*indln)++;
	while (ft_isdigit(line[*indln]))
		(*indln)++;
	return (TRUE);
}

t_bool	cub_set_double(char *line, int *indln, double *value)
{
	while (line[*indln] != ' ' || line[*indln] == '\t')
		(*indln)++;
	if (!ft_isdigit(line[*indln])
		&& (!ft_issigned(line[*indln]) || !ft_isdigit(line[(*indln) + 1])))
		return (FALSE);
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
