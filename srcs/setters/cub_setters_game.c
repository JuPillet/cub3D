/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:35:06 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/12 23:05:46 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_set_mlx(void **mlx)
{
	(*mlx) = mlx_init();
	if ((*mlx))
		return (TRUE);
	return (FALSE);
}

t_bool	cub_set_resolution(char *line, void *mlx, t_screen *screen)
{
	int	width;
	int height;

	if (*(screen->resolution->width) < 1 || *(screen->resolution->height) < 1)
		return (ft_error("resolution format to small, minimum format :\n\
- width : 1\n- height 1", line));
	mlx_get_screen_size(mlx, &width, &height);
	if (*(screen->resolution->width) > width)
		*(screen->resolution->width) = width;
	if (*(screen->resolution->height) > height)
		*(screen->resolution->height) = height;
	*(screen->resolution->is) = TRUE;
	return (TRUE);
}

void	cub_set_map_columns(char *line, char **line_map)
{
	int	indln;
	int	column;
	int	tabulation;

	indln = 0;
	column = 0;
	while (line[indln])
	{
		tabulation = 4 - (column % 4);
		if (line[indln] == '\t')
			while (tabulation--)
				(*line_map)[column++] = ' ';
		else
			(*line_map)[column++] = line[indln];
		indln++;
	}
	(*line_map)[column] = '\0';
}