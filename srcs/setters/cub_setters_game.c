/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setters_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:35:06 by jpillet           #+#    #+#             */
/*   Updated: 2021/05/05 15:54:15 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "cub3d.h"

t_bool	cub_set_resolution(char *line, t_screen *screen)
{
	int	*width;
	int *height;
	
	if (*(screen->resolution->width) < 1 || *(screen->resolution->height) < 1)
		return (ft_error("resolution format to small, minimum format :\n\
- width : 1\n- height 1", line));
	mlx_get_screen_size(screen->mlx, width, height);
	if (*(screen->resolution->width) > *width)
		*(screen->resolution->width) = *width;
	if (*(screen->resolution->height) > *height)
		*(screen->resolution->height) = *height;
	*(screen->resolution->is) = TRUE;
	return (TRUE);
}

void	cub_set_map_column(char *line, char *linemap)
{
	int	indln;
	int	column;
	int	tabulation;

	indln = 0;
	column = 0;
	while (linemap[++indln])
	{
		tabulation = 4 - (column % 4);
		if (line[indln] == '\t')
			while (tabulation--)
				linemap[column++] = ' ';
		else
			linemap[column++] = line[indln];
	}
	linemap[column] = '\0';
}